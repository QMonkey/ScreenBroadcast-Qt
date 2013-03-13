#include <QtNetwork/QHostAddress>
#include "host.h"
#include "tcp_endthread.h"
#include "tcp_serverend.h"

TcpEndThread::TcpEndThread(QObject *parent) :
    QThread(parent)
{
}

void TcpEndThread::run()
{
    TcpServerEnd *server = new TcpServerEnd;
    server->listen(*Host::host,Host::port+2);
    exec();
}
