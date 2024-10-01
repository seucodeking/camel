#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    regula_system.readbookfile("C:\\Users\\jiaxi\\Documents\\build-ximen_library_system-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\\bookinfor.txt");
    regula_system.readreaderfile("C:\\Users\\jiaxi\\Documents\\build-ximen_library_system-Desktop_Qt_5_12_10_MinGW_64_bit-Debug\\readerinfor.txt");
    QApplication a(argc, argv);
    a.setStyleSheet(
                            "QWidget {"
                            "   background: #121212;"
                            "   color: #e0e0e0;"
                            "   font-family: 'Arial', sans-serif;"
                            "   border-radius: 15px;"
                            "}"
                            "QPushButton {"
                            "   background: #8e2de2;"
                            "   color: #ffffff;"
                            "   border: none;"
                            "   border-radius: 10px;"
                            "   padding: 15px 30px;"
                            "   font-size: 18px;"
                            "   cursor: pointer;"
                            "   box-shadow: 0 0 15px rgba(255, 0, 255, 0.7), 0 0 30px rgba(255, 0, 255, 0.5);"
                            "   transition: background 0.3s, box-shadow 0.3s;"
                            "}"
                            "QPushButton:hover {"
                                   "   background: linear-gradient(45deg, #ff0081, #ff0081);"
                                   "   border-color: #ff0081;"
                                   "   box-shadow: 0 0 15px rgba(255, 0, 0, 0.8);"
                                   "}"

                            "QLineEdit {"
                            "   background: rgba(40, 40, 40, 0.8);"
                            "   color: #ffffff;"
                            "   border: 1px solid #ff0081;"
                            "   border-radius: 8px;"
                            "   padding: 10px;"
                            "   font-size: 16px;"
                            "   font-weight: bold;"
                            "}"
                            "QLineEdit:focus {"
                            "   border-color: #ff8c00;"
                            "   background: rgba(40, 40, 40, 1);"
                            "   box-shadow: 0 0 10px rgba(255, 0, 128, 0.5);"
                            "}"
                            "QLabel {"
                            "   color: #e0e0e0;"
                            "   font-size: 16px;"
                            "   font-weight: bold;"
                            "   text-shadow: 0 0 10px rgba(255, 0, 128, 0.7);"
                            "}"

                            "QScrollBar:vertical {"
                            "   background: rgba(20, 20, 20, 0.8);"
                            "   width: 12px;"
                            "   border-radius: 6px;"
                            "}"
                            "QScrollBar::handle:vertical {"
                            "   background: #ff0081;"
                            "   border-radius: 6px;"
                            "}"
                            "QScrollBar::handle:vertical:hover {"
                            "   background: #ff8c00;"
                            "}"
                            "QTableView {"
                               "   background-color: #1a1a1a;"                   // 表格背景色
                               "   color: #e0e0e0;"                               // 字体颜色
                               "   border: 2px solid #ff0081;"                    // 表格边框颜色
                               "   border-radius: 8px;"                           // 圆角边框
                               "   gridline-color: #ff004f;"                      // 网格线颜色
                               "}"
                               "QHeaderView::section {"
                               "   background: linear-gradient(45deg, #ff004f, #ff8c00);" // 表头渐变背景色
                               "   color: #ff004f;"                              // 表头字体颜色（绿色霓虹）
                               "   border: 1px solid #ff004f;"                    // 表头边框颜色
                               "   padding: 8px;"
                               "   font-weight: bold;"
                               "   font-size: 14px;"
                               "   border-radius: 5px;"                          // 圆角边框
                               "}"
                               "QHeaderView::section:horizontal {"
                               "   border-bottom: 2px solid #ff004f;"             // 水平边框颜色
                               "}"
                               "QHeaderView::section:vertical {"
                               "   border-right: 2px solid #ff004f;"              // 垂直边框颜色
                               "}"
                               "QTableView::item {"
                               "   padding: 8px;"
                               "   border: 1px solid rgba(255, 0, 128, 0.2);"    // 单元格边框
                               "   border-radius: 5px;"
                               "}"
                               "QTableView::item:selected {"
                               "   background: rgba(255, 0, 128, 0.4);"
                               "   color: #ffffff;"
                               "}"
                               "QTableView::item:hover {"
                               "   background: rgba(255, 0, 128, 0.2);"
                               "}"
                               "QTableView::item:selected:active {"
                               "   background: rgba(255, 0, 128, 0.6);"
                               "}"
                               "QTableCornerButton::section {"
                               "   background-color: #1a1a1a;"
                               "   border: 1px solid #ff0081;"
                               "}"
                               "QCheckBox {"
                                  "   color: #e0e0e0;"
                                  "   font-size: 16px;"
                                  "   font-weight: bold;"
                                  "   spacing: 8px;"
                                  "}"
                                  "QCheckBox::indicator {"
                                  "   width: 20px;"
                                  "   height: 20px;"
                                  "   border: 2px solid #ff0081;"
                                  "   border-radius: 5px;"
                                  "   background: #121212;"
                                  "}"
                                  "QCheckBox::indicator:checked {"
                                  "   background: #ff0081;"
                                  "   border: 2px solid #ff0081;"
                                  "   image: url(:/icons/checked_icon.png);"
                                  "}"
                                  "QCheckBox::indicator:unchecked {"
                                  "   background: #121212;"
                                  "   border: 2px solid #ff0081;"
                                  "   image: url(:/icons/unchecked_icon.png);"
                                  "}");
    MainWindow w;
    w.setWindowFlags(Qt::FramelessWindowHint);
    w.show();
    return a.exec();
}
