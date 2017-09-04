#ifndef TEXTINFORMATION_H
#define TEXTINFORMATION_H

#include <QDialog>
#include "ui_textinformation.h"
#include <QKeyEvent>
#include <QCloseEvent>
class textInformation : public QDialog
{
	Q_OBJECT

public:
	textInformation(QWidget *parent = 0);
	~textInformation();
	bool isContinue();
	void updateData();
	QString getPath()const
	{
		return ui.pathLineEdit->text();
	}
	void setPath(QString text)
	{
		ui.pathLineEdit->setText(text);
	}
	QString getVersion() const
	{
		return ui.versionLineEdit->text();
	}
	void setVersion(QString text)
	{
		return ui.versionLineEdit->setText(text);
	}
	QString getFileName() const
	{
		return ui.fileNameLineEdit->text();
	}
	void setFileName(QString text)
	{
		ui.fileNameLineEdit->setText(text);
		
	}
public slots:
	void myClose();
	void choosePath();
	void newFile();
signals:
	void isTextChange();
protected:
	void keyReleaseEvent(QKeyEvent *event);
private:
	Ui::textInformation ui;
	bool isChange;//信息是否被修改过
	QString path;
	QString version;
	QString fileName;
};

#endif // TEXTINFORMATION_H
