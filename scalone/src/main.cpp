#include <QDebug>
#include <QFile>
#include <QTextStream>

#include <QtGui/QApplication>
#include "edytor.h"
#include "przegladarka.h"
void myMessageHandler(QtMsgType type, const char *msg)
{
	QString txt;
	switch (type) {
	case QtDebugMsg:
		txt = QString("Debug: %1").arg(msg);
		break;
	case QtWarningMsg:
		txt = QString("Warning: %1").arg(msg);
	break;
	case QtCriticalMsg:
		txt = QString("Critical: %1").arg(msg);
	break;
	case QtFatalMsg:
		txt = QString("Fatal: %1").arg(msg);
		abort();
	}
	QFile outFile("log");
	outFile.open(QIODevice::WriteOnly);
	QTextStream ts(&outFile);
	ts << txt << endl;
    }

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    przegladarka p;
    p.show();


    qInstallMsgHandler(myMessageHandler);

  return a.exec();
}
