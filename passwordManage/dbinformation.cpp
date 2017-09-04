#include "dbinformation.h"
#include <qmessagebox.h>
DBInformation::DBInformation(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(u8"数据库信息");
	connect(ui.okPushButton, &QPushButton::clicked, this, &DBInformation::myClose);
	connect(ui.cancelPushButton, &QPushButton::clicked, this, &DBInformation::reject);
	ui.tableLineEdit->setText(table);
	ui.tableLineEdit->setEnabled(false);
	ui.tableLineEdit->setFocusPolicy(Qt::NoFocus);
	
}
void DBInformation::updateData()
{
	drive = getDriveName();
	host = getHostName();
	dataBase = getDataBaseName();
	user = getUserName();
	password = getPassword();
}
void DBInformation::keyPressEvent(QKeyEvent *event)
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

void DBInformation::myClose()
{
	if (isContinue())
	{
		if (change)
		{
			emit isChange();
		}
		accept();
	}

}
bool DBInformation::isContinue()
{

	bool isDrive = getDriveName().isEmpty();
	bool isData = getDataBaseName().isEmpty();
	bool isUser = getUserName().isEmpty();
	bool isPassword = getPassword().isEmpty();
	if (isDrive || isData || isUser || isPassword) {
		QString temp;
		if (isDrive)
			temp.append(QString(u8"驱动程序不能为空!\n"));
		if (isData)
			temp.append(QString(u8"数据库值不能为空!\n"));
		if (isUser)
			temp += QString(u8"用户名不能为空!\n");
		if (isPassword)
			temp += QString(u8"密码不能为空!\n");
	int i=	QMessageBox::information(this, u8"提示",tr(u8"%1").arg(temp), QMessageBox::Ok);
	if(i==QMessageBox::Ok)	return false;
	}
	else
	{
		QString t1 = getDriveName();
		QString t2 = getHostName();
		QString t3 = getDataBaseName();
		QString t4 = getUserName();
		QString t5 = getPassword();
		if (t1 == drive&&t2 == host&&t3 == dataBase&&t4 == user&&t5 == password)
			return true;
		else
		{
			change = 1;
			return true;
		}
	}
}
QString DBInformation::getDriveName() const
{
	return ui.driveComboBox->currentText();
}
void DBInformation::setDriveName(QString text)
{
	ui.driveComboBox->setCurrentIndex(ui.driveComboBox->findText(text));
}
QString DBInformation::getHostName() const
{
	if (ui.hostLineEdit->text().isEmpty())
	{
		return ui.hostLineEdit->placeholderText();
	}
	else
	{
		return ui.hostLineEdit->text();
	}
}
void DBInformation::setHostName(QString text)
{
	ui.hostLineEdit->setText(text);
}
QString DBInformation::getDataBaseName() const
{
	return ui.databaseLineEdit->text();
}
void DBInformation::setDataBaseName(QString text)
{
	ui.databaseLineEdit->setText(text);
}
QString DBInformation::getUserName() const
{
	 return ui.userNameLineEdit->text();
}
void DBInformation::setUserName(QString text)
{
	ui.userNameLineEdit->setText(text);
}
QString DBInformation::getPassword() const
{
	return ui.passwordLineEdit->text();
}
void DBInformation::setPassword(QString text)
{
	ui.passwordLineEdit->setText(text);
}
DBInformation::~DBInformation()
{
}
