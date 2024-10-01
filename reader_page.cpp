#include "reader_page.h"
#include "ui_reader_page.h"
#include "global.h"
#include <map>
#include <QDate>
#include "mainwindow.h" // 引入 MainWindow

reader_page::reader_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reader_page)
{
    ui->setupUi(this);
    updateTableModel();
}

reader_page::~reader_page()
{
    delete ui;
}
void reader_page::updateTableModel()//更新列表，在列表发生改变后使用
{
    BookTableModel *model = new BookTableModel(this);
    model->setBooks(regula_system.bmap);
    ui->tableView->setModel(model);
}

void reader_page::on_search_clicked()
{
    QString temple = ui->bookinfo->text().trimmed();//读取lineedit上的信息
    std::map<std::string, book> temple_map;//创建一个零食的map
    int searchType = ui->category->currentIndex();//确定查找依据
        for (const auto &entry : regula_system.bmap)//遍历原map，将与标签对应的个体存入临时map中
        {
            bool match = false;
            switch (searchType)
            {
                case 0: match = (entry.second.showid() == temple.toStdString()); break;
                case 1: match = (entry.second.showaccid() == temple.toStdString()); break;
                case 2: match = (entry.second.showwritername() == temple.toStdString()); break;
                case 3: match = (entry.second.showreaderid() == temple_id); break;
                case 4: match = (entry.second.outsit() == 0); break;
                case 5: match = (entry.second.showname()==temple.toStdString());break;
                case 6: match =1;
                default: break;
            }
            if (match)
            {
                temple_map[entry.first] = entry.second;
            }
        }
        BookTableModel *model = new BookTableModel(this);
        model->setBooks(temple_map);
        ui->tableView->setModel(model);
        ui->bookinfo->clear();
}

void reader_page::on_borrow_clicked()//借书
{
    QDate current_time = QDate::currentDate();
    int year = current_time.year();
    int month = current_time.month();
    int day = current_time.day();

    QString id = ui->id->text().trimmed();
    QString accessid = ui->accessid->text().trimmed();

    if (regula_system.rmap[temple_id].shownumbers() >= 2)//该读者是否借书过多
    {
        ui->situation->setText("have borrow too much");
        ui->accessid->clear();
        ui->id->clear();
        return;
    }

    auto bookIt = regula_system.bmap.find(accessid.toStdString());
    if (bookIt == regula_system.bmap.end() || bookIt->second.outsit() == 1)//书籍信息是否正确与是否在库存中
    {
        ui->situation->setText("the book is out or wrong information");
        ui->accessid->clear();
        ui->id->clear();
        return;
    }

    if (bookIt->second.showid() == id.toStdString())
    {
        regula_system.borrowbook(bookIt->second, regula_system.rmap[temple_id], day, month, year);
        ui->situation->setText("borrow success");
        ui->accessid->clear();
        ui->id->clear();
        updateTableModel();
    }
    else
    {
        ui->situation->setText("wrong information");
        ui->accessid->clear();
        ui->id->clear();
    }
}

void reader_page::on_return_3_clicked()//还书
{
    QString name =ui->id->text().trimmed();
    QString accessid = ui->accessid->text().trimmed();

    auto &reader = regula_system.rmap[temple_id];
    if ((reader.showbaccessid1() == accessid.toStdString() && reader.showbid1() == name.toStdString()) ||
        (reader.showbaccessid2() == accessid.toStdString() && reader.showbid2() == name.toStdString()))
    {
        regula_system.returnbook(regula_system.bmap[accessid.toStdString()], reader);
        ui->situation->setText("return success");
        ui->accessid->clear();
        ui->id->clear();
        updateTableModel();
    }
    else
    {
        ui->situation->setText("wrong information");
        ui->accessid->clear();
        ui->id->clear();
    }
}

void reader_page::on_close_clicked()
{
    saveData();
    this->close();
}
