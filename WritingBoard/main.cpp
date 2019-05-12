#include <QApplication>
#include <QGraphicsView>
#include <QDesktopWidget>
#include "wbgraphicsscene.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSize desktopSize = qApp->desktop()->screenGeometry().size();
    QGraphicsView view;
    view.resize(desktopSize);
    WbGraphicsScene * pScene = new WbGraphicsScene(desktopSize);
    view.setScene(pScene);
    view.show();

    return a.exec();
}
