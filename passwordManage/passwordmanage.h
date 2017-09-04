#ifndef PASSWORDMANAGE_H
#define PASSWORDMANAGE_H

#include <QtWidgets/QMainWindow>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QPainter>
#include <QEvent>
#include <QAction>
#include <QCloseEvent>
#include <qstringlistmodel.h>
#include <qsqltablemodel.h>
#include <qdatetime.h>
#include "passworditem.h"
#include "dbinformation.h"
#include "ui_passwordmanage.h"
#include "textinformation.h"
#include "mytablemodel.h"

struct Item {
	int id;
	QString account;
	QString password;
	QString remark;
	QDateTime date;
};
struct Move
{
	bool isPressed;
	QPoint point;
};
struct ChangePushButton
{
	QSize size;
	QFont font;
};
struct Connection
{
	QString dataBaseDriveInfo;//数据库驱动信息
	QString dataBaseDrive;//数据库驱动
	QString hostName;//主机名
	QString dataBaseName;//数据库名
	QString tableName;//表名
	QString userName;//用户名
	QString password;//密码
};
struct Text
{
	QString path;//本地路径
	QString version;//Qt储存版本
	QString fileName;//文件名
};
class passwordManage : public QMainWindow
{
	Q_OBJECT
	friend class DBInformation;
public:
	enum
	{
		passwordManage_Id = 0,
		passwordManage_Account = 1,
		passwordManage_Password = 2,
		passwordManage_Remark = 3,
		passwordManage_Date = 4

	};
	passwordManage(QWidget *parent = 0);
	~passwordManage();
public slots:
void updateSQL();
void updateText();
protected:
	void paintEvent(QPaintEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
	bool eventFilter(QObject *target, QEvent *event);
	void closeEvent(QCloseEvent *event);
private slots:
void checkChange(int statu);
	void toFirst();
	void toNext();
	void toPrevious();
	void toLast();
	void editTextInformation();
	void editDBInformation();
	void addItem();
	void delItem();
	void editItem();
	void delSQL();
	void delText();
	void menuSlot(QPoint point);
	void findRecord();
private:
	//添加item
	void addSqlItem();
	void addTextItem();
	//删除item
	void delSqlItem();
	void delTextItem();
	//编辑item
	void editSqlItem();
	void editTextItem();
	//写入文件
	bool writeFile();
	//初始化
	void Init();
	//写入储存con
	void writeSettings();
	//读取储存con
	void readSettings();
	//创建connect
	void initConnect();
	//注册过滤器
	void initFilter();
	//编辑样式表
	void editStyleSheet();
	//初始化一些控件
	void initUI();
	//改变一些控件
	void changeUI(QObject *obj,QEvent *event);
	//连接数据库
	bool createSQLConnection();
	bool createTextList();
	//创建模型
	void createModel();
	void createTextModel();
	//构建视图
	void createView();
	/**/
	Ui::passwordManageClass ui;
	Move move_;
	ChangePushButton cpb;
	Connection con;//链接数据库信息
	Text text;//本地文件信息
	QSqlTableModel *model;
	DBInformation *dialog;
	passwordItem *dialog2;
	textInformation *dialog3;
	QAction *newAction;
	QAction *editAction;
	QAction *delAction;
	QMenu *menu;
	bool isSQL;//是否是使用数据库
	MyTableModel *textModel;

	QStringList *list;
	QString path;
};

#endif // PASSWORDMANAGE_H
