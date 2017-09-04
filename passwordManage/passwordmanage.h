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
	QString dataBaseDriveInfo;//���ݿ�������Ϣ
	QString dataBaseDrive;//���ݿ�����
	QString hostName;//������
	QString dataBaseName;//���ݿ���
	QString tableName;//����
	QString userName;//�û���
	QString password;//����
};
struct Text
{
	QString path;//����·��
	QString version;//Qt����汾
	QString fileName;//�ļ���
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
	//���item
	void addSqlItem();
	void addTextItem();
	//ɾ��item
	void delSqlItem();
	void delTextItem();
	//�༭item
	void editSqlItem();
	void editTextItem();
	//д���ļ�
	bool writeFile();
	//��ʼ��
	void Init();
	//д�봢��con
	void writeSettings();
	//��ȡ����con
	void readSettings();
	//����connect
	void initConnect();
	//ע�������
	void initFilter();
	//�༭��ʽ��
	void editStyleSheet();
	//��ʼ��һЩ�ؼ�
	void initUI();
	//�ı�һЩ�ؼ�
	void changeUI(QObject *obj,QEvent *event);
	//�������ݿ�
	bool createSQLConnection();
	bool createTextList();
	//����ģ��
	void createModel();
	void createTextModel();
	//������ͼ
	void createView();
	/**/
	Ui::passwordManageClass ui;
	Move move_;
	ChangePushButton cpb;
	Connection con;//�������ݿ���Ϣ
	Text text;//�����ļ���Ϣ
	QSqlTableModel *model;
	DBInformation *dialog;
	passwordItem *dialog2;
	textInformation *dialog3;
	QAction *newAction;
	QAction *editAction;
	QAction *delAction;
	QMenu *menu;
	bool isSQL;//�Ƿ���ʹ�����ݿ�
	MyTableModel *textModel;

	QStringList *list;
	QString path;
};

#endif // PASSWORDMANAGE_H
