/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed Jul 4 16:04:01 2012
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
    QGridLayout *server_gridLayout;
    QSpacerItem *server_horizontalSpacer_4;
    QLineEdit *server_lineEdit_ip;
    QSpacerItem *server_horizontalSpacer_3;
    QSpacerItem *server_horizontalSpacer_5;
    QLabel *server_label_port;
    QLineEdit *server_lineEdit_port;
    QSpacerItem *server_horizontalSpacer;
    QLabel *server_label_ip;
    QHBoxLayout *server_horizontalLayout;
    QSpacerItem *server_horizontalSpacer_1;
    QPushButton *server_button_start;
    QPushButton *server_button_stop;
    QPushButton *server_button_close;
    QSpacerItem *server_horizontalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(299, 115);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        server_gridLayout = new QGridLayout();
        server_gridLayout->setSpacing(6);
        server_gridLayout->setObjectName(QString::fromUtf8("server_gridLayout"));
        server_horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        server_gridLayout->addItem(server_horizontalSpacer_4, 0, 0, 1, 2);

        server_lineEdit_ip = new QLineEdit(Dialog);
        server_lineEdit_ip->setObjectName(QString::fromUtf8("server_lineEdit_ip"));

        server_gridLayout->addWidget(server_lineEdit_ip, 0, 3, 1, 1);

        server_horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        server_gridLayout->addItem(server_horizontalSpacer_3, 0, 4, 1, 1);

        server_horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        server_gridLayout->addItem(server_horizontalSpacer_5, 1, 0, 1, 1);

        server_label_port = new QLabel(Dialog);
        server_label_port->setObjectName(QString::fromUtf8("server_label_port"));

        server_gridLayout->addWidget(server_label_port, 1, 1, 1, 2);

        server_lineEdit_port = new QLineEdit(Dialog);
        server_lineEdit_port->setObjectName(QString::fromUtf8("server_lineEdit_port"));

        server_gridLayout->addWidget(server_lineEdit_port, 1, 3, 1, 1);

        server_horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        server_gridLayout->addItem(server_horizontalSpacer, 1, 4, 1, 1);

        server_label_ip = new QLabel(Dialog);
        server_label_ip->setObjectName(QString::fromUtf8("server_label_ip"));

        server_gridLayout->addWidget(server_label_ip, 0, 2, 1, 1);


        verticalLayout->addLayout(server_gridLayout);

        server_horizontalLayout = new QHBoxLayout();
        server_horizontalLayout->setSpacing(6);
        server_horizontalLayout->setObjectName(QString::fromUtf8("server_horizontalLayout"));
        server_horizontalSpacer_1 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        server_horizontalLayout->addItem(server_horizontalSpacer_1);

        server_button_start = new QPushButton(Dialog);
        server_button_start->setObjectName(QString::fromUtf8("server_button_start"));
        server_button_start->setEnabled(false);

        server_horizontalLayout->addWidget(server_button_start);

        server_button_stop = new QPushButton(Dialog);
        server_button_stop->setObjectName(QString::fromUtf8("server_button_stop"));
        server_button_stop->setEnabled(false);

        server_horizontalLayout->addWidget(server_button_stop);

        server_button_close = new QPushButton(Dialog);
        server_button_close->setObjectName(QString::fromUtf8("server_button_close"));

        server_horizontalLayout->addWidget(server_button_close);

        server_horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        server_horizontalLayout->addItem(server_horizontalSpacer_2);


        verticalLayout->addLayout(server_horizontalLayout);

#ifndef QT_NO_SHORTCUT
        server_label_port->setBuddy(server_lineEdit_port);
        server_label_ip->setBuddy(server_lineEdit_ip);
#endif // QT_NO_SHORTCUT

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Server", 0, QApplication::UnicodeUTF8));
        server_label_port->setText(QApplication::translate("Dialog", "&Port:", 0, QApplication::UnicodeUTF8));
        server_label_ip->setText(QApplication::translate("Dialog", "&IP:", 0, QApplication::UnicodeUTF8));
        server_button_start->setText(QApplication::translate("Dialog", "&Start", 0, QApplication::UnicodeUTF8));
        server_button_stop->setText(QApplication::translate("Dialog", "St&op", 0, QApplication::UnicodeUTF8));
        server_button_close->setText(QApplication::translate("Dialog", "&Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
