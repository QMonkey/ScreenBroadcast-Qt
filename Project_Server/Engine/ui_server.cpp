#include<QtWidgets/QMessageBox>
#include<QtCore/QDir>
#include<QtCore/QProcess>
#include<QtNetwork/QHostAddress>
#include<QtNetwork/QTcpSocket>
#include"ui_server.h"

UI_Server::UI_Server(QWidget *parent) :
    QDialog(parent),process(new QProcess)
{
    setupUi(this);
    setWinIcon();
    connection();
}

void UI_Server::setWinIcon()
{
    QIcon icon(":/image/homeserver.png");
    setWindowIcon(icon);
    setWindowTitle(tr("Start server"));
}

void UI_Server::connection()
{
    connect(server_lineEdit_port,SIGNAL(textChanged(QString)),this,SLOT(lineEditEmpty(QString)));
    connect(server_button_start,SIGNAL(clicked()),this,SLOT(disableWidget()));
    connect(server_button_start,SIGNAL(clicked()),this,SLOT(startServer()));
    connect(server_button_close,SIGNAL(clicked()),this,SLOT(close()));
    connect(server_button_stop,SIGNAL(clicked()),this,SLOT(enableWidget()));
    connect(server_button_stop,SIGNAL(clicked()),this,SLOT(stopListening()));
    connect(server_button_stop,SIGNAL(clicked()),process,SLOT(kill()));
}

void UI_Server::closeEvent(QCloseEvent *)
{
    process->kill();
}

void UI_Server::lineEditEmpty(QString text)
{
    if(text.isEmpty())
    {
        server_button_start->setDisabled(true);
    }
    else
    {
        server_button_start->setDisabled(false);
    }
}

void UI_Server::startServer()
{
    QStringList str_lst;
    QString ip=server_lineEdit_ip->text();
    str_lst.append(ip);
    QString port=server_lineEdit_port->text();
    str_lst.append(port);
    process->start(QDir::toNativeSeparators(QDir::current().absoluteFilePath("Server")),str_lst);
    QMessageBox::information(this,tr("Server"),tr("Start server.\nIP:")+ip+tr("\nPort:")+port);
}

void UI_Server::disableWidget()
{
    server_button_start->setDisabled(true);
    server_lineEdit_ip->setEnabled(false);
    server_lineEdit_port->setEnabled(false);
    server_button_stop->setDisabled(false);
}

void UI_Server::enableWidget()
{
    server_button_start->setDisabled(false);
    server_lineEdit_ip->setEnabled(true);
    server_lineEdit_port->setEnabled(true);
    server_button_stop->setDisabled(true);
}

void UI_Server::stopListening()
{
    QMessageBox::warning(this,tr("Stop"),tr("Stop listening."));
}

UI_Server::~UI_Server()
{
    delete process;
}
