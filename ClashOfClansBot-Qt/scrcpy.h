#pragma once
#ifndef SCRCPY_H
#define SCRCPY_H
#include <qprocess.h>
#include <QDebug>
#include <QTcpSocket>
#include <QHostAddress>
#include <QRegExp>
#include <QFile>

#ifndef FFMPEG
#define FFMPEG
extern "C" {
#include <libavcodec/avcodec.h>
}
#endif

#endif//SCRCPY_H end




namespace capture {

	class Base
	{
	public:
		Base();
		~Base();
		void set_adb_path(const QString adb_path);
		QString run_cmd(const QStringList args, const bool waitforfinish);
		QString rum_cmd(const QStringList args);
		QMap<QString, QString> get_devices();
		void set_default_device(QString device);
	protected:
		QString ADB_PATH;
		int MINICAP_PORT{ 19916 }, MINITOUCH_PORT{19255}, SCRCPY_PORT{19505};
		bool is_multidevice;

	private:
		QList<QProcess*> QProcessList{};

	};

	class Scrcpy
	{
	public:

		Scrcpy(int port);
		~Scrcpy();
		void run_server();

	private:

		QProcess* push_process, *exec_process, *forward_process;
		QString ADB_PATH, SCRCPY_SERVER_JAR;
		QStringList PUSH_JAR, EXEC, FORWARD;
		QString SVR_maxSize{ "600" },
			SVR_bitRate{ "999999999" },
			SVR_tunnelForward{ "true" },
			SVR_crop{ "9999:9999:0:0" },
			SVR_sendFrameMeta{ "true" };
		int PORT;


	};


	class Minicap : protected capture::Base
	{
	public:
		Minicap();
		~Minicap();
		void run_server();
		bool connnect_cap();
	private:
		QStringList GET_ABI, GET_SDK, GET_WxH, PUSH_A, PUSH_B, RUN_TEST, RUN, FORWARD_CAP,FORWARD_TOUCH;
		QTcpSocket *cap_socket, *touch_socket;
		struct HEADER
		{
			unsigned char version;
			unsigned char SizeOfHeader;
			uint32_t pid;
			uint32_t RealWidth;
			uint32_t RealHeight;
			uint32_t VirtualWidth;
			uint32_t VirtualHeight;
			unsigned char orientation;
			unsigned char Quirkbitflags;
		};
		struct FRAME
		{
			uint32_t frameSize;
			unsigned char * frame;
		};

	};



}