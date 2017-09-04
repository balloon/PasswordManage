#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <qmessagebox.h>
struct item {
	QString id;
	QString account;
	QString password;
	QString remark;
	QString date;
	static int count()
	{
		return 5;
	}
	QString& at(int i)
	{
		
		if (i == 0)
		{
			QString& t = id;
			return t;
		}
		else if (i == 1)
		{
			QString& t = account;
			return t;
		}
		else if (i == 2)
		{
			QString &t = password;
			return t;
		}
		else if (i == 3)
		{
			QString &t = remark;
			return t;
		}
		else if (i == 4)
		{
			QString &t = date;
			return t;
		}
	}
};
class MyTableModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	MyTableModel(QObject *parent=0);
	~MyTableModel();
	void setList( QStringList* temp);
	int rowCount(const QModelIndex &parent=QModelIndex()) const;
	int columnCount(const QModelIndex &parent= QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role)const;
	bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
	QVariant headerData(int section, Qt::Orientation orientation, int role= Qt::DisplayRole) const;
public:
	int findLikeString(QString,QString);
	bool insertRow(int i)
	{
		if (i > rowCount())
			return false;
		list2->insert(i,item());
		beginResetModel();
		endResetModel();
		return true;
	}
	bool removeRow(int i)
	{

		if (i > rowCount())
			return false;
		list2->removeAt(i);
		beginResetModel();
		endResetModel();
		return true;
	}
	Qt::ItemFlags flags(const QModelIndex &index) const;
	QList<item>* getList()
	{
		return list2;
	}
private:
	QList<item> *list2;
};

#endif // MYTABLEMODEL_H
