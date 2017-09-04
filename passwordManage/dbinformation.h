#pragma once

#include <QWidget>
#include <QDialog>
#include "ui_dbinformation.h"
#include <QKeyEvent>
class DBInformation : public QDialog
{
	Q_OBJECT

public:


	DBInformation(QWidget *parent = Q_NULLPTR);
	~DBInformation();
	void updateData();
	bool isContinue();

	QString getDriveName() const ;
	void setDriveName(QString text);

	QString getHostName() const;
	void setHostName(QString text);

	QString getDataBaseName() const;
	void setDataBaseName(QString text);

	QString getUserName() const;
	void setUserName(QString text);

	QString getPassword() const;
	void setPassword(QString text);
	public slots:
	void myClose();
signals:
	void isChange();
protected:
	void keyPressEvent(QKeyEvent *event);
	
private:
	bool change;
	Ui::DBInformation ui;
	const QString table = "passwordManage";
	QString drive;
	QString host;
	QString dataBase;
	QString user;
	QString password;
};
