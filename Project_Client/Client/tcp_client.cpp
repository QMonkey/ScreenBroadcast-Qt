#include <QtCore/QByteArray>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QTcpSocket>
#include "constant.h"
#include "data.h"
#include "host.h"
#include "tcp_client.h"

TcpClient::TcpClient(QObject *parent) :
    QThread(parent)
{
}

void TcpClient::run()
{
    QTcpSocket *socket = new QTcpSocket;
    socket->connectToHost(Host::ip_address,Host::port);
    socket->waitForConnected(-1);
    socket->waitForReadyRead(-1);
    QByteArray head = socket->readAll();
    Data::width = *(quint16*)head.data();
    Data::height = *(quint16*)(head.data()+sizeof(quint16));
    Data::src->resize(*(quint32*)(head.data()+(sizeof(quint16)<<1)));
    emit showReq();
    delete socket;
}
