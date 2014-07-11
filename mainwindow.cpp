#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent,QString s) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scaleFactor = 1;
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowState((windowState() & ~(Qt::WindowMinimized | Qt::WindowFullScreen))
                       | Qt::WindowMaximized);


    file = new QString(s);
    createMovie();
    size = new QSize;
    *size = ui->label->sizeHint();
    setupButtons();
    
    
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMovie()
{

    if(file->endsWith(".gif",Qt::CaseInsensitive))
    {
        qDebug()<<"Iam here again"<<QString("Rohil");
        movie = new QMovie(*file);
        movie->setCacheMode(QMovie::CacheAll);
        ui->label->setMovie(movie);
        movie->stop();
        movie->start();
    }
    else
    {
        movie = new QMovie(":/1.gif");
        movie->setCacheMode(QMovie::CacheAll);
        ui->label->setMovie(movie);
        movie->stop();
        movie->start();
    }
}

void MainWindow::setupButtons()
{
    connect(ui->close,SIGNAL(clicked()),this,SLOT(close()));

    connect(ui->close,SIGNAL(hoverenter()),this,SLOT(closehover()));

    connect(ui->close,SIGNAL(hoverleave()),this,SLOT(closehoverleave()));

    connect(ui->zoomin,SIGNAL(clicked()),this,SLOT(zoomin()));

    connect(ui->zoomin,SIGNAL(hoverenter()),this,SLOT(zoominhover()));

    connect(ui->zoomin,SIGNAL(hoverleave()),this,SLOT(zoominhoverleave()));

    connect(ui->zoomout,SIGNAL(clicked()),this,SLOT(zoomout()));

    connect(ui->zoomout,SIGNAL(hoverenter()),this,SLOT(zoomouthover()));

    connect(ui->zoomout,SIGNAL(hoverleave()),this,SLOT(zoomouthoverleave()));



}

void MainWindow::closehover()
{

        ui->close->setPixmap(QPixmap(":/closehover.png"));

}

void MainWindow::closehoverleave()
{

        ui->close->setPixmap(QPixmap(":/close.png"));
}

void MainWindow::zoominhover()
{

        ui->zoomin->setPixmap(QPixmap(":/zoominhover.png"));

}

void MainWindow::zoominhoverleave()
{

        ui->zoomin->setPixmap(QPixmap(":/zoomin.png"));
}

void MainWindow::zoomouthover()
{

        ui->zoomout->setPixmap(QPixmap(":/zoomouthover.png"));

}

void MainWindow::zoomouthoverleave()
{

        ui->zoomout->setPixmap(QPixmap(":/zoomout.png"));
}

void MainWindow::zoomin()
{
    scaleFactor += .05;
    movie->setScaledSize(scaleFactor * (*size));



}

void MainWindow::zoomout()
{
    scaleFactor -= .05;
    movie->setScaledSize(scaleFactor * (*size));

}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    qDebug()<<QWheelEvent::Wheel;
    if(event->delta()>0)
        zoomin();
    if(event->delta()<0)
        zoomout();
}
