#include "headers/windows/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window = MainWindow(nullptr);
    window.showMaximized();
    return app.exec();
}
