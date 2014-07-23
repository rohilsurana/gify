#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMovie>
#include <QDebug>
#include <QDesktopWidget>
#include <QScreen>
#include <QPainter>
#include <QMimeData>
#include <QMimeType>



MainWindow::MainWindow(QWidget *parent,QString s) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    scaleFactor = 1;
    ui->setupUi(this);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint);


    file = new QString(s);
    createMovie();
    setPosition();
    size = new QSize;
    *size = ui->label->sizeHint();
    setupButtons();
    qDebug()<<this->sizeHint();


    
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
        if(QFile(*file).size()>10000000)
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
    ui->label->resize(ui->label->sizeHint() + QSize(20,20));
    //QScreen *w = new QScreen();
    //qDebug()<<w.availableSize();
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

    connect(ui->label,SIGNAL(dragged()),this,SLOT(moviemove()));

    connect(ui->label,SIGNAL(hoverenter()),this,SLOT(moviehover()));

    connect(ui->label,SIGNAL(hoverleave()),this,SLOT(movieleave()));

    connect(ui->pauseButton,SIGNAL(clicked()),this,SLOT(pauseButton()));

    connect(ui->pauseButton,SIGNAL(hoverenter()),this,SLOT(pauseButtonhover()));

    connect(ui->pauseButton,SIGNAL(hoverleave()),this,SLOT(pauseButtonhoverleave()));



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

void MainWindow::moviehover()
{
    this->setCursor(Qt::SizeAllCursor);
}

void MainWindow::movieleave()
{
    this->setCursor(Qt::ArrowCursor);
}

void MainWindow::pauseButton()
{
    if(pausesClicked)
    {
        movie->setPaused(true);
        pausesClicked = false;
        ui->pauseButton->setPixmap(QPixmap(":/play.png"));
    }
    else
    {
        movie->setPaused(false);
        pausesClicked = true;
        ui->pauseButton->setPixmap(QPixmap(":/pauseButton.png"));
    }
}

void MainWindow::pauseButtonhover()
{
    if(pausesClicked)
        ui->pauseButton->setPixmap(QPixmap(":/pauseButtonhover.png"));
    else
        ui->pauseButton->setPixmap(QPixmap(":/playhover.png"));
}

void MainWindow::pauseButtonhoverleave()
{
    if(pausesClicked)
        ui->pauseButton->setPixmap(QPixmap(":/pauseButton.png"));
    else
        ui->pauseButton->setPixmap(QPixmap(":/play.png"));
}

void MainWindow::moviemove()
{
    QPoint cursorPos = cursor().pos();
    QPoint relCursorPos = ui->label->cursor().pos();
    qDebug()<<cursorPos<<"yup"<<relCursorPos;
}

void MainWindow::zoomin()
{
    //if(scaleFactor<2.25)
    scaleFactor += .05;
    movie->setScaledSize(scaleFactor * (*size));
    ui->label->resize(ui->label->sizeHint() + QSize(20,20));
    if(x!=1)
    setPosition();
    else
        ui->label->move(ui->label->pos());



}

void MainWindow::zoomout()
{
    if(scaleFactor>0.05)
    scaleFactor -= .05;
    movie->setScaledSize(scaleFactor * (*size));
    ui->label->resize(ui->label->sizeHint() + QSize(20,20));
    if(x!=1)
    setPosition();
    else
        ui->label->move(ui->label->pos());


}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    qDebug()<<QWheelEvent::Wheel;
    if(event->delta()>0)
        zoomin();
    if(event->delta()<0)
        zoomout();
}

void MainWindow::setPosition()
{
    QSize screen = QDesktopWidget().screenGeometry(this).size();
    QSize zoomin= screen - ui->zoomin->sizeHint();
    QSize zoomout= screen - ui->zoomout->sizeHint();
    QSize close= screen - ui->close->sizeHint();
    QSize labelPos= screen - ui->label->sizeHint();



    zoomin = zoomin / 2;
    zoomout = zoomout / 2;
    close = close;
    labelPos = labelPos / 2;

    ui->zoomin->move(zoomin.width()-ui->zoomin->sizeHint().width() - 10,screen.height()-ui->zoomin->sizeHint().height() - 5);
    ui->zoomout->move(zoomout.width()+ui->zoomout->sizeHint().width() + 10,screen.height()-ui->zoomout->sizeHint().height() - 5);
    ui->pauseButton->move(zoomin.width()-ui->pauseButton->sizeHint().width() + 30,screen.height()-ui->pauseButton->sizeHint().height() - 5);

    ui->close->move(close.width()+10,0);
    ui->label->move(labelPos.width(),labelPos.height());

}





void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QLabel *child = static_cast<QLabel*>(childAt(event->pos()));
    if (!child)
        return;
    qDebug()<<"Rohil dfef";
    if(child->pixmap())
        return;
        qDebug()<<"Rohil dfef";
    child->movie()->setPaused(true);
    QPixmap pixmap = child->movie()->currentPixmap();


    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->pos() - child->pos());

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();
    drag->setPixmap(tempPixmap);
    drag->setHotSpot(event->pos() - child->pos());
    qDebug()<<"Rohil dfef";



    qDebug()<<"Rohil dfef";

    child->setMovie(child->movie());

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        child->close();
    } else {
        //child->show();
        x=1;
        child->move(this->cursor().pos() + child->pos() - event->pos());
        //qDebug()<<this->cursor().pos()<<"MOUSE"<< this->cursor().pos() - event->pos();
        //child->setMovie(child->movie());
        if(pausesClicked)
        child->movie()->setPaused(false);
    }

}
