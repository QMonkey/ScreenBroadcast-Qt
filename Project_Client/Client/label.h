#ifndef LABEL_H
#define LABEL_H

#include <QtGui/QLabel>
#include <QtGui/QPixmap>
#include <QtCore/QPoint>

class QKeyEvent;
class QMouseEvent;

class Label : public QLabel
{
    Q_OBJECT
public:
    explicit Label(QWidget *parent = 0);
    
signals:
    void destroySig();
public slots:
    void acShowReq();
private:
    void closeEvent(QCloseEvent *);
    void timerEvent(QTimerEvent *);
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    QPoint mouseGlobalPos;
    QPoint mousePos;
    QPixmap pix;
};

#endif // LABEL_H
