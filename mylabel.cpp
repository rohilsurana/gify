#include "mylabel.h"

MyLabel::MyLabel(QWidget *parent) :
    QLabel(parent)
{
}


void MyLabel::mousePressEvent(QMouseEvent * e)
{
  QLabel::mousePressEvent(e);

  emit clicked();
}

bool MyLabel::event(QEvent *e)
{
    QLabel::event(e);
    if(e->type() == QMouseEvent::Enter)
        emit hoverenter();
    if(e->type() == QMouseEvent::Leave)
        emit hoverleave();
}
