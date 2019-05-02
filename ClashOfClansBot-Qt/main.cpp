#include "ClashOfClansBot.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ClashOfClansBot w;
	w.show();
	return a.exec();
}
