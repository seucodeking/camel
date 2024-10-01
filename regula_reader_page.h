#ifndef REGULA_READER_PAGE_H
#define REGULA_READER_PAGE_H
#include <QWidget>
#include"reader_table_modle.h"
namespace Ui {
class regula_reader_page;
}
class regula_reader_page : public QWidget
{
    Q_OBJECT

public:
    explicit regula_reader_page(QWidget *parent = nullptr);
    ~regula_reader_page();
   void updateTableModel();
private slots:


   void on_black_clicked();//拉黑读者

   void on_black_2_clicked();//取消拉黑

   void on_research_clicked();//查找读者

   void on_pushButton_clicked();//返回菜单

private:
    Ui::regula_reader_page *ui;

};

#endif // REGULA_READER_PAGE_H
