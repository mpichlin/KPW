#include "SkosParser.hpp"
#include "SkosSerializer.hpp"
#include "SkosModel.hpp"

#include <QDebug>
#include <QFile>
#include <QTextStream>
 
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
	outFile.open(QIODevice::WriteOnly | QIODevice::Append);
	QTextStream ts(&outFile);
	ts << txt << endl;
}

int main()
{
  qInstallMsgHandler(myMessageHandler);
  SkosModel g_skosModel;
  SkosParser g_skosParser(&g_skosModel);
  g_skosParser.parseFile("example.tur", Soprano::SerializationTurtle);
  g_skosModel.removeConceptScheme(QUrl("http://example.org/ns/ConceptScheme"));
  g_skosModel.removeConcept(QUrl("http://example.org/ns/AnotherConcept"));
  g_skosModel.removeLabel(Soprano::Node("Ukryty smok","pl"), 
                          HiddenLabelType,
                          QUrl("http://example.org/ns/MyConcept"));
  g_skosModel.removeLabel(Soprano::Node("Ukryty smok","pl"), 
                          HiddenLabelType,
                          QUrl("http://example.org/ns/MyConcept"));
  SkosSerializer g_skosSerializer(&g_skosModel);
  g_skosSerializer.serialize(QString("out2.txt"), Soprano::SerializationTurtle);
  return 0;
}
