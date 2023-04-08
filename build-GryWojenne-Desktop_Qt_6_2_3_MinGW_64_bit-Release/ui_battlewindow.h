/********************************************************************************
** Form generated from reading UI file 'battlewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTLEWINDOW_H
#define UI_BATTLEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_battlewindow
{
public:
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label;
    QGraphicsView *graphicsView;
    QTextBrowser *textBrowser;

    void setupUi(QDialog *battlewindow)
    {
        if (battlewindow->objectName().isEmpty())
            battlewindow->setObjectName(QString::fromUtf8("battlewindow"));
        battlewindow->resize(850, 650);
        pushButton = new QPushButton(battlewindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(589, 390, 131, 31));
        label_2 = new QLabel(battlewindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 440, 181, 141));
        label = new QLabel(battlewindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 10, 181, 141));
        graphicsView = new QGraphicsView(battlewindow);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 10, 521, 571));
        textBrowser = new QTextBrowser(battlewindow);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(550, 180, 201, 192));

        retranslateUi(battlewindow);

        QMetaObject::connectSlotsByName(battlewindow);
    } // setupUi

    void retranslateUi(QDialog *battlewindow)
    {
        battlewindow->setWindowTitle(QCoreApplication::translate("battlewindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("battlewindow", "Zamknij ", nullptr));
        label_2->setText(QCoreApplication::translate("battlewindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("battlewindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class battlewindow: public Ui_battlewindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTLEWINDOW_H
