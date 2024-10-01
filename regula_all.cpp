#include "regula_all.h"
#include "ui_regula_all.h"

regula_all::regula_all(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regula_all)
{
    ui->setupUi(this);
    }


regula_all::~regula_all()
{
    delete ui;
}

void regula_all::on_bookregula_clicked()
{
    regula_book_page*pointer = &regula_book;
    centerwindow(pointer);
    regula_book.show();
}
void regula_all::on_readerregula_clicked()
{
    regula_reader.show();

}

void regula_all::on_close_clicked()
{
   this->~regula_all();
    saveData();
}
