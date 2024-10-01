#include "regula_reader_page.h"
#include "ui_regula_reader_page.h"
#include"global.h"

regula_reader_page::regula_reader_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regula_reader_page)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint);
    updateTableModel();
}
void regula_reader_page::updateTableModel()//更新表格模型
{
    ReaderTableModel *model = new ReaderTableModel(this);
    model->setReaders(regula_system.rmap);
    ui->tableView->setModel(model);
}
regula_reader_page::~regula_reader_page()
{
    delete ui;
}
void regula_reader_page::on_black_clicked()//拉黑读者
{
    QString name = ui->name->text();
    QString id = ui->id->text();
    auto it = regula_system.rmap.find(id.toStdString());
    if (it != regula_system.rmap.end() && QString::fromStdString(it->second.showname()) == name)
    {
        it->second.turn_black();
        ui->situation->setText("success");
         updateTableModel();
    }
    else
    {
        ui->situation->setText("wrong person");
    }
    ui->name->clear();
    ui->id->clear();
}

void regula_reader_page::on_black_2_clicked()//取消拉黑
{
    QString name = ui->name->text();
    QString id = ui->id->text();
    auto it = regula_system.rmap.find(id.toStdString());
    if (it != regula_system.rmap.end() && QString::fromStdString(it->second.showname()) == name)
    {
        it->second.turn_white();
        ui->situation->setText("success");
         updateTableModel();

    }
    else
    {
        ui->situation->setText("wrong person");
    }
    ui->name->clear();
    ui->id->clear();
}

void regula_reader_page::on_research_clicked()//按照不同信息查找读者
{

    std::map<std::string,reader>temple_map;
    int category = ui->comboBox->currentIndex();
    for (const auto &entry : regula_system.rmap)
    {
        bool match = false;
        switch (category)
        {
            case 0: match = (entry.second.shownumbers()==0); break;
            case 1: match = (entry.second.shownumbers()==1); break;
            case 2: match = (entry.second.shownumbers()==2); break;
         case 3: match = 1;
            default: break;
        }
        if (match)
        {
            temple_map[entry.first] = entry.second;
        }
    }
    ReaderTableModel *model = new ReaderTableModel(this);
    model->setReaders(temple_map);
    ui->tableView->setModel(model);
    ui->situation->clear();
}


void regula_reader_page::on_pushButton_clicked()
{
    this->close();
}
