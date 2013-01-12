#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString locale = QLocale::system().name().section('_', 0, 0);
    QTranslator translator;
    translator.load(QString("qt_") + locale, QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    QCoreApplication::setApplicationName("Cat Editor");
    a.setApplicationName("Cat Editor");
    qApp->setApplicationName("Cat Editor");

    return a.exec();
}
