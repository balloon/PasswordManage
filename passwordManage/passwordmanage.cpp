#include "passwordmanage.h"

#include <qpalette.h>
#include <qcombobox.h>
#include <QMenu>
#include <qsettings.h>
#include <QSqlDatabase>
#include <qmessagebox.h>
passwordManage::passwordManage(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	setAttribute(Qt::WA_TranslucentBackground);
	Init();
	readSettings();
	initUI();
	initFilter();
	if (isSQL)
	{
		createSQLConnection();
		createModel();
	}
	else
	{
		createTextList();
		createTextModel();
	}
	createView();
	initConnect();
	editStyleSheet();
}

void passwordManage::readSettings()
{
	QSettings settings("CON", "passwordManage");
	con.dataBaseDriveInfo = settings.value("driveInfo").toString();
	con.dataBaseDrive = settings.value("drive").toString();
	con.hostName = settings.value("host").toString();
	con.dataBaseName = settings.value("database").toString();
	con.userName = settings.value("user").toString();
	con.password = settings.value("password").toString();
	isSQL = settings.value("isSQL").toBool();
	QSettings s("TEXT", "passwordManage");
	text.path = s.value("path").toString();
	text.version = s.value("version").toString();
	text.fileName = s.value("fileName").toString();
	if (!isSQL)
	{
		//初始化是禁用一些按钮
		ui.checkBox->setChecked(false);
		ui.DBPushButton->setVisible(false);
		ui.deleteDBPushButon->setVisible(false);
	}
	else
	{
		ui.checkBox->setChecked(true);
		ui.textPushButton->setVisible(false);
		ui.deleteTextPushButon->setVisible(false);
	}
}
void passwordManage::writeSettings()
{
	QSettings settings("CON","passwordManage");
	settings.setValue("driveInfo", con.dataBaseDriveInfo);
	settings.setValue("drive", con.dataBaseDrive);
	settings.setValue("host", con.hostName);
	settings.setValue("database", con.dataBaseName);
	settings.setValue("user", con.userName);
	settings.setValue("password", con.password);
	settings.setValue("isSQL", isSQL);
	QSettings s("TEXT", "passwordManage");
	s.setValue("path", text.path);
	s.setValue("version", text.version);
	s.setValue("fileName", text.fileName);
	if (!isSQL)
		writeFile();
}
void passwordManage::initConnect()
{	
	connect(ui.checkBox, &QCheckBox::stateChanged, this, &passwordManage::checkChange);
	connect(newAction, &QAction::triggered, this, &passwordManage::addItem);
	connect(editAction, &QAction::triggered, this, &passwordManage::editItem);
	connect(delAction, &QAction::triggered, this, &passwordManage::delItem);
	connect(ui.closePushButton, &QPushButton::clicked, this, &passwordManage::close);
	connect(ui.minPushButton, &QPushButton::clicked, this, &passwordManage::showMinimized);
	connect(ui.DBPushButton, &QPushButton::clicked, this, &passwordManage::editDBInformation);
	connect(ui.textPushButton, &QPushButton::clicked, this, &passwordManage::editTextInformation);
	connect(ui.addPushButton, &QPushButton::clicked, this, &passwordManage::addItem);
	connect(ui.delPushButton, &QPushButton::clicked, this, &passwordManage::delItem);
	connect(ui.editPushButton, &QPushButton::clicked, this, &passwordManage::editItem);
	connect(ui.deleteDBPushButon, &QPushButton::clicked, this, &passwordManage::delSQL);
	connect(ui.view, &QTableView::customContextMenuRequested, this, &passwordManage::menuSlot);
	connect(ui.view, &QTableView::doubleClicked, this, &passwordManage::editItem);
	connect(ui.deleteTextPushButon, &QPushButton::clicked, this, &passwordManage::delText);
	connect(ui.findToolButton, &QToolButton::clicked, this, &passwordManage::findRecord);
}
void passwordManage::findRecord()
{
	
	QString status = ui.comboBox->currentText();
	QString text = ui.findLineEdit->text();
	if (!text.isEmpty())
	{
		connect(ui.findLineEdit, &QLineEdit::textChanged, this, &passwordManage::findRecord);
	}
	else
	{
		disconnect(ui.findLineEdit, &QLineEdit::textChanged, this, &passwordManage::findRecord);
		if (isSQL)
		{
			model->setFilter("");
			model->select();
		}
		else
		{
			int number = textModel->rowCount();
			for (int i = 0; i < number; ++i)
			{
				ui.view->setRowHidden(i, false);
			}
		}
		return;
	}
	if (!text.isEmpty()&&!status.isEmpty())
	{
		if (isSQL)
		{
			if(status==u8"账户")
			model->setFilter(QObject::tr(u8"账户 like '%%1%'").arg(text));
			else if(status==u8"密码")
				model->setFilter(QObject::tr(u8"密码 like'%%1%'").arg(text));
			model->select();
		}
		else
		{
			int x = textModel->findLikeString(status, text);
			int number = textModel->rowCount();
			for (int i = 0; i < number; ++i)
			{
				if (i != x)
					ui.view->setRowHidden(i,true);
			}
		}
	}
}
void passwordManage::initFilter()
{
	ui.addPushButton->installEventFilter(this);
	ui.DBPushButton->installEventFilter(this);
	ui.deleteDBPushButon->installEventFilter(this);
	ui.delPushButton->installEventFilter(this);
	ui.editPushButton->installEventFilter(this);
	ui.textPushButton->installEventFilter(this);
	ui.deleteTextPushButon->installEventFilter(this);
}
void passwordManage::closeEvent(QCloseEvent *event)
{
	writeSettings();
	event->accept();
}
void passwordManage::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		move_.point = event->pos();
		move_.isPressed = true;
	}
}
bool passwordManage::createTextList()
{
	if (!list)
		list = new QStringList();
	list->clear();
	 path = text.path + (text.path.contains('\'')?('\'') : '/') + text.fileName;
	QFile file(path);
	//打开文件失败
	if (!file.open(QIODevice::ReadWrite))
	{
		QMessageBox::warning(this, u8"警告", u8"打开文件失败，请检查");
		return false;
	}
	QString text = file.readAll();
	if (text.isEmpty())
		return true;
	*list=text.split('\n');
	return true;
}
bool passwordManage::writeFile()
{
	QList<item> *list = textModel->getList();
	QMutableListIterator<item> i(*list);
	QString text;
	while (i.hasNext())
	{
		int x = 0;
		item t = i.next();
		while (x < 5)
		{
			if(x<4)
			t.at(x) += '\t'; 
			else
				t.at(x) += '\n';
			text.append(t.at(x));
			++x;
		}
	}
	QFile file(path);
	if (!file.open(QIODevice::WriteOnly))
	{
		QMessageBox::warning(this, u8"警告", u8"打开文件失败，请检查");
		return false;
	}
	file.write(text.toStdString().c_str());
	return true;
}
bool passwordManage::createSQLConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase(con.dataBaseDrive);
	db.setHostName(con.hostName);
	db.setDatabaseName(con.dataBaseName);
	db.setUserName ( con.userName);
	db.setPassword(con.password);
	if (!db.open())
	{
		QMessageBox::information(this, u8"提示", u8"未能连接到数据库，请检查数据！");
		return false;
	}
	return true;
}
void passwordManage::createTextModel()
{

	textModel = new MyTableModel(this);
	textModel->setList(list);
}
void passwordManage::createModel()
{
	model = new QSqlTableModel(this);
	model->setTable(con.tableName);//选择表
	model->setSort(passwordManage_Id, Qt::AscendingOrder);//按照ID升序排序
	model->setHeaderData(passwordManage_Id, Qt::Horizontal, tr(u8"ID"));
	model->setHeaderData(passwordManage_Account, Qt::Horizontal, tr(u8"账户"));
	model->setHeaderData(passwordManage_Password, Qt::Horizontal, tr(u8"密码"));
	model->setHeaderData(passwordManage_Remark, Qt::Horizontal, tr(u8"备注"));
	model->setHeaderData(passwordManage_Date, Qt::Horizontal, tr(u8"上次修改时间"));
	model->select();

}
void passwordManage::createView()
{
	if (isSQL)
	{
		ui.view->setModel(model);

	}
	else
	{
		ui.view->setModel(textModel);

	}
	//设置每列的距离
	ui.view->setColumnWidth(passwordManage_Id, ui.view->width() / 4 / 4 *1);
	ui.view->setColumnWidth(passwordManage_Account, ui.view->width()/4);
	ui.view->setColumnWidth(passwordManage_Password, ui.view->width() / 4);
	ui.view->setColumnWidth(passwordManage_Remark, ui.view->width() / 4);
	ui.view->setColumnWidth(passwordManage_Date, ui.view->width() / 4/4*2);
	//设置特性
	ui.view->setContextMenuPolicy(Qt::CustomContextMenu);

	ui.view->setSelectionMode(QAbstractItemView::SingleSelection);
	ui.view->setSelectionBehavior(QAbstractItemView::SelectRows);
	//ui.view->setColumnHidden(passwordManage_Id, true);
	//ui.view->resizeColumnsToContents();
	ui.view->setEditTriggers(QAbstractItemView::NoEditTriggers);
	QHeaderView *header = ui.view->horizontalHeader();
	header->setStretchLastSection(true);

}
void passwordManage::updateText()
{
	text.path = dialog3->getPath();
	text.version = dialog3->getVersion();
	text.fileName = dialog3->getFileName();
	createTextList();
	createTextModel();
	createView();
}
void passwordManage::updateSQL()
{
	con.dataBaseDriveInfo = dialog->getDriveName();
	con.dataBaseDrive = con.dataBaseDriveInfo.split(' ').at(0);
	con.hostName = dialog->getHostName();
	con.dataBaseName = dialog->getDataBaseName();
	con.userName = dialog->getUserName();
	con.password = dialog->getPassword();
	createSQLConnection();
	createModel();
	createView();
}
void passwordManage::mouseReleaseEvent(QMouseEvent *event)
{
	move_.isPressed = false;
}
void passwordManage::mouseMoveEvent(QMouseEvent *event)
{
	if (move_.isPressed)
	{
		QPoint pos = event->globalPos();
		move(pos - move_.point);
	}
}
void passwordManage::paintEvent(QPaintEvent *event)
{
	QPainter painter(this);
	QPainterPath path;
	QRectF	rect(this->rect());
	painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
	
	path.addRoundedRect(rect, 20, 20);
	painter.fillPath(path, QColor(255, 255, 255));
	painter.drawRoundedRect(0, 0, width(), height(), 20, 20);
	
}
void passwordManage::editStyleSheet()
{
	setStyleSheet("QTableView{border-bottom-right-radius:0px;}QPushButton{background:rgba(28,134,238,0.5);border-radius:2px;}QPushButton::hover{background:rgba(80,201,195,0.5);border-radius:5px;}");
	ui.passwordLabel->setStyleSheet("QLabel{border-radius:20px;background:rgba(28,134,238,0.5);}");
	ui.closePushButton->setStyleSheet("QPushButton{border-radius:5px;border-image:url(:/images/close);background:rgb(80,201,195);}QPushButton::hover{border-image:url(:/images/close_on);background:rgb(150,222,218);}QPushButton:hover:pressed{border-image:url(:/images/close_pressed);}");
	ui.minPushButton->setStyleSheet("QPushButton{border-radius:5px;border-image:url(:/images/min);background:rgb(80,201,195);}QPushButton::hover{border-image:url(:/images/min_on);background:rgb(150,222,218);}QPushButton:hover:pressed{border-image:url(:/images/min);}");
	ui.updatePushButton->setStyleSheet("QPushButton{border-radius:5px;border-image:url(:/images/update);background:rgb(80,201,195);}QPushButton::hover{border-image:url(:/images/update_on);background:rgb(150,222,218);}QPushButton:hover:pressed{border-image:url(:/images/update);}");
}
void passwordManage::initUI()
{
	QPalette pa;
	pa.setColor(QPalette::WindowText, QColor(199,144,129));
	ui.passwordLabel->setPalette(pa);
	ui.passwordLabel->setGeometry(0, 0, width(), height()/4);
	
}
bool passwordManage::eventFilter(QObject *target, QEvent *e)
{
	if (isSQL) 
	{
		if (target == ui.DBPushButton || target == ui.addPushButton || target == ui.deleteDBPushButon || target == ui.delPushButton ||
		target == ui.editPushButton )
		{
		if (e->type() == QEvent::HoverMove || e->type() == QEvent::HoverLeave)
			{
			changeUI(target, e);
			return true;
			}
		}
	}
	else
	{
		if (target == ui.textPushButton || target == ui.deleteTextPushButon|| target == ui.addPushButton || target == ui.delPushButton ||
			target == ui.editPushButton  )
		{
			if (e->type() == QEvent::HoverMove || e->type() == QEvent::HoverLeave)
			{
				changeUI(target, e);
				return true;
			}
		}
	}
	return QMainWindow::eventFilter(target, e);
}
void passwordManage::changeUI(QObject *obj, QEvent *event)
{
	if (event->type() == QEvent::HoverMove)
	{
		QPushButton* object = static_cast<QPushButton*>(obj);
		QPalette pa;
		pa.setColor(QPalette::ButtonText,Qt::white);
		object->setPalette(pa);
		object->setFont(QFont(u8"微软雅黑", 10, QFont::Bold));
		object->resize(QSize(cpb.size.width()*1.5, cpb.size.height()*1.5));
	}
	else
	{
		QPushButton* object = static_cast<QPushButton*>(obj);
		QPalette pa;
		pa.setColor(QPalette::ButtonText, Qt::black);
		object->setPalette(pa);
		object->setFont(cpb.font);
		object->resize(cpb.size.width(), cpb.size.height());
	}
}
void passwordManage::Init()
{
	isSQL = false;//第一次设置为false;
	cpb.size = ui.addPushButton->size();
	cpb.font = ui.addPushButton->font();
	con.tableName = "passwordManage";
	dialog = 0;
	dialog2 = 0;
	dialog3 = 0;
	list = 0;
	model = 0;
	textModel = 0;
	newAction = new QAction(this);
	newAction->setText(u8"新建记录");
	editAction = new QAction(this);
	editAction->setText(u8"编辑记录");
	delAction = new QAction(this);
	delAction->setText(u8"删除记录");
	menu = new QMenu(ui.view);
	menu->addAction(newAction);
	menu->addAction(delAction);
	menu->addAction(editAction);

}
void passwordManage::editTextInformation()
{
	if (!dialog3)
	{
		dialog3 = new textInformation(this);
		connect(dialog3, &textInformation::isTextChange, this, &passwordManage::updateText);
	}
	dialog3->setPath(text.path);
	dialog3->setVersion(text.version);
	dialog3->setFileName(text.fileName);
	dialog3->updateData();
	if (dialog3->exec())
	{
		;
	}
}
void passwordManage::editDBInformation()
{

	if (!dialog)
	{
		dialog = new DBInformation(this);
		connect(dialog, &DBInformation::isChange, this, &passwordManage::updateSQL);
	}
	dialog->setDriveName(con.dataBaseDriveInfo);
	dialog->setHostName(con.hostName);
	dialog->setDataBaseName(con.dataBaseName);
	dialog->setUserName(con.userName);
	dialog->setPassword(con.password);
	dialog->updateData();
	if (dialog->exec())
	{
		;
	}

}
void passwordManage::addItem()
{
	if (isSQL)
		addSqlItem();
	else
		addTextItem();
}
void passwordManage::delItem()
{
	if (isSQL)
		delSqlItem();
	else
		delTextItem();
}
void passwordManage::addTextItem()
{
	if (!dialog2)
	{
		dialog2 = new passwordItem(this);
		connect(dialog2, &passwordItem::toFirst, this, &passwordManage::toFirst);
		connect(dialog2, &passwordItem::toPrevious, this, &passwordManage::toPrevious);
		connect(dialog2, &passwordItem::toNext, this, &passwordManage::toNext);
		connect(dialog2, &passwordItem::toLast, this, &passwordManage::toLast);
	}
	dialog2->Init();
	dialog2->setDelVisible(false);
	dialog2->setItemVisible(true, false);
	int rowNumber = textModel->rowCount();
	int id=0;
	if (rowNumber > 0)
	{
		QString s=textModel->data(textModel->index(textModel->rowCount() - 1, passwordManage_Id),Qt::DisplayRole).toString();
		id = s.toInt() + 1;
	}
	else
		id = 1;

	//添加记录初始化id和当前时间
	dialog2->setId(id);
	QDateTime time = QDateTime::currentDateTime();
	dialog2->setDate(time);
	if (dialog2->exec())
	{
		item item;
		item.id = QString::number(id,10);//int 转 int 
		item.account = dialog2->getAccount();
		item.password = dialog2->getPassword();
		item.remark = dialog2->getRemark();
		item.date = dialog2->getDate().toString("yyyy-MM-dd");
		textModel->insertRow(rowNumber);
		textModel->setData(textModel->index(rowNumber, passwordManage_Id), item.id);
		textModel->setData(textModel->index(rowNumber, passwordManage_Account), item.account);
		textModel->setData(textModel->index(rowNumber, passwordManage_Password), item.password);
		textModel->setData(textModel->index(rowNumber, passwordManage_Remark), item.remark);
		textModel->setData(textModel->index(rowNumber, passwordManage_Date), item.date);
	}
}
void passwordManage::addSqlItem()
{
	if (!dialog2)
	{
	dialog2 = new passwordItem(this);
	connect(dialog2, &passwordItem::toFirst, this, &passwordManage::toFirst);
	connect(dialog2, &passwordItem::toPrevious, this, &passwordManage::toPrevious);
	connect(dialog2, &passwordItem::toNext, this, &passwordManage::toNext);
	connect(dialog2, &passwordItem::toLast, this, &passwordManage::toLast);
	}
	dialog2->Init();
	dialog2->setDelVisible(false);
	dialog2->setItemVisible(true,false);
	int rowNumber = model->rowCount();
	int id;
	if (rowNumber > 0)
	{
		id = model->data(model->index(model->rowCount() - 1, passwordManage_Id)).toInt() + 1;
	}
	else
		id = 1;
	//添加记录初始化id和当前时间
	dialog2->setId(id);
	QDateTime time = QDateTime::currentDateTime();
	dialog2->setDate(time);

	if (dialog2->exec())
	{
		Item item;
		item.id = id;
		item.account = dialog2->getAccount();
		item.password = dialog2->getPassword();
		item.remark = dialog2->getRemark();
		item.date = dialog2->getDate();
		model->insertRow(rowNumber);
		model->setData(model->index(rowNumber, passwordManage_Id), item.id);
		model->setData(model->index(rowNumber, passwordManage_Account), item.account);
		model->setData(model->index(rowNumber, passwordManage_Password), item.password);
		model->setData(model->index(rowNumber, passwordManage_Remark), item.remark);
		model->setData(model->index(rowNumber, passwordManage_Date), item.date);
		model->submitAll();
	}
}
void passwordManage::delSqlItem()
{
	if (!dialog2)
	{
		dialog2 = new passwordItem(this);
		connect(dialog2, &passwordItem::toFirst, this, &passwordManage::toFirst);
		connect(dialog2, &passwordItem::toPrevious, this, &passwordManage::toPrevious);
		connect(dialog2, &passwordItem::toNext, this, &passwordManage::toNext);
		connect(dialog2, &passwordItem::toLast, this, &passwordManage::toLast);
	}
	dialog2->Init();
	dialog2->setDelVisible(true);
	dialog2->setItemVisible(false,true);
	int rowNumber = ui.view->currentIndex().row();
	if (rowNumber == -1)
	{
		QMessageBox::information(this, u8"提示", u8"当前并未有选中项", QMessageBox::Ok | QMessageBox::Cancel);
	}
	else
	{
		Item item;
		item.id = model->data(model->index(rowNumber, passwordManage_Id)).toInt();
		item.account = model->data(model->index(rowNumber, passwordManage_Account)).toString();
		item.password = model->data(model->index(rowNumber, passwordManage_Password)).toString();
		item.remark = model->data(model->index(rowNumber, passwordManage_Remark)).toString();
		item.date = model->data(model->index(rowNumber, passwordManage_Date)).toDateTime();
		dialog2->setId(item.id);
		dialog2->setAccount(item.account);
		dialog2->setPassword(item.password);
		dialog2->setRemark(item.remark);
		dialog2->setDate(item.date);
		if (dialog2->exec())
		{
			rowNumber = ui.view->currentIndex().row();
			model->removeRow(rowNumber);
			model->submitAll();
			model->select();
			ui.view->setModel(model);
		}
	}
}
void passwordManage::delTextItem()
{
	if (!dialog2)
	{
		dialog2 = new passwordItem(this);
		connect(dialog2, &passwordItem::toFirst, this, &passwordManage::toFirst);
		connect(dialog2, &passwordItem::toPrevious, this, &passwordManage::toPrevious);
		connect(dialog2, &passwordItem::toNext, this, &passwordManage::toNext);
		connect(dialog2, &passwordItem::toLast, this, &passwordManage::toLast);
	}
	dialog2->Init();
	dialog2->setDelVisible(true);
	dialog2->setItemVisible(false, true);
	int rowNumber = ui.view->currentIndex().row();
	if (rowNumber == -1)
	{
		QMessageBox::information(this, u8"提示", u8"当前并未有选中项", QMessageBox::Ok | QMessageBox::Cancel);
	}
	else
	{
		Item item;
		item.id = textModel->data(textModel->index(rowNumber, passwordManage_Id),Qt::DisplayRole).toInt();
		item.account = textModel->data(textModel->index(rowNumber, passwordManage_Account), Qt::DisplayRole).toString();
		item.password = textModel->data(textModel->index(rowNumber, passwordManage_Password), Qt::DisplayRole).toString();
		item.remark = textModel->data(textModel->index(rowNumber, passwordManage_Remark), Qt::DisplayRole).toString();
		item.date = textModel->data(textModel->index(rowNumber, passwordManage_Date),Qt::DisplayRole).toDateTime();
		dialog2->setId(item.id);
		dialog2->setAccount(item.account);
		dialog2->setPassword(item.password);
		dialog2->setRemark(item.remark);
		dialog2->setDate(item.date);
		if (dialog2->exec())
		{
			rowNumber = ui.view->currentIndex().row();
			textModel->removeRow(rowNumber);
			textModel->submit();
		}
	}
}
void passwordManage::editItem()
{
	if (isSQL)
		editSqlItem();
	else
		editTextItem();

}
void passwordManage::editSqlItem()
{
	if (!dialog2)
	{
		dialog2 = new passwordItem(this);
		connect(dialog2, &passwordItem::toFirst, this, &passwordManage::toFirst);
		connect(dialog2, &passwordItem::toPrevious, this, &passwordManage::toPrevious);
		connect(dialog2, &passwordItem::toNext, this, &passwordManage::toNext);
		connect(dialog2, &passwordItem::toLast, this, &passwordManage::toLast);
	}
	dialog2->Init();
	dialog2->setDelVisible(false);
	dialog2->setItemVisible(true,true);
	int rowNumber = ui.view->currentIndex().row();
	if (rowNumber == -1)
	{
		QMessageBox::information(this, u8"提示", u8"当前并未有选中项", QMessageBox::Ok | QMessageBox::Cancel);
	}
	else
	{
		Item item;
		item.id = model->data(model->index(rowNumber, passwordManage_Id)).toInt();
		item.account = model->data(model->index(rowNumber, passwordManage_Account)).toString();
		item.password = model->data(model->index(rowNumber, passwordManage_Password)).toString();
		item.remark = model->data(model->index(rowNumber, passwordManage_Remark)).toString();
		//item.date = model->data(model->index(rowNumber, passwordManage_Date)).toDateTime();
		dialog2->setId(item.id);
		dialog2->setAccount(item.account);
		dialog2->setPassword(item.password);
		dialog2->setRemark(item.remark);
		QDateTime time = QDateTime::currentDateTime();
		dialog2->setDate(time);
		if (dialog2->exec())
		{
			rowNumber = ui.view->currentIndex().row();
			Item item;
			item.account = dialog2->getAccount();
			item.password = dialog2->getPassword();
			item.remark = dialog2->getRemark();
			item.date = dialog2->getDate();
			//model->setData(model->index(rowNumber, passwordManage_Id), item.id);
			model->setData(model->index(rowNumber, passwordManage_Account), item.account);
			model->setData(model->index(rowNumber, passwordManage_Password), item.password);
			model->setData(model->index(rowNumber, passwordManage_Remark), item.remark);
			model->setData(model->index(rowNumber, passwordManage_Date), item.date);
			model->submitAll();
		}
	}
}
void passwordManage::editTextItem()
{
	if (!dialog2)
	{
		dialog2 = new passwordItem(this);
		connect(dialog2, &passwordItem::toFirst, this, &passwordManage::toFirst);
		connect(dialog2, &passwordItem::toPrevious, this, &passwordManage::toPrevious);
		connect(dialog2, &passwordItem::toNext, this, &passwordManage::toNext);
		connect(dialog2, &passwordItem::toLast, this, &passwordManage::toLast);
	}
	dialog2->Init();
	dialog2->setDelVisible(false);
	dialog2->setItemVisible(true, true);
	int rowNumber = ui.view->currentIndex().row();
	if (rowNumber == -1)
	{
		QMessageBox::information(this, u8"提示", u8"当前并未有选中项", QMessageBox::Ok | QMessageBox::Cancel);
	}
	else
	{
		Item t;
		t.id =textModel->data(textModel->index(rowNumber, passwordManage_Id),Qt::DisplayRole).toInt();
		t.account = textModel->data(textModel->index(rowNumber, passwordManage_Account), Qt::DisplayRole).toString();
		t.password = textModel->data(textModel->index(rowNumber, passwordManage_Password), Qt::DisplayRole).toString();
		t.remark = textModel->data(textModel->index(rowNumber, passwordManage_Remark), Qt::DisplayRole).toString();
		//t.date = textModel->data(textModel->index(rowNumber, passwordManage_Date),Qt::DisplayRole).toDateTime();
		dialog2->setId(t.id);
		dialog2->setAccount(t.account);
		dialog2->setPassword(t.password);
		dialog2->setRemark(t.remark);
		QDateTime time = QDateTime::currentDateTime();
		dialog2->setDate(time);
		if (dialog2->exec())
		{
			rowNumber = ui.view->currentIndex().row();
			item t2;
			t2.account = dialog2->getAccount();
			t2.password = dialog2->getPassword();
			t2.remark = dialog2->getRemark();
			t2.date = dialog2->getDate().toString("yyyy-MM-dd");
			//model->setData(model->index(rowNumber, passwordManage_Id), item.id);
			textModel->setData(textModel->index(rowNumber, passwordManage_Account),t2.account);
			textModel->setData(textModel->index(rowNumber, passwordManage_Password), t2.password);
			textModel->setData(textModel->index(rowNumber, passwordManage_Remark), t2.remark);
			textModel->setData(textModel->index(rowNumber, passwordManage_Date), t2.date);
			textModel->submit();
		}
	}
}
void passwordManage::delSQL()
{
	int x = QMessageBox::warning(this, u8"严重警告", u8"你确定要删除这个数据库中的所有记录！！！", QMessageBox::Ok | QMessageBox::Cancel);
	if (x == QMessageBox::Ok)
	{
		int rowNumber = model->rowCount();
		for (int i = 0; i < rowNumber; ++i)
			model->removeRow(i);
		model->submitAll();
		model->select();
		ui.view->setModel(model);
	}
}
void passwordManage::delText()
{
	int x = QMessageBox::warning(this, u8"严重警告", u8"你确定要删除这个文件中的所有记录！！！", QMessageBox::Ok | QMessageBox::Cancel);
	if (x == QMessageBox::Ok)
	{
		QFile file(path);
		if (!file.open(QIODevice::ReadWrite))
		{
			QMessageBox::warning(this, u8"警告", u8"打开文件失败，请检查");
			return;
		}
		file.resize(0);
		createTextList();
		createTextModel();
		createView();
	}
}
void passwordManage::toFirst()
{
	if (isSQL)
	{
		ui.view->setCurrentIndex(model->index(0, passwordManage_Id));
		Item item;
		item.id = model->data(model->index(0, passwordManage_Id)).toInt();
		item.account = model->data(model->index(0, passwordManage_Account)).toString();
		item.password = model->data(model->index(0, passwordManage_Password)).toString();
		item.remark = model->data(model->index(0, passwordManage_Remark)).toString();
		item.date = model->data(model->index(0, passwordManage_Date)).toDateTime();
		dialog2->setId(item.id);
		dialog2->setAccount(item.account);
		dialog2->setPassword(item.password);
		dialog2->setRemark(item.remark);
		dialog2->setDate(item.date);
	}
	else
	{
		ui.view->setCurrentIndex(textModel->index(0, passwordManage_Id));
		Item item;
		item.id = textModel->data(textModel->index(0, passwordManage_Id),Qt::DisplayRole).toInt();
		item.account = textModel->data(textModel->index(0, passwordManage_Account), Qt::DisplayRole).toString();
		item.password = textModel->data(textModel->index(0, passwordManage_Password), Qt::DisplayRole).toString();
		item.remark = textModel->data(textModel->index(0, passwordManage_Remark), Qt::DisplayRole).toString();
		item.date = textModel->data(textModel->index(0, passwordManage_Date), Qt::DisplayRole).toDateTime();
		dialog2->setId(item.id);
		dialog2->setAccount(item.account);
		dialog2->setPassword(item.password);
		dialog2->setRemark(item.remark);
		dialog2->setDate(item.date);
	}
}
void passwordManage::toPrevious()
{
	int rowNumber = ui.view->currentIndex().row()-1;
	if (rowNumber != -1)
	{
		if (isSQL)
		{
			ui.view->setCurrentIndex(model->index(rowNumber, passwordManage_Id));
			Item item;
			item.id = model->data(model->index(rowNumber, passwordManage_Id)).toInt();
			item.account = model->data(model->index(rowNumber, passwordManage_Account)).toString();
			item.password = model->data(model->index(rowNumber, passwordManage_Password)).toString();
			item.remark = model->data(model->index(rowNumber, passwordManage_Remark)).toString();
			item.date = model->data(model->index(rowNumber, passwordManage_Date)).toDateTime();
			dialog2->setId(item.id);
			dialog2->setAccount(item.account);
			dialog2->setPassword(item.password);
			dialog2->setRemark(item.remark);
			dialog2->setDate(item.date);
		}
		else
		{
			ui.view->setCurrentIndex(textModel->index(rowNumber, passwordManage_Id));
			Item item;
			item.id = textModel->data(textModel->index(rowNumber, passwordManage_Id), Qt::DisplayRole).toInt();
			item.account = textModel->data(textModel->index(rowNumber, passwordManage_Account), Qt::DisplayRole).toString();
			item.password = textModel->data(textModel->index(rowNumber, passwordManage_Password), Qt::DisplayRole).toString();
			item.remark = textModel->data(textModel->index(rowNumber, passwordManage_Remark), Qt::DisplayRole).toString();
			item.date = textModel->data(textModel->index(rowNumber, passwordManage_Date), Qt::DisplayRole).toDateTime();
			dialog2->setId(item.id);
			dialog2->setAccount(item.account);
			dialog2->setPassword(item.password);
			dialog2->setRemark(item.remark);
			dialog2->setDate(item.date);
		}
	}
}
void passwordManage::toNext()
{
	int rowNumber = ui.view->currentIndex().row()+1;
	int maxRow;
	if (isSQL)
		maxRow = model->rowCount();
	else
		maxRow = textModel->rowCount();
	if (rowNumber != maxRow)
	{
		if (isSQL)
		{
			ui.view->setCurrentIndex(model->index(rowNumber, passwordManage_Id));
			Item item;
			item.id = model->data(model->index(rowNumber, passwordManage_Id)).toInt();
			item.account = model->data(model->index(rowNumber, passwordManage_Account)).toString();
			item.password = model->data(model->index(rowNumber, passwordManage_Password)).toString();
			item.remark = model->data(model->index(rowNumber, passwordManage_Remark)).toString();
			item.date = model->data(model->index(rowNumber, passwordManage_Date)).toDateTime();
			dialog2->setId(item.id);
			dialog2->setAccount(item.account);
			dialog2->setPassword(item.password);
			dialog2->setRemark(item.remark);
			dialog2->setDate(item.date);
		}
		else
		{
			ui.view->setCurrentIndex(textModel->index(rowNumber, passwordManage_Id));
			Item item;
			item.id = textModel->data(textModel->index(rowNumber, passwordManage_Id), Qt::DisplayRole).toInt();
			item.account = textModel->data(textModel->index(rowNumber, passwordManage_Account), Qt::DisplayRole).toString();
			item.password = textModel->data(textModel->index(rowNumber, passwordManage_Password), Qt::DisplayRole).toString();
			item.remark = textModel->data(textModel->index(rowNumber, passwordManage_Remark), Qt::DisplayRole).toString();
			item.date = textModel->data(textModel->index(rowNumber, passwordManage_Date), Qt::DisplayRole).toDateTime();
			dialog2->setId(item.id);
			dialog2->setAccount(item.account);
			dialog2->setPassword(item.password);
			dialog2->setRemark(item.remark);
			dialog2->setDate(item.date);
		}
	}

}
void passwordManage::toLast() 
{
	
	if (isSQL)
	{
		int rowNumber = model->rowCount() - 1;
		ui.view->setCurrentIndex(model->index(rowNumber, passwordManage_Id));
		Item item;
		item.id = model->data(model->index(rowNumber, passwordManage_Id)).toInt();
		item.account = model->data(model->index(rowNumber, passwordManage_Account)).toString();
		item.password = model->data(model->index(rowNumber, passwordManage_Password)).toString();
		item.remark = model->data(model->index(rowNumber, passwordManage_Remark)).toString();
		item.date = model->data(model->index(rowNumber, passwordManage_Date)).toDateTime();
		dialog2->setId(item.id);
		dialog2->setAccount(item.account);
		dialog2->setPassword(item.password);
		dialog2->setRemark(item.remark);
		dialog2->setDate(item.date);
	}
	else
	{
		int rowNumber = textModel->rowCount() - 1;
		ui.view->setCurrentIndex(textModel->index(rowNumber, passwordManage_Id));
		Item item;
		item.id = textModel->data(textModel->index(rowNumber, passwordManage_Id), Qt::DisplayRole).toInt();
		item.account = textModel->data(textModel->index(rowNumber, passwordManage_Account), Qt::DisplayRole).toString();
		item.password = textModel->data(textModel->index(rowNumber, passwordManage_Password), Qt::DisplayRole).toString();
		item.remark = textModel->data(textModel->index(rowNumber, passwordManage_Remark), Qt::DisplayRole).toString();
		item.date = textModel->data(textModel->index(rowNumber, passwordManage_Date), Qt::DisplayRole).toDateTime();
		dialog2->setId(item.id);
		dialog2->setAccount(item.account);
		dialog2->setPassword(item.password);
		dialog2->setRemark(item.remark);
		dialog2->setDate(item.date);
	}
}
void passwordManage::menuSlot(QPoint point)
{
QModelIndex p=	ui.view->indexAt(point);
if (p.isValid())
{
	menu->exec(QCursor::pos());// 菜单出现的位置为当前鼠标的位置
}
}
void passwordManage::checkChange(int statu)
{
	if (statu == Qt::Unchecked)//没有选中，本地文件存储
	{
		isSQL = false;
		ui.DBPushButton->setVisible(false);
		ui.deleteDBPushButon->setVisible(false);
		ui.textPushButton->setVisible(true);
		ui.deleteTextPushButon->setVisible(true);
		createTextList();
		createTextModel();
		createView();
	}
	else if (statu == Qt::Checked)
	{
		writeFile();
		isSQL =true;
		ui.DBPushButton->setVisible(true);
		ui.deleteDBPushButon->setVisible(true);
		ui.textPushButton->setVisible(false);
		ui.deleteTextPushButon->setVisible(false);
		createSQLConnection();
		createModel();
		createView();
	}
}
passwordManage::~passwordManage()
{
	delete model;
	delete textModel;
	delete dialog;
	delete dialog2;
	delete dialog3;
}
