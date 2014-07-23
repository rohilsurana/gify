#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
//#include <QtSvg>
#include <QFileDialog>
#include <QDrag>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,QString s = ":/1.gif");
    ~MainWindow();
    int x = 0;
    QMovie *movie;
    QString *file;
    QSize *size;
    bool pausesClicked = true;
    double scaleFactor;

private:
    Ui::MainWindow *ui;
    void createMovie();
    void setupButtons();
private slots:
    void closehover();
    void closehoverleave();
    void zoomin();
    void zoominhover();
    void zoominhoverleave();
    void zoomout();
    void zoomouthover();
    void zoomouthoverleave();
    void pauseButton();
    void pauseButtonhover();
    void pauseButtonhoverleave();
    void moviehover();
    void movieleave();
    void moviemove();
    void setPosition();
protected:

    void mousePressEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // MAINWINDOW_H
