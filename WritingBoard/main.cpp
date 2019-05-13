#include <QApplication>
#include <QGraphicsView>
#include <QDesktopWidget>
#include "wbgraphicsscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize desktopSize = qApp->desktop()->screenGeometry().size();
    QGraphicsView * view = new QGraphicsView();
    WbGraphicsScene * pScene = new WbGraphicsScene(desktopSize);
    view->setScene(pScene);
    view->resize(desktopSize);
    view->show();

    return a.exec();
}
