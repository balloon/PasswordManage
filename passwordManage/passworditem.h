#ifndef PASSWORDITEM_H
#define PASSWORDITEM_H

#include <QDialog>
#include "ui_passworditem.h"
#include <QCloseEvent>
#include <QKeyEvent>
class passwordItem : public QDialog
{
	Q_OBJECT

public:
	passwordItem(QWidget *parent = 0);
	~passwordItem();
	bool getStatus() const
	{
		if (ui.dateLabel->isVisible())
		{
			return true;
		}
		else
			return false;
	}
	bool isContinue();
	void Init();
	void setDelVisible(bool is);
	void setItemVisible(bool is,bool is2);
	int getId() const;
	void setId(int x);
	QString getAccount() const;
	void setAccount(QString text);
	QString getPassword() const;
	void setPassword(QString text);
	QString getRemark() const;
	void setRemark(QString text);
	QDateTime getDate() const;
	void setDate(QDateTime date);
signals:
	void toFirst();
	void toNext();
	void toPrevious();
	void toLast();
	public slots:
void myClose();
protected:
	
	
	void keyPressEvent(QKeyEvent *event);
private:
	Ui::passwordItem ui;
};

#endif // PASSWORDITEM_H
