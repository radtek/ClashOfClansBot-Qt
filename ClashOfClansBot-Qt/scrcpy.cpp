#include "scrcpy.h"

using namespace  capture;

#pragma region Base

Base::Base()
{
	
}

Base::~Base()
{
	for (QProcess* q_process : QProcessList)
	{
		if (QProcess::Running== q_process->state())
		{
			q_process->kill();
		}
		delete q_process;
		q_process = nullptr;
	}
}

void Base::set_adb_path(const QString adb_path)
{
	/*if (!QFile::exists(adb_path))
	{
		qDebug() << "The adb path:" << adb_path << " is invaild!";
	}*/
	ADB_PATH = adb_path;
}

QString Base::run_cmd(const QStringList args, const bool waitforfinish = true)
{
	//std::shared_ptr<QProcess> process(new QProcess);
	QProcess *process = new QProcess;
	QString result;
	process->setProgram(ADB_PATH);
	process->setNativeArguments(args.join(" "));
	process->start();
	if (waitforfinish)
	{
		process->waitForFinished(1000);
		result = QString::fromLocal8Bit(process->readAll());
		delete process;
		process = nullptr;
	}
	else
	{
		if (process->state() != QProcess::NotRunning)
		{
			QProcessList.append(process);
		}
		else
		{
			delete process;
			process = nullptr;
		}

	}
	return result;
}

QString Base::rum_cmd(const QStringList args)
{
	return run_cmd(args, true);
}

QMap<QString, QString> Base::get_devices()
{
	QStringList devices;
	devices << "devices";
	QString result = run_cmd(devices);
	QMap<QString, QString> a{};
	return a;
}

void Base::set_default_device(QString device)
{
}


#pragma endregion 

#pragma region Scrcpy 

Scrcpy::Scrcpy(int port)
{
	PORT = port;
	ADB_PATH = "O:\\ADB Driver\\adb.exe";
	SCRCPY_SERVER_JAR = "B:\\falling\\Downloads\\Compressed\\scrcpy-win64-v1.8\\scrcpy-server.jar";

	PUSH_JAR = QList<QString>{ "push",SCRCPY_SERVER_JAR,"/data/local/tmp/" };

	EXEC = QList<QString>{ "shell","CLASSPATH=/data/local/tmp/scrcpy-server.jar",
		"app_process","/","com.genymobile.scrcpy.Server",
		SVR_maxSize,SVR_bitRate,SVR_tunnelForward,SVR_crop,SVR_sendFrameMeta };

	FORWARD = QList<QString>{ "forward",QString("tcp:") + QString::number(PORT) + QString(" localabstract:scrcpy") };

}

void Scrcpy::run_server()
{



}

Scrcpy::~Scrcpy()
{

	QList<QString> clear_scrcpy = { "shell","pkill","-f","scrcpy" };

}

#pragma endregion 

#pragma region MinCap

Minicap::Minicap()
{
	GET_ABI << "shell" << "getprop" << "ro.product.cpu.abi";
	GET_SDK << "shell" << "getprop" << "ro.build.version.sdk";
	GET_WxH << "shell" << "dumpsys" << "window" << "d";
	FORWARD_CAP << "forward" << QString("tcp:") + QString::number(MINICAP_PORT) << QString("localabstract:minicap");
	set_adb_path("O:\\ADB Driver\\adb.exe");
	cap_socket = new QTcpSocket;
	
	
}



Minicap::~Minicap()
{
	QStringList clear_minicap;
	clear_minicap << "shell" << "pkill" << "-f" << "minicap";
	run_cmd(clear_minicap);
	QStringList clear_minitouch;
	clear_minitouch << "shell" << "pkill" << "-f" << "minitouch";
	run_cmd(clear_minitouch);
	delete cap_socket, cap_socket = nullptr;
}

void Minicap::run_server()
{
	//TODO PUSH minicap and minicap.so 
	/*QString abi = run_cmd(GET_ABI).trimmed();
	QString sdk = run_cmd(GET_SDK).trimmed();
	QString a_path(""),b_path("");
	PUSH_A << "push" << a_path << "/data/local/tmp/";
	PUSH_B << "push" << b_path << "/data/local/tmp/";
	run_cmd(PUSH_A);
	run_cmd(PUSH_B);*/
	// get width and height
	QString wh_content = run_cmd(GET_WxH);
	QRegExp rx("init=(\\d+)x(\\d+)");
	QString w, h;
	int pos = 0;
	while ((pos = rx.indexIn(wh_content, pos)) != -1) {
		w = rx.cap(1);
		h = rx.cap(2);
		break;
	}
	//run test then run
	RUN << "shell" << "LD_LIBRARY_PATH=/data/local/tmp" << "/data/local/tmp/minicap" << "-P" << w + "x" + h + "@" + w + "x" + h + "/0";
	RUN_TEST << RUN << "-t";
	//TODO to confirm is ok by using the result 
	QString result = run_cmd(RUN_TEST);
	qDebug() << result;
	run_cmd(RUN, false);
	


}

bool Minicap::connnect_cap()
{
	HEADER header;
	cap_socket->connectToHost(QHostAddress::LocalHost, MINICAP_PORT);
	cap_socket->waitForConnected();
	cap_socket->readyRead();
	auto header_bit= cap_socket->read(sizeof(HEADER));
	qDebug() << header_bit.toBase64();
	memcpy(&header, header_bit, sizeof(HEADER));
	qDebug() << header.pid;
	return false;
}


#pragma endregion 
