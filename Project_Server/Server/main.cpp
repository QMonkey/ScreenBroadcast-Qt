#include <QtWidgets/QApplication>
#include <QtWidgets/QMessageBox>
#include "host.h"
#include "service_mgr.h"

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    if(argc < 3)
    {
        QMessageBox::critical(NULL,QObject::tr("Server"),QObject::tr("Unknow ip or port."));
    }
    else
    {
        Host::port = atoi(argv[2]);
        Host::ip_address = argv[1];
        //Host::ip_address = "0.0.0.0";
        //Host::host = new QHostAddress(QHostAddress::AnyIPv4);
        Host::host = new QHostAddress(Host::ip_address);
        ServiceMgr *mgr = new ServiceMgr;
        mgr->startService();
    }
    return app.exec();
}
