#ifndef TCP_SERVEREND_H
#define TCP_SERVEREND_H

#include <QtNetwork/QTcpServer>

class TcpServerEnd : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServerEnd(QObject *parent = 0);
    ~TcpServerEnd();
signals:
    
public slots:
    
private:
    void incomingConnection(qintptr handle);
};

#endif // TCP_SERVEREND_H
