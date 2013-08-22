#include <QtNetwork/QTcpSocket>
#include "data.h"
#include "tcp_serverend.h"

TcpServerEnd::TcpServerEnd(QObject *parent) :
    QTcpServer(parent)
{
}

void TcpServerEnd::incomingConnection(qintptr handle)
{
    QTcpSocket *socket = new QTcpSocket;
    socket->setSocketDescriptor(handle);
    Data::address_lst.removeOne(socket->peerAddress());
    delete socket;
}

TcpServerEnd::~TcpServerEnd()
{
    delete this;
}
