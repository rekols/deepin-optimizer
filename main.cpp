#include "main_window.h"
#include <DApplication>
#include <QDesktopWidget>
#include "utils.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setTheme("light");

    MainWindow w;
    w.setMinimumSize(800, 550);
    w.setWindowIcon(QIcon(":/images/360logo.svg"));
    w.show();
    w.move((QApplication::desktop()->width() - w.width()) / 2,
           (QApplication::desktop()->height() - w.height()) / 2);

    qApp->setStyleSheet(Utils::getQssContent(":/qss/main.qss"));

    return a.exec();
}
