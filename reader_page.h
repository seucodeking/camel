#ifndef READER_PAGE_H
#define READER_PAGE_H

#include <QWidget>
#include"book_table_modle.h"
#include"global.h"

namespace Ui {
class reader_page;
}

class reader_page : public QWidget
{
    Q_OBJECT

public:
    explicit reader_page(QWidget *parent = nullptr);
    void updateTableModel();
    ~reader_page();

private slots:
    void on_search_clicked();//查书

    void on_borrow_clicked();//借书

    void on_return_3_clicked();//还书

    void on_close_clicked();//关闭页面

private:
    Ui::reader_page *ui;
};

#endif // READER_PAGE_H
