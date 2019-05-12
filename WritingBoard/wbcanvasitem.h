#ifndef WBCANVASITEM_H
#define WBCANVASITEM_H

#include <QGraphicsObject>

class WbCanvasItem : public QGraphicsObject
{
public:
    explicit WbCanvasItem(const QSizeF & size,QGraphicsObject * parent = nullptr);
    ~WbCanvasItem();

    void drawPress(int id,const QPointF &p);
    void drawMove(int id,const QPointF &lastPoint,const QPointF &curPoint);
    void drawRelease(int id, const QPointF &point);
protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    void resize(const QSizeF & size);
private:
    QSizeF m_size;
    QImage m_canvasImage;     //在图片上绘制
    QPainter * m_pBgPainter = nullptr;
};

#endif // WBCANVASITEM_H
