#include <QtNetwork/QHostAddress>
#include "host.h"
#include "tcp_server.h"
#include "tcp_serverthread.h"

TcpServerThread::TcpServerThread(QObject *parent) :
    QThread(parent)
{
}

void TcpServerThread::run()
{
    TcpServer *server = new TcpServer;
    server->listen(*Host::host,Host::port);
    exec();
}
