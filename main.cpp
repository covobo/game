#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QString>
QString loadStyleSheetFromFileAndReplaceUrlPath(QString file, QString folderForUrl);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile f(QString("://qss/style.css"));
    f.open(QFile::ReadOnly);
    QString stylSheet = QLatin1String(f.readAll());
    f.close();
    qDebug() << stylSheet;

    a.setStyleSheet(stylSheet);

    MainWindow w;
    w.show();

    return a.exec();
}

