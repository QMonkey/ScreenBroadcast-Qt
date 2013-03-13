#include<QtGui/QApplication>
#include"ui_client.h"
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    UI_Client client;
    client.show();
    return app.exec();
}
