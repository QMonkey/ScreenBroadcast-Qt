#ifndef UDP_CLIENT_H
#define UDP_CLIENT_H

#include <QtCore/QObject>

class QUdpSocket;

class UdpClient : public QObject
{
    Q_OBJECT
public:
    explicit UdpClient(QObject *parent = 0);

signals:

public slots:
    void recv();
private:
    inline QByteArray rduc(QUdpSocket *socket);
    QUdpSocket *udp_socket;
};

#endif // CLIENT_H
