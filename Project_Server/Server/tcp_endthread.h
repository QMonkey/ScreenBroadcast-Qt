#ifndef TCP_ENDTHREAD_H
#define TCP_ENDTHREAD_H

#include <QtCore/QThread>

class TcpEndThread : public QThread
{
    Q_OBJECT
public:
    explicit TcpEndThread(QObject *parent = 0);
    
signals:
    
public slots:
    
private:
    void run();
};

#endif // TCP_ENDTHREAD_H
