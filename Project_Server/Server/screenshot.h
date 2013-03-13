#ifndef SCREENSHOT_H
#define SCREENSHOT_H

#include <QtCore/QThread>

class QByteArray;

class Screenshot : public QThread
{
    Q_OBJECT
public:
    explicit Screenshot(QObject *parent = 0);
    void screenshot();
signals:

public slots:

private:
    void saveScreen(QByteArray *src);
    void timerEvent(QTimerEvent *);
};

#endif // SCREENSHOT_H
