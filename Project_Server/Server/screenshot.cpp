#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtGui/QPixmap>
#include <QtGui/QScreen>
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
    QScreen *screen = QApplication::primaryScreen();
    QPixmap pix = screen->grabWindow(0);
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
