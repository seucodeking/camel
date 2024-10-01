#ifndef GLOBAL_H
#define GLOBAL_H


#endif // GLOBAL_H
#include"system.h"
#include"string"
#include <QWidget>
#include <QApplication>
#include <QScreen>
#include"book.h"
struct bookinformation;
struct numbers;
void centerwindow(QWidget *window) ;//将窗口放到屏幕中
extern opsystem regula_system;//管理系统
extern std::string temple_name;//记录当前登录读者名字
extern std::string temple_id;//记录当前登录读者id
extern bool in_regula;//是否为管理员登录
extern void saveData();//保存数据到文件


