#include <QtCore/QCoreApplication>
#include <QtCore/QByteArray>
#include <QtCore/QDataStream>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include "constant.h"
#include "data.h"
#include "host.h"
#include "udp_server.h"

UdpServer::UdpServer(QObject *parent) :
    QThread(parent),dest(new QByteArray)
{
    dest->resize(Data::src->size());
}

void UdpServer::timerEvent(QTimerEvent *)
{
    static quint64 counter = 0;
    ++counter;
    if(counter % 50 == 0)
    {
        sendAll();
    }
    else
    {
        sendDiff();
    }
}

void UdpServer::run()
{
    /*
    startTimer(UDP_SLEEP_TIME_MS*2);
    exec();
    */
    for( ; ; )
    {
        timerEvent(NULL);
        msleep(UDP_SLEEP_TIME_MS);
        QCoreApplication::processEvents();
    }
}

void UdpServer::sendDiff()
{
    if(!Data::address_lst.empty())
    {
        QUdpSocket udp_socket;
        quint64 src_len = Data::src->size();
        for(quint64 i = 0 ; i < src_len ; i += DATASIZE_PER_PACKET)
        {
            quint64 packet_end = i + DATASIZE_PER_PACKET;
            for(quint64 j = i,p_end = src_len < packet_end ? src_len : packet_end ; j < p_end; ++j)
            {
                if(Data::src->data()[j] != dest->data()[j])
                {
                    QByteArray datagram;
                    QDataStream stream(&datagram,QIODevice::WriteOnly);
                    quint32 head = i;
                    stream.writeRawData((char*)&head,sizeof(quint32));
                    char *src_begin = Data::src->data()+i;
                    stream.writeRawData(src_begin,DATASIZE_PER_PACKET);
                    datagram = qCompress(datagram,COMPRESS_LEVEL);
                    for(QList<QHostAddress>::Iterator iter = Data::address_lst.begin() ;
                        iter != Data::address_lst.end() ; ++iter)
                    {
                        udp_socket.writeDatagram(datagram,*iter,Host::port+1);
                    }
                    qCopy(src_begin,src_begin+p_end-i,dest->data()+i);
                    break;
                }
            }
        }
    }
}

void UdpServer::sendAll()
{
    if(!Data::address_lst.empty())
    {
        QUdpSocket udp_socket;
        quint64 src_len = Data::src->size();
        for(quint64 i = 0 ; i < src_len ; i += DATASIZE_PER_PACKET)
        {
            quint64 packet_end = i + DATASIZE_PER_PACKET;
            QByteArray datagram;
            QDataStream stream(&datagram,QIODevice::WriteOnly);
            quint32 head = i;
            stream.writeRawData((char*)&head,sizeof(quint32));
            char *src_begin = Data::src->data()+i;
            stream.writeRawData(src_begin,DATASIZE_PER_PACKET);
            datagram = qCompress(datagram,COMPRESS_LEVEL);
            for(QList<QHostAddress>::Iterator iter = Data::address_lst.begin() ;
                iter != Data::address_lst.end() ; ++iter)
            {
                udp_socket.writeDatagram(datagram,*iter,Host::port+1);
            }
            qCopy(src_begin,src_begin+(packet_end > src_len ?
                                           src_len-i : DATASIZE_PER_PACKET),dest->data()+i);
        }
    }
}
