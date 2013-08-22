#include <QtCore/QByteArray>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QUdpSocket>
#include "constant.h"
#include "data.h"
#include "host.h"
#include "udp_client.h"

UdpClient::UdpClient(QObject *parent) :
    QObject(parent),udp_socket(new QUdpSocket(this))
{
    udp_socket->bind(QHostAddress("127.0.0.1"),Host::port+1);
    connect(udp_socket,SIGNAL(readyRead()),this,SLOT(recv()));
}

QByteArray UdpClient::rduc(QUdpSocket *socket)
{
    QByteArray datagram;
    datagram.resize(socket->pendingDatagramSize());
    socket->readDatagram(datagram.data(),datagram.size());
    return qUncompress(datagram);
}

void UdpClient::recv()
{
    while(udp_socket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram = rduc(udp_socket);
        //qDebug()<<"qUncompress():"<<datagram.size();
        quint32 idx = *(quint32*)datagram.data();
        qCopy(datagram.data()+HEAD_SIZE,datagram.data()+datagram.size(),Data::src->data()+idx);
    }
}
