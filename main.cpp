#include <QApplication>
#include "head/superviseClientWidget.h"


int main(int argc, char *argv[]) {

    // 隐藏黑窗口
    // FreeConsole();

    QApplication a(argc, argv);
    superviseClientWidget widget;
    widget.show();
    return QApplication::exec();
}
