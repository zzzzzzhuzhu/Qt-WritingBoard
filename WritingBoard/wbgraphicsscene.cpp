#include "wbgraphicsscene.h"
#include <QDebug>

WbGraphicsScene::WbGraphicsScene(const QSizeF &size, QObject *parent):
    QGraphicsScene(QRectF(0, 0, size.width(), size.height()), parent)
{
    m_pCanvasItem = new WbCanvasItem(size);
    m_pCanvasItem->setBackgroundColor(Qt::white);
    this->addItem(m_pCanvasItem);
}

WbGraphicsScene::~WbGraphicsScene()
{

}

bool WbGraphicsScene::event(QEvent *e)
{
//    qDebug() << "--->>>Lynn<<<---" << __FUNCTION__ << e->type();
    switch(e->type())
    {
    case QEvent::TouchEnd:
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
        if(touchEvent(static_cast<QTouchEvent*>(e))){
            return true;
        }
        break;
    }
    return QGraphicsScene::event(e);
}

bool WbGraphicsScene::touchEvent(QTouchEvent *e)
{
    bool rtn = true;
    QList<QTouchEvent::TouchPoint> touchPoints = e->touchPoints();
    foreach (const QTouchEvent::TouchPoint &touchPoint, touchPoints) {
        int id = touchPoint.id();  //0,1 reserve for mouse event
        switch (touchPoint.state()) {
        case Qt::TouchPointPressed:{
            rtn = scenePress(id, touchPoint.scenePos());
        }
            break;
        case Qt::TouchPointMoved:{
            rtn = sceneMove(id, touchPoint.lastScenePos(), touchPoint.scenePos());
        }
            break;
        case Qt::TouchPointReleased:{
            rtn = sceneRelease(id, touchPoint.scenePos());
        }
            break;
        default:
            break;
        }
    }
    return rtn;
}

bool WbGraphicsScene::scenePress(int id, const QPointF &pos)
{
    m_pCanvasItem->drawPress(id,pos);
    return true;
}

bool WbGraphicsScene::sceneMove(int id, const QPointF &prepos, const QPointF &pos)
{
    m_pCanvasItem->drawMove(id,prepos,pos);
    return true;
}

bool WbGraphicsScene::sceneRelease(int id,const QPointF &pos)
{
    m_pCanvasItem->drawRelease(id,pos);
    return true;
}
