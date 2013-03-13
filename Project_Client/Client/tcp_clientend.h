#ifndef TCP_CLIENTEND_H
#define TCP_CLIENTEND_H

#include <QThread>

class TcpClientEnd : public QThread
{
    Q_OBJECT
public:
    explicit TcpClientEnd(QObject *parent = 0);
    
signals:
    
public slots:
    void acDestroySig();
private:
    void run();
};

#endif // TCP_CLIENTEND_H
