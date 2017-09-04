/********************************************************************************
** Form generated from reading UI file 'textinformation.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTINFORMATION_H
#define UI_TEXTINFORMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_textInformation
{
public:
    QLineEdit *pathLineEdit;
    QLabel *pathLabel;
    QToolButton *toolButton;
    QLabel *versionLabel;
    QLabel *fileNameLabel;
    QLineEdit *versionLineEdit;
    QLineEdit *fileNameLineEdit;
    QPushButton *okPushButton;
    QPushButton *cancelPushButton;
    QPushButton *newPushButton;

    void setupUi(QDialog *textInformation)
    {
        if (textInformation->objectName().isEmpty())
            textInformation->setObjectName(QStringLiteral("textInformation"));
        textInformation->resize(397, 265);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        textInformation->setFont(font);
        pathLineEdit = new QLineEdit(textInformation);
        pathLineEdit->setObjectName(QStringLiteral("pathLineEdit"));
        pathLineEdit->setGeometry(QRect(80, 50, 271, 21));
        pathLabel = new QLabel(textInformation);
        pathLabel->setObjectName(QStringLiteral("pathLabel"));
        pathLabel->setGeometry(QRect(13, 50, 61, 20));
        pathLabel->setAlignment(Qt::AlignCenter);
        toolButton = new QToolButton(textInformation);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(350, 50, 21, 21));
        versionLabel = new QLabel(textInformation);
        versionLabel->setObjectName(QStringLiteral("versionLabel"));
        versionLabel->setGeometry(QRect(13, 100, 61, 20));
        versionLabel->setAlignment(Qt::AlignCenter);
        fileNameLabel = new QLabel(textInformation);
        fileNameLabel->setObjectName(QStringLiteral("fileNameLabel"));
        fileNameLabel->setGeometry(QRect(13, 150, 61, 20));
        fileNameLabel->setAlignment(Qt::AlignCenter);
        versionLineEdit = new QLineEdit(textInformation);
        versionLineEdit->setObjectName(QStringLiteral("versionLineEdit"));
        versionLineEdit->setGeometry(QRect(80, 100, 271, 21));
        fileNameLineEdit = new QLineEdit(textInformation);
        fileNameLineEdit->setObjectName(QStringLiteral("fileNameLineEdit"));
        fileNameLineEdit->setGeometry(QRect(80, 150, 271, 21));
        okPushButton = new QPushButton(textInformation);
        okPushButton->setObjectName(QStringLiteral("okPushButton"));
        okPushButton->setGeometry(QRect(20, 210, 75, 23));
        cancelPushButton = new QPushButton(textInformation);
        cancelPushButton->setObjectName(QStringLiteral("cancelPushButton"));
        cancelPushButton->setGeometry(QRect(110, 210, 75, 23));
        newPushButton = new QPushButton(textInformation);
        newPushButton->setObjectName(QStringLiteral("newPushButton"));
        newPushButton->setGeometry(QRect(10, 10, 81, 21));

        retranslateUi(textInformation);

        QMetaObject::connectSlotsByName(textInformation);
    } // setupUi

    void retranslateUi(QDialog *textInformation)
    {
        textInformation->setWindowTitle(QApplication::translate("textInformation", "textInformation", 0));
        pathLabel->setText(QApplication::translate("textInformation", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", 0));
        toolButton->setText(QApplication::translate("textInformation", "...", 0));
        versionLabel->setText(QApplication::translate("textInformation", "\347\211\210\346\234\254\344\277\241\346\201\257\357\274\232", 0));
        fileNameLabel->setText(QApplication::translate("textInformation", "\346\226\207\344\273\266\345\220\215\357\274\232", 0));
        okPushButton->setText(QApplication::translate("textInformation", "\347\241\256\350\256\244", 0));
        cancelPushButton->setText(QApplication::translate("textInformation", "\345\217\226\346\266\210", 0));
        newPushButton->setText(QApplication::translate("textInformation", "\346\226\260\345\273\272\345\202\250\345\255\230\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class textInformation: public Ui_textInformation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTINFORMATION_H
