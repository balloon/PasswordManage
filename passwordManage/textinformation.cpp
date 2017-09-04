#include "textinformation.h"
#include <qmessagebox.h>
#include <qfiledialog.h>
textInformation::textInformation(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	setWindowTitle(u8"�ļ���Ϣ");
	connect(ui.okPushButton, &QPushButton::clicked, this, &textInformation::myClose);
	connect(ui.cancelPushButton, &QPushButton::clicked, this, &textInformation::reject);
	connect(ui.toolButton, &QToolButton::clicked, this, &textInformation::choosePath);
	connect(ui.newPushButton, &QPushButton::clicked, this, &textInformation::newFile);
}
void textInformation::newFile()
{
	QString temp = QFileDialog::getSaveFileName(this, u8"�½������ļ�", "index.dat", "*.dat");
	if (!temp.isEmpty())
	{
		QFileInfo info(temp);
		ui.pathLineEdit->setText(info.absolutePath());
		ui.fileNameLineEdit->setText(info.fileName());
	}
}
void textInformation::choosePath()
{
	QString temp = QFileDialog::getOpenFileName(this, u8"ѡ��·��","","*.dat");
	if (!temp.isEmpty())
	{
		QFileInfo info(temp);
		ui.pathLineEdit->setText(info.absolutePath());
		ui.fileNameLineEdit->setText(info.fileName());
	}
}
void textInformation::updateData()
{
	path = getPath();
	version = getVersion();
	fileName = getFileName();
}
void textInformation::keyReleaseEvent(QKeyEvent *event)
{
	if (event->type() == Qt::Key_Return)
		myClose();
	else if (event->type() == Qt::Key_Escape)
		reject();
}
bool textInformation::isContinue()
{
	bool isPath = ui.pathLineEdit->text().isEmpty();
	bool isVersion = ui.versionLineEdit->text().isEmpty();
	bool isFileName = ui.fileNameLineEdit->text().isEmpty();
	QString temp;
	if (isPath || isVersion || isFileName)
	{
		if (isPath)
			temp += u8"·������Ϊ��\n";
		if (isVersion)
			temp += u8"�汾��Ϣ����Ϊ��\n";
		if (isFileName)
			temp += u8"�ļ�������Ϊ��\n";
		int i = QMessageBox::information(this, u8"��ʾ", QString(u8"%1").arg(temp), QMessageBox::Ok | QMessageBox::Cancel);
		return false;
	}
	else
	{
		QString s = getPath();
		QString s2 = getVersion();
		QString s3 = getFileName();
		if (s == path&&s2 == version&&s3 == fileName)
			return true;
		else
		{
			isChange = 1;
			return true;
		}
	}
}
void textInformation::myClose()
{
	if (isContinue())
	{
		if (isChange)
			emit isTextChange();
		accept();
	}
	
}
textInformation::~textInformation()
{

}
