#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtGui/QDialog>
#include<QtCore/QString>
#include"ui_dialog.h"

class QProcess;
class UI_Client : public QDialog,public Ui_Dialog
{
    Q_OBJECT
public:
    explicit UI_Client(QWidget *parent = 0);
    ~UI_Client();
signals:

public slots:
    void lineEditEmpty(QString text);
    void startClient();
    void disableWidget();
    void enableWidget();
    void stopListening();
private:
    void closeEvent(QCloseEvent *);
    void setWinIcon();
    void connection();
    QProcess* process;
};

#endif // UI_SERVER_H
