/********************************************************************************
** Form generated from reading UI file 'passwordmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDMANAGE_H
#define UI_PASSWORDMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passwordManageClass
{
public:
    QWidget *centralWidget;
    QPushButton *deleteDBPushButon;
    QPushButton *addPushButton;
    QPushButton *delPushButton;
    QLabel *passwordLabel;
    QPushButton *editPushButton;
    QPushButton *DBPushButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *updatePushButton;
    QPushButton *minPushButton;
    QPushButton *closePushButton;
    QTableView *view;
    QCheckBox *checkBox;
    QToolButton *findToolButton;
    QPushButton *textPushButton;
    QPushButton *deleteTextPushButon;
    QLineEdit *findLineEdit;
    QComboBox *comboBox;

    void setupUi(QMainWindow *passwordManageClass)
    {
        if (passwordManageClass->objectName().isEmpty())
            passwordManageClass->setObjectName(QStringLiteral("passwordManageClass"));
        passwordManageClass->resize(721, 446);
        centralWidget = new QWidget(passwordManageClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        deleteDBPushButon = new QPushButton(centralWidget);
        deleteDBPushButon->setObjectName(QStringLiteral("deleteDBPushButon"));
        deleteDBPushButon->setGeometry(QRect(30, 400, 75, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        deleteDBPushButon->setFont(font);
        addPushButton = new QPushButton(centralWidget);
        addPushButton->setObjectName(QStringLiteral("addPushButton"));
        addPushButton->setGeometry(QRect(30, 240, 75, 23));
        addPushButton->setFont(font);
        delPushButton = new QPushButton(centralWidget);
        delPushButton->setObjectName(QStringLiteral("delPushButton"));
        delPushButton->setGeometry(QRect(30, 280, 75, 23));
        delPushButton->setFont(font);
        passwordLabel = new QLabel(centralWidget);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setGeometry(QRect(200, 10, 291, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\205\260\344\272\255\350\266\205\347\273\206\351\273\221\347\256\200\344\275\223"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setWeight(50);
        passwordLabel->setFont(font1);
        passwordLabel->setContextMenuPolicy(Qt::NoContextMenu);
        passwordLabel->setAlignment(Qt::AlignCenter);
        editPushButton = new QPushButton(centralWidget);
        editPushButton->setObjectName(QStringLiteral("editPushButton"));
        editPushButton->setGeometry(QRect(30, 320, 75, 23));
        editPushButton->setFont(font);
        DBPushButton = new QPushButton(centralWidget);
        DBPushButton->setObjectName(QStringLiteral("DBPushButton"));
        DBPushButton->setGeometry(QRect(30, 160, 75, 23));
        DBPushButton->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(620, 0, 86, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        updatePushButton = new QPushButton(layoutWidget);
        updatePushButton->setObjectName(QStringLiteral("updatePushButton"));
        updatePushButton->setEnabled(true);
        updatePushButton->setMinimumSize(QSize(24, 24));
        updatePushButton->setMaximumSize(QSize(24, 24));
        updatePushButton->setFlat(true);

        horizontalLayout->addWidget(updatePushButton);

        minPushButton = new QPushButton(layoutWidget);
        minPushButton->setObjectName(QStringLiteral("minPushButton"));
        minPushButton->setMinimumSize(QSize(24, 24));
        minPushButton->setMaximumSize(QSize(24, 24));
        minPushButton->setFlat(true);

        horizontalLayout->addWidget(minPushButton);

        closePushButton = new QPushButton(layoutWidget);
        closePushButton->setObjectName(QStringLiteral("closePushButton"));
        closePushButton->setMinimumSize(QSize(24, 24));
        closePushButton->setMaximumSize(QSize(24, 24));
        closePushButton->setFlat(true);

        horizontalLayout->addWidget(closePushButton);

        view = new QTableView(centralWidget);
        view->setObjectName(QStringLiteral("view"));
        view->setGeometry(QRect(150, 150, 551, 291));
        checkBox = new QCheckBox(centralWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 120, 101, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setWeight(50);
        checkBox->setFont(font2);
        findToolButton = new QToolButton(centralWidget);
        findToolButton->setObjectName(QStringLiteral("findToolButton"));
        findToolButton->setGeometry(QRect(680, 120, 21, 21));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/find"), QSize(), QIcon::Normal, QIcon::Off);
        findToolButton->setIcon(icon);
        textPushButton = new QPushButton(centralWidget);
        textPushButton->setObjectName(QStringLiteral("textPushButton"));
        textPushButton->setGeometry(QRect(30, 200, 75, 23));
        textPushButton->setFont(font);
        deleteTextPushButon = new QPushButton(centralWidget);
        deleteTextPushButon->setObjectName(QStringLiteral("deleteTextPushButon"));
        deleteTextPushButon->setGeometry(QRect(30, 360, 75, 23));
        deleteTextPushButon->setFont(font);
        findLineEdit = new QLineEdit(centralWidget);
        findLineEdit->setObjectName(QStringLiteral("findLineEdit"));
        findLineEdit->setGeometry(QRect(580, 120, 101, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(10);
        findLineEdit->setFont(font3);
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(510, 120, 69, 22));
        comboBox->setFont(font3);
        passwordManageClass->setCentralWidget(centralWidget);

        retranslateUi(passwordManageClass);

        QMetaObject::connectSlotsByName(passwordManageClass);
    } // setupUi

    void retranslateUi(QMainWindow *passwordManageClass)
    {
        passwordManageClass->setWindowTitle(QApplication::translate("passwordManageClass", "passwordManage", 0));
        deleteDBPushButon->setText(QApplication::translate("passwordManageClass", "\345\210\240\351\231\244\346\225\260\346\215\256\345\272\223", 0));
        addPushButton->setText(QApplication::translate("passwordManageClass", "\346\267\273\345\212\240", 0));
        delPushButton->setText(QApplication::translate("passwordManageClass", "\345\210\240\351\231\244", 0));
        passwordLabel->setText(QApplication::translate("passwordManageClass", "\345\257\206\347\240\201\347\256\241\347\220\206\345\267\245\345\205\267", 0));
        editPushButton->setText(QApplication::translate("passwordManageClass", "\344\277\256\346\224\271", 0));
        DBPushButton->setText(QApplication::translate("passwordManageClass", "\346\225\260\346\215\256\345\272\223\344\277\241\346\201\257", 0));
        updatePushButton->setText(QString());
        minPushButton->setText(QString());
        closePushButton->setText(QString());
        checkBox->setText(QApplication::translate("passwordManageClass", "\346\230\257\345\220\246\344\275\277\347\224\250\346\225\260\346\215\256\345\272\223", 0));
#ifndef QT_NO_TOOLTIP
        findToolButton->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        findToolButton->setText(QApplication::translate("passwordManageClass", "...", 0));
        textPushButton->setText(QApplication::translate("passwordManageClass", "\346\226\207\344\273\266\344\277\241\346\201\257", 0));
        deleteTextPushButon->setText(QApplication::translate("passwordManageClass", "\345\210\240\351\231\244\346\226\207\344\273\266", 0));
        findLineEdit->setPlaceholderText(QApplication::translate("passwordManageClass", "\346\220\234\347\264\242", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("passwordManageClass", "\350\264\246\346\210\267", 0)
         << QApplication::translate("passwordManageClass", "\345\257\206\347\240\201", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class passwordManageClass: public Ui_passwordManageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDMANAGE_H
