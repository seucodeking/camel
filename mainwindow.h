#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"global.h"
#include <QMainWindow>
#include "reader_page.h"  // 假设你有一个 `reader_page` 类
#include "regula_all.h"  // 假设你有一个 `regula_page` 类
#include "system.h"       // 包含 opsystem 类的头文件

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void openreader_page();

    void openregula_book_page();

private slots:

    void on_sign_up_clicked();//读者注册

    void on_sign_in_clicked();//读者或管理人员登录

    void on_close_clicked();//关闭页面

private:
    Ui::MainWindow *ui;
    regula_all regula;
    reader_page reader_pa;
};

#endif // MAINWINDOW_H
