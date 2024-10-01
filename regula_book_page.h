#ifndef REGULA_BOOK_PAGE_H
#define REGULA_BOOK_PAGE_H
#include"book_table_modle.h"
#include <QWidget>
#include"global.h"
class MainWindow;
namespace Ui {
class regula_book_page;
}

class regula_book_page : public QWidget
{
    Q_OBJECT

public:
    explicit regula_book_page(QWidget *parent = nullptr);
    ~regula_book_page();
    void readefile();


private slots:
    void on_search_clicked();//查找书籍

    void on_addbook_clicked();//添加书籍

    void on_deletebook_clicked();//删除书籍


    void on_pushButton_clicked();//返回菜单

    void on_picture_clicked();//ocr识别加书

private:
    void updateTableModel();
    Ui::regula_book_page *ui;

};

#endif // REGULA_BOOK_PAGE_H
