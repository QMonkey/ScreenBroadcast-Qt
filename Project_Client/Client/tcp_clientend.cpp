#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include "host.h"
#include "tcp_clientend.h"

TcpClientEnd::TcpClientEnd(QObject *parent) :
    QThread(parent)
{
}

void TcpClientEnd::acDestroySig()
{
    start();
}

void TcpClientEnd::run()
{
    QTcpSocket *socket = new QTcpSocket;
    socket->connectToHost(Host::ip_address,Host::port+2);
    socket->waitForConnected(-1);
    delete socket;
}
