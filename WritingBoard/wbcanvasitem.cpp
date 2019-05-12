#include "wbcanvasitem.h"
#include <QDebug>

WbCanvasItem::WbCanvasItem(const QSizeF & size,QGraphicsObject * parent):
    QGraphicsObject (parent)
{

}

WbCanvasItem::~WbCanvasItem()
{

}

void WbCanvasItem::drawPress(int id, const QPointF &p)
{
    qDebug() << "--->>>Lynn<<<---" << __FUNCTION__ << p;
}

void WbCanvasItem::drawMove(int id, const QPointF &lastPoint, const QPointF &curPoint)
{
    qDebug() << "--->>>Lynn<<<---" << __FUNCTION__ << lastPoint<<curPoint;
}

void WbCanvasItem::drawRelease(int id, const QPointF &point)
{
    qDebug() << "--->>>Lynn<<<---" << __FUNCTION__ << point;
}

QRectF WbCanvasItem::boundingRect() const
{
    return  QRectF(0,0,m_size.width(),m_size.height());
}

void WbCanvasItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void WbCanvasItem::resize(const QSizeF &size)
{
    m_size = size;
}
