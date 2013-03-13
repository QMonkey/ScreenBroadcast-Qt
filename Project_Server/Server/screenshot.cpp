#include <QtGui/QApplication>
#include <QtGui/QDesktopWidget>
#include <QtGui/QPixmap>
#include <QtCore/QBuffer>
#include "constant.h"
#include "data.h"
#include "screenshot.h"
#include <QtCore>
Screenshot::Screenshot(QObject *parent) :
    QThread(parent)
{
    Data::width = QApplication::desktop()->width();
    Data::height = QApplication::desktop()->height();
    saveScreen(Data::src);
}

void Screenshot::saveScreen(QByteArray *src)
{
    QPixmap pix = QPixmap::grabWindow(QDesktopWidget().screen()->winId(),
                                      0,0,Data::width,Data::height);
    QBuffer buffer(src);
    pix.save(&buffer,IMAGE_FORMAT);
}

void Screenshot::screenshot()
{
    for( ; ; )
    {
        saveScreen(Data::src);
        msleep(SCREENSHOT_SLEEP_TIME_MS);
        QApplication::processEvents();
    }
}

void Screenshot::timerEvent(QTimerEvent *)
{
    saveScreen(Data::src);
}
