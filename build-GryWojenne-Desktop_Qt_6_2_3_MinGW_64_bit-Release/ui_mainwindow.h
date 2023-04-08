/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_2;
    QLabel *label_3;
    QPushButton *wyjscie;
    QPushButton *Rozpocznij_potyczke;
    QComboBox *comboBox;
    QLabel *label_4;
    QComboBox *comboBox_2;
    QTextBrowser *textBrowser;
    QComboBox *comboBox_3;
    QSpinBox *spinBox;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *dodaj_jednostke_Button;
    QPushButton *kasuj_oddzialy;
    QPushButton *LosujButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(766, 468);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 730, 421));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser_2 = new QTextBrowser(gridLayoutWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        QFont font;
        font.setPointSize(11);
        textBrowser_2->setFont(font);
        textBrowser_2->setFrameShape(QFrame::Box);

        gridLayout->addWidget(textBrowser_2, 1, 2, 3, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QFont font1;
        font1.setBold(true);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        wyjscie = new QPushButton(gridLayoutWidget);
        wyjscie->setObjectName(QString::fromUtf8("wyjscie"));

        gridLayout->addWidget(wyjscie, 6, 2, 1, 1);

        Rozpocznij_potyczke = new QPushButton(gridLayoutWidget);
        Rozpocznij_potyczke->setObjectName(QString::fromUtf8("Rozpocznij_potyczke"));

        gridLayout->addWidget(Rozpocznij_potyczke, 6, 3, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        comboBox_2 = new QComboBox(gridLayoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 2, 1, 1, 1);

        textBrowser = new QTextBrowser(gridLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setFont(font);

        gridLayout->addWidget(textBrowser, 1, 3, 3, 1);

        comboBox_3 = new QComboBox(gridLayoutWidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        gridLayout->addWidget(comboBox_3, 5, 3, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setValue(1);

        gridLayout->addWidget(spinBox, 3, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 5, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setPointSize(18);
        font2.setBold(true);
        label_5->setFont(font2);
        label_5->setMouseTracking(false);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setFrameShape(QFrame::WinPanel);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font2);
        label_6->setFrameShape(QFrame::WinPanel);
        label_6->setFrameShadow(QFrame::Plain);
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 0, 3, 1, 1);

        dodaj_jednostke_Button = new QPushButton(gridLayoutWidget);
        dodaj_jednostke_Button->setObjectName(QString::fromUtf8("dodaj_jednostke_Button"));

        gridLayout->addWidget(dodaj_jednostke_Button, 4, 1, 1, 1);

        kasuj_oddzialy = new QPushButton(gridLayoutWidget);
        kasuj_oddzialy->setObjectName(QString::fromUtf8("kasuj_oddzialy"));

        gridLayout->addWidget(kasuj_oddzialy, 5, 1, 1, 1);

        LosujButton = new QPushButton(gridLayoutWidget);
        LosujButton->setObjectName(QString::fromUtf8("LosujButton"));

        gridLayout->addWidget(LosujButton, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 766, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:600; color:#550000;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell"
                        " Dlg 2'; font-size:9pt; font-weight:600; color:#550000;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:600; color:#550000;\">Lista jednostek dodanych do oddzia\305\202u </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:600; color:#550000;\">ISIS</span><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:600; color:#550000;\">. </span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Typ jednostki:", nullptr));
        wyjscie->setText(QCoreApplication::translate("MainWindow", "Wyj\305\233cie", nullptr));
        Rozpocznij_potyczke->setText(QCoreApplication::translate("MainWindow", "Rozpocznij potyczk\304\231", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "ISIS", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "NATO", nullptr));

        comboBox->setCurrentText(QCoreApplication::translate("MainWindow", "ISIS", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Frakcja:", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Piechota", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Lotnictwo", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Artyleria", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Czolg", nullptr));

        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:600; color:#550000;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'MS Shell Dlg 2'; font-"
                        "size:8.25pt; font-weight:600; color:#55007f;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2'; font-size:9pt; font-weight:600; color:#005500;\">Lista jednostek dodanych do oddzia\305\202u </span><span style=\" font-family:'MS Shell Dlg 2'; font-size:14pt; font-weight:600; color:#005500;\">NATO</span></p></body></html>", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "Pustynia", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Miasto", nullptr));

        spinBox->setSuffix(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "                                       Rodzaj terenu:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Ilo\305\233\304\207 jednostek:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "ISIS", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "NATO", nullptr));
        dodaj_jednostke_Button->setText(QCoreApplication::translate("MainWindow", "Dodaj", nullptr));
        kasuj_oddzialy->setText(QCoreApplication::translate("MainWindow", "Kasuj oddzialy", nullptr));
        LosujButton->setText(QCoreApplication::translate("MainWindow", "Losuj jednostki", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
