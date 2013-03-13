#include "constant.h"
#include "screenshot.h"
#include "service_mgr.h"
#include "tcp_endthread.h"
#include "tcp_serverthread.h"
#include "udp_server.h"

ServiceMgr::ServiceMgr(QObject *parent) :
    QObject(parent),screen(new Screenshot(this)),
    tcp_server_thread(new TcpServerThread(this)),
    udp_server(new UdpServer(this)),tcp_end_server(new TcpEndThread)
{
}

void ServiceMgr::startService() const
{
    tcp_server_thread->start();
    tcp_end_server->start();
    udp_server->start();
    screen->screenshot();
    //screen->startTimer(SCREENSHOT_SLEEP_TIME_MS);
}

ServiceMgr::~ServiceMgr()
{
    delete this;
}
