#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

signals:
    void clicked();
    void hoverenter();
    void hoverleave();

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
    virtual bool event(QEvent *e);


};

#endif // MYLABEL_H
