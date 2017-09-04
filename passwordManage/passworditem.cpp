#include "passworditem.h"
#include <qmessagebox.h>
passwordItem::passwordItem(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(u8"记录信息");
	
	connect(ui.okPushButton, &QPushButton::clicked, this, &passwordItem::myClose);
	connect(ui.cancelPushButton, &QPushButton::clicked, this, &passwordItem::reject);
	connect(ui.firstPushButton, &QPushButton::clicked, this, &passwordItem::toFirst);
	connect(ui.previousPushButton, &QPushButton::clicked, this, &passwordItem::toPrevious);
	connect(ui.nextPushButton, &QPushButton::clicked, this, &passwordItem::toNext);
	connect(ui.lastPushButton, &QPushButton::clicked, this, &passwordItem::toLast);
}
void passwordItem::myClose()
{
	if (isContinue())
	{
		accept();
	}

}

bool passwordItem::isContinue()
{
	bool isAccount = ui.accountLineEdit->text().isEmpty();
	bool isPassword = ui.passwordLineEdit->text().isEmpty();
	bool isDate = ui.dateEdit->text().isEmpty();
	if (isAccount || isPassword || isDate)
	{
		QString temp;
		if (isAccount)
			temp += u8"账户不能为空值\n";
		if (isPassword)
			temp += u8"密码不能为空值\n";
		if (isDate)
			temp += u8"密码不能为空值\n";
	int i=	QMessageBox::information(this, u8"提示", tr("%1").arg(temp), QMessageBox::Ok);
	if (i == QMessageBox::Ok)
		return false;
	}
	return true;
}
void passwordItem::Init()
{
	ui.accountLineEdit->setText("");
	ui.passwordLineEdit->setText("");
	ui.remarkLineEdit->setText("");
	ui.dateEdit->setDateTime(QDateTime());
}
void passwordItem::keyPressEvent(QKeyEvent *event)
{
	if (event->key() == Qt::Key_Return)
	{
		myClose();
	}
	else if (event->key() == Qt::Key_Escape)
	{
		reject();
	}
	QDialog::keyPressEvent(event);
}
void passwordItem::setDelVisible(bool is)
{
if(is)
ui.delLabel->setVisible(true);
else
ui.delLabel->setVisible(false);
}
void passwordItem::setItemVisible(bool is,bool is2)
{
	if (!is) {

		ui.idLineEdit->setEnabled(false);

		ui.accountLineEdit->setEnabled(false);

		ui.passwordLineEdit->setEnabled(false);


		ui.remarkLineEdit->setEnabled(false);


		ui.dateEdit->setEnabled(false);

	}
	else
	{

		ui.idLineEdit->setEnabled(true);

		ui.accountLineEdit->setEnabled(true);

		ui.passwordLineEdit->setEnabled(true);


		ui.remarkLineEdit->setEnabled(true);


		ui.dateEdit->setEnabled(true);
	}
	if (!is2)
	{
		ui.firstPushButton->setEnabled(false);
		ui.previousPushButton->setEnabled(false);
		ui.nextPushButton->setEnabled(false);
		ui.lastPushButton->setEnabled(false);
	}
	else
	{
		ui.firstPushButton->setEnabled(true);
		ui.previousPushButton->setEnabled(true);
		ui.nextPushButton->setEnabled(true);
		ui.lastPushButton->setEnabled(true);
	}
}
int passwordItem::getId() const
{
	return ui.idLineEdit->text().toInt();
}
void passwordItem::setId(int x) 
{
	ui.idLineEdit->setText(tr("%1").arg(x));
}
QString passwordItem::getAccount() const
{
	return ui.accountLineEdit->text();
}
void passwordItem::setAccount(QString text)
{
	ui.accountLineEdit->setText(text);
}
QString passwordItem::getPassword()const
{
	return ui.passwordLineEdit->text();
}
void passwordItem::setPassword(QString text)
{
	ui.passwordLineEdit->setText(text);
}
QString passwordItem::getRemark()const
{
	return ui.remarkLineEdit->text();
}
void passwordItem::setRemark(QString text)
{
	ui.remarkLineEdit->setText(text);
}
QDateTime passwordItem::getDate()const
{
	return ui.dateEdit->dateTime();
}
void passwordItem::setDate(QDateTime date) 
{
	ui.dateEdit->setDateTime(date);
}
passwordItem::~passwordItem()
{

}
