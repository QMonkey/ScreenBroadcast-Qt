#include "constant.h"
#include "label.h"
#include "service_mgr.h"
#include "tcp_client.h"
#include "tcp_clientend.h"
#include "udp_client.h"

ServiceMgr::ServiceMgr(QObject *parent) :
    QThread(parent),tcp_client(new TcpClient(this)),
    tcp_client_end(new TcpClientEnd(this)),label(new Label)
{
    connect(tcp_client,SIGNAL(showReq()),label,SLOT(acShowReq()));
    connect(label,SIGNAL(destroySig()),tcp_client_end,SLOT(acDestroySig()));
}

void ServiceMgr::startRpt() const
{
    label->startTimer(REPAINT_TIME_MS);
    UdpClient *client = new UdpClient;
}

void ServiceMgr::run()
{
    tcp_client->start();
    exec();
}

ServiceMgr::~ServiceMgr()
{
    delete label;
}
