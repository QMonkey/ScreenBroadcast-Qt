#ifndef HOST_H
#define HOST_H

#include <QtGlobal>
#include <QtNetwork/QHostAddress>

class Host
{
public:
    static quint16 port;
    static char const* ip_address;
    static QHostAddress const* host;
};

#endif // HOST_H
