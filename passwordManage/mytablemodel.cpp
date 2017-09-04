#include "mytablemodel.h"
MyTableModel::MyTableModel(QObject *parent)
	: QAbstractTableModel(parent)
{
	list2 = new QList<item>;


}
void MyTableModel::setList(QStringList* temp)
{
	if (temp->isEmpty())
		return;
	temp->removeAt(temp->count() - 1);//�Ƴ������һ������Ŀ
	QMutableStringListIterator i(*temp);
	while (i.hasNext())
	{
	QStringList text=i.next().split('\t');
	item it;
	int i = 0;
		while (i < 5)
		{
			it.at(i) = text.at(i); ++i;
		}
		*list2 << it;

	}

}
QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole )
		return QVariant();
	if (orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:return QVariant(u8"ID"); break;
		case 1:return QVariant(u8"�˻�"); break;
		case 2:return QVariant(u8"����"); break;
		case 3:return QVariant(u8"��ע"); break;
		case 4:return QVariant(u8"�ϴ��޸�ʱ��"); break;
		default:
			break;
		}
	}
	return QVariant();
}
Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
	
	if (!index.isValid())
		return QAbstractItemModel::flags(index);

	Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
	return flags;
}
int MyTableModel::rowCount(const QModelIndex &parent) const
{
	return list2->count();
}
int MyTableModel::columnCount(const QModelIndex &parent) const
{
	return item::count();
}
QVariant MyTableModel::data(const QModelIndex &index, int role)const
{
	if (!index.isValid())
		return QVariant();
	if (role == Qt::TextAlignmentRole)
		return int(Qt::AlignLeft | Qt::AlignVCenter);
	else if (role == Qt::DisplayRole) {
		item t = list2->at(index.row());//��ȡ��һ��
		QString temp = t.at(index.column());
		return temp;
	}
	return QVariant();
	
}
bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	if (!index.isValid() || index.row() >= rowCount() || index.column() >= columnCount())
		return false;

	(*list2)[index.row()].at(index.column()) = value.toString();
	return true;
}
int MyTableModel::findLikeString(QString status,QString string)
{
	int x = 0;
	int y = 0;
	if (status == u8"�˻�")
		y = 1;

	else if (status == u8"����")
		y = 2;
	QMutableListIterator<item> i(*list2);
	while (i.hasNext())
	{
		QString temp = i.next().at(y);
		if (temp.contains(string))
			break;
		++x;
	}
	return x;
}
MyTableModel::~MyTableModel()
{

}
