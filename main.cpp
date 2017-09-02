#include "main_window.h"
#include <DApplication>
#include <QDesktopWidget>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setTheme("light");

    MainWindow w;
    w.setMinimumSize(800, 500);
    w.show();
    w.move((QApplication::desktop()->width() - w.width()) / 2,
           (QApplication::desktop()->height() - w.height()) / 2);

    return a.exec();
}
