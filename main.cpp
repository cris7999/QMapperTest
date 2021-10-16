#include <QApplication>
#include <QPushButton>
#include "mapperWindow.h"
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
//    button.show();

    mapperWindow mapperWindow;
    mapperWindow.show();

    return QApplication::exec();
}
