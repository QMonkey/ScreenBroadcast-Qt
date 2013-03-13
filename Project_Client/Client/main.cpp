#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include "host.h"
#include "service_mgr.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    if(argc < 3)
    {
        QMessageBox::critical(NULL,QObject::tr("Client"),QObject::tr("Unknow ip or port."));
    }
    else
    {
        Host::port = atoi(argv[2]);
        Host::ip_address = argv[1];
        Host::host = new QHostAddress(Host::ip_address);
        ServiceMgr *mgr = new ServiceMgr;
        mgr->start();
        mgr->startRpt();
    }
    return app.exec();
}
