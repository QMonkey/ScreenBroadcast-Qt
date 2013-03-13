#include<QtGui/QMessageBox>
#include<QtCore/QDir>
#include<QtCore/QProcess>
#include<QtNetwork/QHostAddress>
#include<QtNetwork/QTcpSocket>
#include"ui_client.h"

UI_Client::UI_Client(QWidget *parent) :
    QDialog(parent),process(new QProcess)
{
    setupUi(this);
    setWinIcon();
    connection();
}

void UI_Client::setWinIcon()
{
    QIcon icon(":/image/imac.png");
    setWindowIcon(icon);
    setWindowTitle(tr("Start client"));
}

void UI_Client::connection()
{
    connect(client_lineEdit_port,SIGNAL(textChanged(QString)),this,SLOT(lineEditEmpty(QString)));
    connect(client_button_connect,SIGNAL(clicked()),this,SLOT(disableWidget()));
    connect(client_button_connect,SIGNAL(clicked()),this,SLOT(startClient()));
    connect(client_button_close,SIGNAL(clicked()),this,SLOT(close()));
    connect(client_button_disconnect,SIGNAL(clicked()),this,SLOT(enableWidget()));
    connect(client_button_disconnect,SIGNAL(clicked()),this,SLOT(stopListening()));
    connect(client_button_disconnect,SIGNAL(clicked()),process,SLOT(kill()));
}

void UI_Client::closeEvent(QCloseEvent *)
{
    process->kill();
}

void UI_Client::lineEditEmpty(QString text)
{
    if(text.isEmpty())
    {
        client_button_connect->setDisabled(true);
    }
    else
    {
        client_button_connect->setDisabled(false);
    }
}

void UI_Client::startClient()
{
    QStringList str_lst;
    QString ip=client_lineEdit_ip->text();
    str_lst.append(ip);
    QString port=client_lineEdit_port->text();
    str_lst.append(port);
    process->start(QDir::toNativeSeparators(QDir::current().absoluteFilePath("Client")),str_lst);
    QMessageBox::information(this,tr("Client"),tr("Start client.\nIP:")+ip+tr("\nPort:")+port);
}

void UI_Client::disableWidget()
{
    client_button_connect->setDisabled(true);
    client_lineEdit_ip->setEnabled(false);
    client_lineEdit_port->setEnabled(false);
    client_button_disconnect->setDisabled(false);
}

void UI_Client::enableWidget()
{
    client_button_connect->setDisabled(false);
    client_lineEdit_ip->setEnabled(true);
    client_lineEdit_port->setEnabled(true);
    client_button_disconnect->setDisabled(true);
}

void UI_Client::stopListening()
{
    QMessageBox::warning(this,tr("Stop"),tr("Stop receiving."));
}

UI_Client::~UI_Client()
{
    delete process;
}
