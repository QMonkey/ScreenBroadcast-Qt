#ifndef DATA_H
#define DATA_H

#include <QtGlobal>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtNetwork/QHostAddress>

class Data
{
public:
    static QByteArray *src;
    static quint16 width;
    static quint16 height;
    static QList<QHostAddress> address_lst;
};

#endif // DATA_H
