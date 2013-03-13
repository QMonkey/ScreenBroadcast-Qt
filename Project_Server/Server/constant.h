#ifndef CONSTANT_H
#define CONSTANT_H

#include <QtGlobal>
#include <QtNetwork/QHostAddress>

quint8 const UPDATE_TIMES = 3;
quint8 const COMPRESS_LEVEL = 9;
quint8 const UDP_SLEEP_TIME_MS = 60;
quint8 const SCREENSHOT_SLEEP_TIME_MS = 60;
quint16 const DATASIZE_PER_PACKET = 1020;
char const* const IMAGE_FORMAT = "bmp";
//char const* const IP_ADDRESS = "0.0.0.0";
//QHostAddress const host(IP_ADDRESS);

#endif // CONSTANT_H
