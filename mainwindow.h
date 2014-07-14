#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QtSvg>
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0,QString s = ":/1.gif");
    ~MainWindow();
    QMovie *movie;
    QString *file;
    QSize *size;
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
protected:
    virtual void wheelEvent(QWheelEvent *event);
};

#endif // MAINWINDOW_H
