#ifndef REGULA_ALL_H
#define REGULA_ALL_H

#include <QWidget>
class regula_book_page;
#include"regula_book_page.h"
class regula_reader_page;
#include"regula_reader_page.h"
#include"global.h"

namespace Ui {
class regula_all;
}

class regula_all : public QWidget
{
    Q_OBJECT

public:
    explicit regula_all(QWidget *parent = nullptr);
    ~regula_all();

private slots:
    void on_bookregula_clicked();//进入书籍管理页面

    void on_readerregula_clicked();//进入读者管理页面

    void on_close_clicked();//关闭窗口

private:
    Ui::regula_all *ui;
    regula_book_page regula_book;//书籍管理页面
    regula_reader_page regula_reader;//读者管理页面
};

#endif // REGULA_ALL_H
