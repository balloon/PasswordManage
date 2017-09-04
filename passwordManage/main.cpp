#include "passwordmanage.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	passwordManage w;
	w.show();
	return a.exec();
}
