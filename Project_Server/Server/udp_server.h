#ifndef UDP_SERVER_H
#define UDP_SERVER_H

#include <QtCore/QThread>

class QByteArray;

class UdpServer : public QThread
{
    Q_OBJECT
public:
    explicit UdpServer(QObject *parent = 0);

signals:

public slots:

private:
    void run();
    void timerEvent(QTimerEvent *);
    void sendDiff();
    void sendAll();
    QByteArray *dest;
};

#endif // SERVER_H
