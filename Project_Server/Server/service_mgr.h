#ifndef SERVICE_MGR_H
#define SERVICE_MGR_H

#include <QtCore/QObject>

class Screenshot;
class TcpServerThread;
class UdpServer;
class TcpEndThread;

class ServiceMgr : public QObject
{
    Q_OBJECT
public:
    explicit ServiceMgr(QObject *parent = 0);
    ~ServiceMgr();
    void startService() const;
signals:
    
public slots:

private:
    Screenshot *screen;
    TcpServerThread *tcp_server_thread;
    UdpServer *udp_server;
    TcpEndThread *tcp_end_server;
};

#endif // SIGNALSLOT_MGR_H
