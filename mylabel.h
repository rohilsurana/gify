#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QDrag>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

signals:
    void clicked();
    void hoverenter();
    void hoverleave();
    void dragged();

public slots:

protected:
    void mousePressEvent(QMouseEvent *e);
    virtual bool event(QEvent *e);

};

#endif // MYLABEL_H
