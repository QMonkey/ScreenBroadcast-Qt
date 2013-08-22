#include<QtWidgets/QApplication>
#include"ui_server.h"
int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    UI_Server server;
    server.show();
    return app.exec();
}
