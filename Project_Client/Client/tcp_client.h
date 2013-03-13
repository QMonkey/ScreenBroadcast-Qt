#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QtCore/QThread>

class TcpClient : public QThread
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = 0);
    
signals:
    void showReq();
public slots:
    
private:
    void run();
};

#endif // TCP_MSGCLIENT_H
