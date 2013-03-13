/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed Jul 11 13:07:52 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *client_gridLayout;
    QSpacerItem *client_horizontalSpacer_4;
    QLineEdit *client_lineEdit_ip;
    QSpacerItem *client_horizontalSpacer_3;
    QSpacerItem *client_horizontalSpacer_5;
    QLabel *client_label_port;
    QLineEdit *client_lineEdit_port;
    QSpacerItem *client_horizontalSpacer;
    QLabel *client_label_ip;
    QHBoxLayout *client_horizontalLayout;
    QSpacerItem *client_horizontalSpacer_1;
    QPushButton *client_button_connect;
    QPushButton *client_button_disconnect;
    QPushButton *client_button_close;
    QSpacerItem *client_horizontalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(299, 115);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        client_gridLayout = new QGridLayout();
        client_gridLayout->setSpacing(6);
        client_gridLayout->setObjectName(QString::fromUtf8("client_gridLayout"));
        client_horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        client_gridLayout->addItem(client_horizontalSpacer_4, 0, 0, 1, 2);

        client_lineEdit_ip = new QLineEdit(Dialog);
        client_lineEdit_ip->setObjectName(QString::fromUtf8("client_lineEdit_ip"));

        client_gridLayout->addWidget(client_lineEdit_ip, 0, 3, 1, 1);

        client_horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        client_gridLayout->addItem(client_horizontalSpacer_3, 0, 4, 1, 1);

        client_horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        client_gridLayout->addItem(client_horizontalSpacer_5, 1, 0, 1, 1);

        client_label_port = new QLabel(Dialog);
        client_label_port->setObjectName(QString::fromUtf8("client_label_port"));

        client_gridLayout->addWidget(client_label_port, 1, 1, 1, 2);

        client_lineEdit_port = new QLineEdit(Dialog);
        client_lineEdit_port->setObjectName(QString::fromUtf8("client_lineEdit_port"));

        client_gridLayout->addWidget(client_lineEdit_port, 1, 3, 1, 1);

        client_horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        client_gridLayout->addItem(client_horizontalSpacer, 1, 4, 1, 1);

        client_label_ip = new QLabel(Dialog);
        client_label_ip->setObjectName(QString::fromUtf8("client_label_ip"));

        client_gridLayout->addWidget(client_label_ip, 0, 2, 1, 1);


        verticalLayout->addLayout(client_gridLayout);

        client_horizontalLayout = new QHBoxLayout();
        client_horizontalLayout->setSpacing(6);
        client_horizontalLayout->setObjectName(QString::fromUtf8("client_horizontalLayout"));
        client_horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        client_horizontalLayout->addItem(client_horizontalSpacer_1);

        client_button_connect = new QPushButton(Dialog);
        client_button_connect->setObjectName(QString::fromUtf8("client_button_connect"));

        client_horizontalLayout->addWidget(client_button_connect);

        client_button_disconnect = new QPushButton(Dialog);
        client_button_disconnect->setObjectName(QString::fromUtf8("client_button_disconnect"));
        client_button_disconnect->setEnabled(false);

        client_horizontalLayout->addWidget(client_button_disconnect);

        client_button_close = new QPushButton(Dialog);
        client_button_close->setObjectName(QString::fromUtf8("client_button_close"));

        client_horizontalLayout->addWidget(client_button_close);

        client_horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        client_horizontalLayout->addItem(client_horizontalSpacer_2);


        verticalLayout->addLayout(client_horizontalLayout);

#ifndef QT_NO_SHORTCUT
        client_label_port->setBuddy(client_lineEdit_port);
        client_label_ip->setBuddy(client_lineEdit_ip);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Client", 0, QApplication::UnicodeUTF8));
        client_label_port->setText(QApplication::translate("Dialog", "&Port:", 0, QApplication::UnicodeUTF8));
        client_label_ip->setText(QApplication::translate("Dialog", "&IP:", 0, QApplication::UnicodeUTF8));
        client_button_connect->setText(QApplication::translate("Dialog", "&Receive", 0, QApplication::UnicodeUTF8));
        client_button_disconnect->setText(QApplication::translate("Dialog", "&Stop", 0, QApplication::UnicodeUTF8));
        client_button_close->setText(QApplication::translate("Dialog", "Cl&ose", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
