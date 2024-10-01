#include "regula_book_page.h"
#include "ui_regula_book_page.h"
#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

regula_book_page::regula_book_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::regula_book_page)
{
    ui->setupUi(this);
   this->setWindowFlags(Qt::FramelessWindowHint);//无边框模式
    updateTableModel();//更新表格
}
void regula_book_page::updateTableModel()//更新列表
{
    BookTableModel *model = new BookTableModel(this);//新建表格模型
    model->setBooks(regula_system.bmap);
    ui->tableView->setModel(model);
}

regula_book_page::~regula_book_page()
{
    delete ui;
}

void regula_book_page::readefile()//读取ocr生成文件
{
    QFile file("C:\\Users\\jiaxi\\Desktop\\answer.txt");//打开ocr文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for reading:" << file.errorString();
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {//按行读取信息
        QString line = in.readLine();
        QStringList fields =  line.split(QRegExp("\\s+"), QString::SkipEmptyParts);//以空格为划分;

        if (fields.size() < 4) {
            qDebug() << "Line format is incorrect, skipping line:" << line;
            continue;
        }
       std::string bookname = fields.at(0).trimmed().toStdString();
        std::string writername = fields.at(1).trimmed().toStdString();
        std::string bookid = fields.at(2).trimmed().toStdString();
        std::string accessid = fields.at(3).trimmed().toStdString();

      regula_system.addbooks(bookname,writername,bookid,accessid);
    }
    file.close();
}
void regula_book_page::on_search_clicked()//查找书目
{

    QString temple = ui->information->text().trimmed();//读取信息
    std::map<std::string, book> temple_map;//新建临时表
    int searchType = ui->category->currentIndex();//读取现在状态
        for (const auto &entry : regula_system.bmap)
        {
            bool match = false;
            switch (searchType)
            {
                case 0: match = (entry.second.showname() == temple.toStdString()); break;//按照书名查找
                case 1: match = (entry.second.showid() == temple.toStdString()); break;//按照id查找
                case 2: match = (entry.second.showaccid() == temple.toStdString()); break;//按照登录号查找
                case 3: match = (entry.second.outsit() == 1); break;//按照在外情况查找
                case 4: match = (entry.second.showwritername()==temple.toStdString());//按照作者查找
                case 5: match = (entry.second.showreaderid()==temple.toStdString());//按照读者id查找
                case 6: match = 1;//显示全部
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
        ui->information->clear();
}

void regula_book_page::on_addbook_clicked()
{
    QString accessid = ui->accessid->text().trimmed();//读取对应信息
    QString bookname = ui->bookname->text().trimmed();
    QString writername = ui->writer->text().trimmed();
    QString bookid = ui->bookid->text().trimmed();

    if (regula_system.bmap.find(accessid.toStdString()) != regula_system.bmap.end())
    {
        ui->situation->setText("The book already exists");//书已经存在
    }
    else
    {
        regula_system.addbooks(bookname.toStdString(), writername.toStdString(), bookid.toStdString(), accessid.toStdString());
        ui->situation->setText("Success add");
        updateTableModel();  // 更新表格模型
    }
    ui->accessid->clear();
    ui->bookid->clear();
    ui->writer->clear();
    ui->bookname->clear();
}

void regula_book_page::on_deletebook_clicked()
{
    QString accessid = ui->accessid->text().trimmed();
    QString bookname = ui->bookname->text().trimmed();
    QString writername = ui->writer->text().trimmed();
    QString bookid = ui->bookid->text().trimmed();
    ui->situation->setText("please check the information");
    if (regula_system.bmap.find(accessid.toStdString()) == regula_system.bmap.end())
    {
        ui->situation->setText("The book does not exists");
    }
    else
    {
        if((regula_system.bmap[accessid.toStdString()].showname()!=bookname.toStdString())||(regula_system.bmap[accessid.toStdString()].showwritername()!=writername.toStdString())||(regula_system.bmap[accessid.toStdString()].showid()!=bookid.toStdString()))
        {
            ui->situation->setText("wrong information");
            return;
        }
        regula_system.deletebook( accessid.toStdString());
        ui->situation->setText("Success delete");
        updateTableModel();  // 更新表格模型
    }
    ui->accessid->clear();
    ui->bookid->clear();
    ui->writer->clear();
    ui->bookname->clear();
}


void regula_book_page::on_pushButton_clicked()
{
   this->destroy();

}

void regula_book_page::on_picture_clicked()
{
    regula_system.ocr();
    readefile();
    updateTableModel();
}

