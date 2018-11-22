/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *titleBar;
    QPushButton *titleIcon;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *mini_btn;
    QPushButton *max_btn;
    QPushButton *close_btn;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QPushButton *start_btn;
    QPushButton *end_btn;
    QPushButton *port_modify_btn;
    QPushButton *config_btn;
    QHBoxLayout *horizontalLayout_timer;
    QSpacerItem *horizontalSpacer;
    QLabel *highlightLabel;
    QSpacerItem *horizontalSpacer_3;
    QLCDNumber *timer;
    QSpacerItem *horizontalSpacer_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tableView;
    QWidget *tab_2;
    QListView *listView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(775, 578);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(8, 4, 761, 521));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new QHBoxLayout();
        titleBar->setSpacing(6);
        titleBar->setObjectName(QStringLiteral("titleBar"));
        titleBar->setContentsMargins(-1, -1, -1, 10);
        titleIcon = new QPushButton(layoutWidget);
        titleIcon->setObjectName(QStringLiteral("titleIcon"));

        titleBar->addWidget(titleIcon);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        titleBar->addItem(horizontalSpacer_4);

        mini_btn = new QPushButton(layoutWidget);
        mini_btn->setObjectName(QStringLiteral("mini_btn"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mini_btn->sizePolicy().hasHeightForWidth());
        mini_btn->setSizePolicy(sizePolicy1);
        mini_btn->setStyleSheet(QStringLiteral("QPushButton{border:none;}"));
        QIcon icon;
        icon.addFile(QStringLiteral("images/mini_btn.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        mini_btn->setIcon(icon);

        titleBar->addWidget(mini_btn);

        max_btn = new QPushButton(layoutWidget);
        max_btn->setObjectName(QStringLiteral("max_btn"));
        sizePolicy1.setHeightForWidth(max_btn->sizePolicy().hasHeightForWidth());
        max_btn->setSizePolicy(sizePolicy1);
        max_btn->setStyleSheet(QStringLiteral("QPushButton{border:none;}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("images/max_btn.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        max_btn->setIcon(icon1);

        titleBar->addWidget(max_btn);

        close_btn = new QPushButton(layoutWidget);
        close_btn->setObjectName(QStringLiteral("close_btn"));
        sizePolicy1.setHeightForWidth(close_btn->sizePolicy().hasHeightForWidth());
        close_btn->setSizePolicy(sizePolicy1);
        close_btn->setStyleSheet(QStringLiteral("QPushButton{border:none;}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("images/close_btn.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        close_btn->setIcon(icon2);

        titleBar->addWidget(close_btn);


        verticalLayout->addLayout(titleBar);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setStyleSheet(QStringLiteral(""));
        lineEdit->setCursorPosition(4);
        lineEdit->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(lineEdit);

        start_btn = new QPushButton(layoutWidget);
        start_btn->setObjectName(QStringLiteral("start_btn"));

        horizontalLayout_2->addWidget(start_btn);

        end_btn = new QPushButton(layoutWidget);
        end_btn->setObjectName(QStringLiteral("end_btn"));
        end_btn->setEnabled(true);
        end_btn->setAutoDefault(false);
        end_btn->setFlat(false);

        horizontalLayout_2->addWidget(end_btn);

        port_modify_btn = new QPushButton(layoutWidget);
        port_modify_btn->setObjectName(QStringLiteral("port_modify_btn"));
        port_modify_btn->setAutoDefault(false);
        port_modify_btn->setFlat(false);

        horizontalLayout_2->addWidget(port_modify_btn);

        config_btn = new QPushButton(layoutWidget);
        config_btn->setObjectName(QStringLiteral("config_btn"));

        horizontalLayout_2->addWidget(config_btn);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_timer = new QHBoxLayout();
        horizontalLayout_timer->setSpacing(6);
        horizontalLayout_timer->setObjectName(QStringLiteral("horizontalLayout_timer"));
        horizontalLayout_timer->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_timer->addItem(horizontalSpacer);

        highlightLabel = new QLabel(layoutWidget);
        highlightLabel->setObjectName(QStringLiteral("highlightLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(highlightLabel->sizePolicy().hasHeightForWidth());
        highlightLabel->setSizePolicy(sizePolicy2);
        highlightLabel->setStyleSheet(QStringLiteral("color:#ffffff"));

        horizontalLayout_timer->addWidget(highlightLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_timer->addItem(horizontalSpacer_3);

        timer = new QLCDNumber(layoutWidget);
        timer->setObjectName(QStringLiteral("timer"));
        timer->setInputMethodHints(Qt::ImhNone);

        horizontalLayout_timer->addWidget(timer);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_timer->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_timer);

        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableView = new QTableView(tab);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 751, 411));
        tableView->horizontalHeader()->setVisible(true);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        listView = new QListView(tab_2);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(0, 0, 751, 411));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 775, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        mini_btn->setDefault(true);
        max_btn->setDefault(true);
        close_btn->setDefault(true);
        start_btn->setDefault(true);
        end_btn->setDefault(true);
        port_modify_btn->setDefault(true);
        config_btn->setDefault(true);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        titleIcon->setText(QString());
        mini_btn->setText(QString());
        max_btn->setText(QString());
        close_btn->setText(QString());
        lineEdit->setText(QApplication::translate("MainWindow", "8080", nullptr));
        start_btn->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        end_btn->setText(QApplication::translate("MainWindow", "\347\273\223\346\235\237", nullptr));
        port_modify_btn->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\253\257\345\217\243", nullptr));
        config_btn->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\233\256\345\275\225", nullptr));
        highlightLabel->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214\346\227\266\351\227\264", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
