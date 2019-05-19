//使QDebug的中文字符能够正常显示
#pragma execution_character_set("utf-8")
#include "ClashOfClansBot.h"
#include <QtWidgets/QApplication>
#include "scrcpy.h"
#include <iostream>
#include <QDebug>


using std::cout;
using std::endl;

void test_push_server();
void test_process();

using namespace capture;


int main(int argc, char *argv[])
{

	qDebug("\n\n--------------------------------------------------------");

	Minicap minicap {};
	minicap.run_server();
	minicap.connnect_cap();
	//test_process();
	//test_push_server();
	QApplication a(argc, argv);
	ClashOfClansBot w;
	w.show();
	return a.exec();
}

void test_process()
{
	QString program = "O:/ADB Driver/adb.exe";
	QStringList arguments;
	arguments << "push" << "B:\\falling\\Downloads\\Compressed\\scrcpy-win64-v1.8\\scrcpy-server.jar"
		<< "/data/local/tmp/";
	QProcess *cmdProcess = new QProcess;
	QObject::connect(cmdProcess, &QProcess::readyRead, [=]() {
		qDebug() << QString::fromLocal8Bit(cmdProcess->readAll());

	});
	cmdProcess->start(program, arguments);
}

void test_push_server()
{
	using namespace capture;


	//delete push_server;
}
