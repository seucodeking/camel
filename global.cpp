#include "global.h"


opsystem regula_system;
std::string temple_name;
std::string temple_id;
bool in_regula=0;

void saveData()
{
    regula_system.writebookfile("C:\\Users\\jiaxi\\Documents\\build-ximen_library_system-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\\bookinfor.txt");
    regula_system.writereaderfile("C:\\Users\\jiaxi\\Documents\\build-ximen_library_system-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\\readerinfor.txt");
}
void centerwindow(QWidget *window) {
    if (!window) return;  // 如果传入的窗口指针为空，直接返回

    QScreen *screen = QGuiApplication::primaryScreen();
    if (!screen) return;  // 如果无法获取屏幕信息，直接返回

    QRect screenGeometry = screen->availableGeometry();
    int x = (screenGeometry.width() - window->width()) / 2;
    int y = (screenGeometry.height() - window->height()) / 2;
    window->move(x, y);//将窗口移到屏幕中央
}

