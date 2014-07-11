#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString s;
    if(argc==1||argc>2)
    {
        s=":/1.gif";
    }
    else
    {
        qDebug()<<"IAM HERE"<<argv[1];
        s=QString(argv[1]);
    }
    MainWindow w(0,s);

    w.show();

    return a.exec();
}
