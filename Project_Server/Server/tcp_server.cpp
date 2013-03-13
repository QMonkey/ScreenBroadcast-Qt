#include <QtCore/QByteArray>
#include <QtCore/QDataStream>
#include <QtNetwork/QTcpSocket>
#include "constant.h"
#include "data.h"
#include "tcp_server.h"
#include <QDebug>

TcpServer::TcpServer(QObject *parent) :
    QTcpServer(parent)
{
}

void TcpServer::incomingConnection(int handle)
{
    QTcpSocket *socket = new QTcpSocket;
    socket->setSocketDescriptor(handle);
    if(!Data::address_lst.contains(socket->peerAddress()))
    {
        Data::address_lst.append(socket->peerAddress());
    }
    QByteArray head;
    QDataStream stream(&head,QIODevice::WriteOnly);
    stream.writeRawData((char*)&Data::width,sizeof(quint16));
    stream.writeRawData((char*)&Data::height,sizeof(quint16));
    quint32 src_size = Data::src->size();
    stream.writeRawData((char*)&src_size,sizeof(quint32));
    socket->write(head);
    socket->waitForBytesWritten(-1);
    delete socket;
}

TcpServer::~TcpServer()
{
    delete this;
}
