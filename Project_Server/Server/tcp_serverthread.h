#ifndef TCP_SERVERTHREAD_H
#define TCP_SERVERTHREAD_H

#include <QtCore/QThread>

class TcpServerThread : public QThread
{
    Q_OBJECT
public:
    explicit TcpServerThread(QObject *parent = 0);
    
signals:

public slots:

private:
    void run();
};

#endif // TCP_HEADERMSGTHREAD_H
