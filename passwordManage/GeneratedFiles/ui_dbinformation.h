/********************************************************************************
** Form generated from reading UI file 'dbinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBINFORMATION_H
#define UI_DBINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBInformation
{
public:
    QLabel *driveLabel;
    QLabel *hostNameLabel;
    QLabel *dataBaseLabel;
    QLabel *userNameLabel;
    QLabel *passwordLabel;
    QComboBox *driveComboBox;
    QLineEdit *hostLineEdit;
    QLineEdit *databaseLineEdit;
    QLineEdit *userNameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *cancelPushButton;
    QPushButton *okPushButton;
    QLabel *tableLabel;
    QLineEdit *tableLineEdit;

    void setupUi(QWidget *DBInformation)
    {
        if (DBInformation->objectName().isEmpty())
            DBInformation->setObjectName(QStringLiteral("DBInformation"));
        DBInformation->resize(479, 300);
        driveLabel = new QLabel(DBInformation);
        driveLabel->setObjectName(QStringLiteral("driveLabel"));
        driveLabel->setGeometry(QRect(30, 30, 61, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        driveLabel->setFont(font);
        driveLabel->setAlignment(Qt::AlignCenter);
        hostNameLabel = new QLabel(DBInformation);
        hostNameLabel->setObjectName(QStringLiteral("hostNameLabel"));
        hostNameLabel->setGeometry(QRect(30, 80, 61, 16));
        hostNameLabel->setFont(font);
        hostNameLabel->setAlignment(Qt::AlignCenter);
        dataBaseLabel = new QLabel(DBInformation);
        dataBaseLabel->setObjectName(QStringLiteral("dataBaseLabel"));
        dataBaseLabel->setGeometry(QRect(30, 130, 61, 16));
        dataBaseLabel->setFont(font);
        dataBaseLabel->setAlignment(Qt::AlignCenter);
        userNameLabel = new QLabel(DBInformation);
        userNameLabel->setObjectName(QStringLiteral("userNameLabel"));
        userNameLabel->setGeometry(QRect(30, 220, 61, 16));
        userNameLabel->setFont(font);
        userNameLabel->setAlignment(Qt::AlignCenter);
        passwordLabel = new QLabel(DBInformation);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(30, 260, 61, 16));
        passwordLabel->setFont(font);
        passwordLabel->setAlignment(Qt::AlignCenter);
        driveComboBox = new QComboBox(DBInformation);
        driveComboBox->setObjectName(QStringLiteral("driveComboBox"));
        driveComboBox->setGeometry(QRect(110, 30, 221, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        driveComboBox->setFont(font1);
        driveComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        hostLineEdit = new QLineEdit(DBInformation);
        hostLineEdit->setObjectName(QStringLiteral("hostLineEdit"));
        hostLineEdit->setGeometry(QRect(110, 80, 221, 21));
        databaseLineEdit = new QLineEdit(DBInformation);
        databaseLineEdit->setObjectName(QStringLiteral("databaseLineEdit"));
        databaseLineEdit->setGeometry(QRect(110, 130, 221, 21));
        userNameLineEdit = new QLineEdit(DBInformation);
        userNameLineEdit->setObjectName(QStringLiteral("userNameLineEdit"));
        userNameLineEdit->setGeometry(QRect(110, 220, 221, 21));
        passwordLineEdit = new QLineEdit(DBInformation);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(110, 260, 221, 21));
        cancelPushButton = new QPushButton(DBInformation);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(380, 70, 75, 23));
        okPushButton = new QPushButton(DBInformation);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));
        okPushButton->setGeometry(QRect(380, 30, 75, 23));
        tableLabel = new QLabel(DBInformation);
        tableLabel->setObjectName(QStringLiteral("tableLabel"));
        tableLabel->setGeometry(QRect(30, 180, 61, 16));
        tableLabel->setFont(font);
        tableLabel->setAlignment(Qt::AlignCenter);
        tableLineEdit = new QLineEdit(DBInformation);
        tableLineEdit->setObjectName(QStringLiteral("tableLineEdit"));
        tableLineEdit->setGeometry(QRect(110, 180, 221, 21));
        tableLineEdit->setFrame(false);
        tableLineEdit->setReadOnly(true);
#ifndef QT_NO_SHORTCUT
        driveLabel->setBuddy(driveComboBox);
        hostNameLabel->setBuddy(hostLineEdit);
        dataBaseLabel->setBuddy(databaseLineEdit);
        userNameLabel->setBuddy(userNameLineEdit);
        passwordLabel->setBuddy(passwordLineEdit);
        tableLabel->setBuddy(userNameLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(DBInformation);

        QMetaObject::connectSlotsByName(DBInformation);
    } // setupUi

    void retranslateUi(QWidget *DBInformation)
    {
        DBInformation->setWindowTitle(QApplication::translate("DBInformation", "DBInformation", 0));
#ifndef QT_NO_TOOLTIP
        DBInformation->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        driveLabel->setText(QApplication::translate("DBInformation", "\351\251\261\345\212\250\347\250\213\345\272\217", 0));
        hostNameLabel->setText(QApplication::translate("DBInformation", "\344\270\273\346\234\272\345\220\215", 0));
        dataBaseLabel->setText(QApplication::translate("DBInformation", "\346\225\260\346\215\256\345\272\223\345\220\215", 0));
        userNameLabel->setText(QApplication::translate("DBInformation", "\347\224\250\346\210\267\345\220\215", 0));
        passwordLabel->setText(QApplication::translate("DBInformation", "\345\257\206\347\240\201", 0));
        driveComboBox->clear();
        driveComboBox->insertItems(0, QStringList()
         << QApplication::translate("DBInformation", "QMYSQL (MySQL\351\251\261\345\212\250)", 0)
         << QApplication::translate("DBInformation", "QOCI (Oracle\350\260\203\347\224\250\346\216\245\345\217\243\351\251\261\345\212\250\347\250\213\345\272\217)", 0)
         << QApplication::translate("DBInformation", "QODBC (ODBC\351\251\261\345\212\250\347\250\213\345\272\217\357\274\210\345\214\205\346\213\254Microsoft SQL Server\357\274\211)", 0)
         << QApplication::translate("DBInformation", "QDB2 (IBM DB2)", 0)
         << QApplication::translate("DBInformation", "QIBASE (Borland InterBase\351\251\261\345\212\250\347\250\213\345\272\217)", 0)
         << QApplication::translate("DBInformation", "QPSQL (PostgreSQL\351\251\261\345\212\250)", 0)
         << QApplication::translate("DBInformation", "QSQLITE (SQLite\347\211\210\346\234\2543\346\210\226\346\233\264\351\253\230\347\211\210\346\234\254)", 0)
         << QApplication::translate("DBInformation", "QSQLITE2 (SQLite\347\211\210\346\234\2542)", 0)
         << QApplication::translate("DBInformation", "QTDS (Sybase Adaptive Server)", 0)
         << QString()
        );
        hostLineEdit->setPlaceholderText(QApplication::translate("DBInformation", "127.0.0.1", 0));
        cancelPushButton->setText(QApplication::translate("DBInformation", "\345\217\226\346\266\210", 0));
        okPushButton->setText(QApplication::translate("DBInformation", "\347\241\256\350\256\244", 0));
        tableLabel->setText(QApplication::translate("DBInformation", "\350\241\250\345\220\215", 0));
#ifndef QT_NO_TOOLTIP
        tableLineEdit->setToolTip(QApplication::translate("DBInformation", "\344\270\215\350\203\275\344\277\256\346\224\271\351\241\271", 0));
#endif // QT_NO_TOOLTIP
        tableLineEdit->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class DBInformation: public Ui_DBInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBINFORMATION_H
