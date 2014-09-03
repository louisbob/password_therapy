#include <QApplication>
#include <QPushButton>
#include "include/mainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mWin;
    mWin.show();

    return app.exec();
}
