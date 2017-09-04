/********************************************************************************
** Form generated from reading UI file 'passworditem.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDITEM_H
#define UI_PASSWORDITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passwordItem
{
public:
    QPushButton *firstPushButton;
    QPushButton *previousPushButton;
    QPushButton *nextPushButton;
    QPushButton *lastPushButton;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *idLabel;
    QLineEdit *idLineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *accoutLabel;
    QLineEdit *accountLineEdit;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *remarkLabel;
    QLineEdit *remarkLineEdit;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *dateLabel;
    QDateEdit *dateEdit;
    QLabel *delLabel;

    void setupUi(QDialog *passwordItem)
    {
        if (passwordItem->objectName().isEmpty())
            passwordItem->setObjectName(QStringLiteral("passwordItem"));
        passwordItem->resize(423, 336);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        passwordItem->setFont(font);
        firstPushButton = new QPushButton(passwordItem);
        firstPushButton->setObjectName(QStringLiteral("firstPushButton"));
        firstPushButton->setGeometry(QRect(20, 30, 75, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(10);
        firstPushButton->setFont(font1);
        firstPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        previousPushButton = new QPushButton(passwordItem);
        previousPushButton->setObjectName(QStringLiteral("previousPushButton"));
        previousPushButton->setGeometry(QRect(110, 30, 75, 23));
        previousPushButton->setFont(font1);
        previousPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        nextPushButton = new QPushButton(passwordItem);
        nextPushButton->setObjectName(QStringLiteral("nextPushButton"));
        nextPushButton->setGeometry(QRect(240, 30, 75, 23));
        nextPushButton->setFont(font1);
        nextPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        lastPushButton = new QPushButton(passwordItem);
        lastPushButton->setObjectName(QStringLiteral("lastPushButton"));
        lastPushButton->setGeometry(QRect(330, 30, 75, 23));
        lastPushButton->setFont(font1);
        lastPushButton->setCursor(QCursor(Qt::PointingHandCursor));
        okPushButton = new QPushButton(passwordItem);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));
        okPushButton->setGeometry(QRect(20, 270, 75, 23));
        cancelPushButton = new QPushButton(passwordItem);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(110, 270, 75, 23));
        layoutWidget = new QWidget(passwordItem);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 70, 155, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        idLabel = new QLabel(layoutWidget);
        idLabel->setObjectName(QStringLiteral("idLabel"));
        idLabel->setFont(font);
        idLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(idLabel);

        idLineEdit = new QLineEdit(layoutWidget);
        idLineEdit->setObjectName(QStringLiteral("idLineEdit"));
        idLineEdit->setFrame(false);
        idLineEdit->setReadOnly(true);

        horizontalLayout->addWidget(idLineEdit);

        layoutWidget1 = new QWidget(passwordItem);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 100, 261, 31));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        accoutLabel = new QLabel(layoutWidget1);
        accoutLabel->setObjectName(QStringLiteral("accoutLabel"));
        accoutLabel->setFont(font);
        accoutLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(accoutLabel);

        accountLineEdit = new QLineEdit(layoutWidget1);
        accountLineEdit->setObjectName(QStringLiteral("accountLineEdit"));

        horizontalLayout_2->addWidget(accountLineEdit);

        layoutWidget2 = new QWidget(passwordItem);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 140, 271, 31));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        passwordLabel = new QLabel(layoutWidget2);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setFont(font);
        passwordLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(passwordLabel);

        passwordLineEdit = new QLineEdit(layoutWidget2);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));

        horizontalLayout_3->addWidget(passwordLineEdit);

        layoutWidget3 = new QWidget(passwordItem);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(20, 180, 281, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        remarkLabel = new QLabel(layoutWidget3);
        remarkLabel->setObjectName(QStringLiteral("remarkLabel"));
        remarkLabel->setFont(font);
        remarkLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(remarkLabel);

        remarkLineEdit = new QLineEdit(layoutWidget3);
        remarkLineEdit->setObjectName(QStringLiteral("remarkLineEdit"));

        horizontalLayout_4->addWidget(remarkLineEdit);

        layoutWidget4 = new QWidget(passwordItem);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(20, 220, 188, 27));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        dateLabel = new QLabel(layoutWidget4);
        dateLabel->setObjectName(QStringLiteral("dateLabel"));
        dateLabel->setFont(font);

        horizontalLayout_5->addWidget(dateLabel);

        dateEdit = new QDateEdit(layoutWidget4);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));

        horizontalLayout_5->addWidget(dateEdit);

        delLabel = new QLabel(passwordItem);
        delLabel->setObjectName(QStringLiteral("delLabel"));
        delLabel->setEnabled(true);
        delLabel->setGeometry(QRect(360, 70, 16, 221));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        delLabel->setFont(font2);
        delLabel->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        delLabel->setWordWrap(true);

        retranslateUi(passwordItem);

        QMetaObject::connectSlotsByName(passwordItem);
    } // setupUi

    void retranslateUi(QDialog *passwordItem)
    {
        passwordItem->setWindowTitle(QApplication::translate("passwordItem", "passwordItem", 0));
        firstPushButton->setText(QApplication::translate("passwordItem", "<<First", 0));
        previousPushButton->setText(QApplication::translate("passwordItem", "<Previous", 0));
        nextPushButton->setText(QApplication::translate("passwordItem", "Next>", 0));
        lastPushButton->setText(QApplication::translate("passwordItem", "Last>>", 0));
        okPushButton->setText(QApplication::translate("passwordItem", "\347\241\256\350\256\244", 0));
        cancelPushButton->setText(QApplication::translate("passwordItem", "\345\217\226\346\266\210", 0));
        idLabel->setText(QApplication::translate("passwordItem", "ID", 0));
        accoutLabel->setText(QApplication::translate("passwordItem", "\350\264\246\346\210\267", 0));
        passwordLabel->setText(QApplication::translate("passwordItem", "\345\257\206\347\240\201", 0));
        remarkLabel->setText(QApplication::translate("passwordItem", "\345\244\207\346\263\250", 0));
        dateLabel->setText(QApplication::translate("passwordItem", "\344\270\212\346\254\241\344\277\256\346\224\271\346\227\266\351\227\264", 0));
        delLabel->setText(QApplication::translate("passwordItem", "<html><head/><body><p><span style=\" color:#c82610;\">\347\241\256\345\256\232\346\230\257\345\220\246\345\210\240\351\231\244\346\255\244\346\235\241\350\256\260\345\275\225</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class passwordItem: public Ui_passwordItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDITEM_H
