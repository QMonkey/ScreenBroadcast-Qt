#ifndef CREATE_CLIENT_H
#define CREATE_CLIENT_H

#include <QtCore/QThread>

class TcpClient;
class TcpClientEnd;
class Label;

class ServiceMgr : public QThread
{
    Q_OBJECT
public:
    explicit ServiceMgr(QObject *parent = 0);
    ~ServiceMgr();
    void startRpt() const;
signals:
    
public slots:
    
private:
    void run();
    TcpClient *tcp_client;
    TcpClientEnd *tcp_client_end;
    Label *label;
};

#endif // CREATE_CLIENT_H
