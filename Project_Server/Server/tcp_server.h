#ifndef TCP_SERVER_H
#define TCP_SERVER_H

#include <QtNetwork/QTcpServer>

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = 0);
    ~TcpServer();
signals:

public slots:

private:
    void incomingConnection(qintptr handle);
};

#endif // TCP_HEADERMSG_H
