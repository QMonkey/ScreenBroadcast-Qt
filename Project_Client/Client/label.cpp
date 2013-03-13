#include <QtGui/QKeyEvent>
#include <QtGui/QMouseEvent>
#include <QtGui/QPainter>
#include <QtCore/QSize>
#include "constant.h"
#include "data.h"
#include "label.h"

Label::Label(QWidget *parent) :
    QLabel(parent)
{
}

void Label::acShowReq()
{
    setFixedSize(Data::width,Data::height);
    show();
}

void Label::closeEvent(QCloseEvent *)
{
    emit destroySig();
}

void Label::timerEvent(QTimerEvent *)
{
    pix.loadFromData(*Data::src,IMAGE_FORMAT);
    setAttribute(Qt::WA_OpaquePaintEvent);
    update();
}

void Label::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix.size().width(),pix.size().height(),pix);
}

void Label::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Escape)
    {
        close();
    }
}

void Label::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        QPoint newGlobalPos = ev->globalPos();
        QPoint coordinate = mousePos+newGlobalPos-mouseGlobalPos;
        move(coordinate);
    }
}

void Label::mousePressEvent(QMouseEvent *ev)
{
    if(ev->buttons() == Qt::LeftButton)
    {
        mouseGlobalPos = ev->globalPos();
        mousePos = ev->globalPos()-ev->pos();
    }
}
