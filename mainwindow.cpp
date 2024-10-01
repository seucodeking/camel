#include "mainwindow.h"
#include "ui_mainwindow.h"

// MainWindow 构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // 设置用户界面
}

// MainWindow 析构函数
MainWindow::~MainWindow()
{
    delete ui; // 释放用户界面占用的内存
}

// 打开读者页面
void MainWindow::openreader_page()
{
    reader_page* ptr = &reader_pa; // 获取 reader_pa 页面指针
    this->hide(); // 隐藏当前窗口
    centerwindow(ptr); // 居中显示新的窗口
    reader_pa.setWindowFlags(Qt::FramelessWindowHint); // 设置窗口无边框
    reader_pa.show(); // 显示读者页面
}

// 打开管理者页面
void MainWindow::openregula_book_page()
{
    this->hide(); // 隐藏当前窗口
    regula.setWindowFlags(Qt::FramelessWindowHint); // 设置窗口无边框
    regula.show(); // 显示普通书籍页面
}

// 处理用户点击“注册”按钮的事件
void MainWindow::on_sign_up_clicked()
{
    QString name = ui->name->text().trimmed(); // 获取输入的姓名
    QString key = ui->key->text().trimmed(); // 获取输入的密钥

    // 检查姓名或密钥是否为空
    if (name.isEmpty() || key.isEmpty()) {
        ui->situation->setText("Name and Key cannot be empty"); // 显示错误信息
        return;
    }

    std::string namestr = name.toStdString(); // 转换姓名为 std::string
    std::string keystr = key.toStdString(); // 转换密钥为 std::string

    // 检查账户是否已存在
    if (regula_system.rmap.find(keystr) != regula_system.rmap.end()) {
        ui->situation->setText("The account already exists"); // 显示账户已存在的信息
    } else {
        regula_system.addreader(namestr, keystr); // 添加新读者到系统中
        ui->situation->setText("Sign up successfully"); // 显示注册成功的信息
    }
    ui->key->clear(); // 清空密钥输入框
    ui->name->clear(); // 清空姓名输入框
}

// 处理用户点击“登录”按钮的事件
void MainWindow::on_sign_in_clicked()
{
    QString name = ui->name->text().trimmed(); // 获取输入的姓名
    QString key = ui->key->text().trimmed(); // 获取输入的密钥

    // 检查姓名或密钥是否为空
    if (name.isEmpty() || key.isEmpty()) {
        ui->situation->setText("Name and Key cannot be empty"); // 显示错误信息
        return;
    }

    // 判断是否选择了“管理者”选项
    if (ui->regula->isChecked())
    {
        in_regula = 1; // 设置为普通用户
        if (name == "1" && key == "1") { // 硬编码的普通用户验证
            openregula_book_page(); // 打开普通书籍页面
            ui->situation->setText("Welcome, regular"); // 显示欢迎信息
        }
        else {
            ui->situation->setText("Wrong person"); // 显示错误信息
        }
    }
    else {
        in_regula = 0; // 设置为非普通用户
        std::string keystr = key.toStdString(); // 转换密钥为 std::string
        auto it = regula_system.rmap.find(keystr); // 查找输入的密钥

        // 验证读者信息
        if (it != regula_system.rmap.end() && QString::fromStdString(it->second.showname()) == name) {
            if (it->second.showsituation() == 1) { // 检查账户是否被禁用
                ui->situation->setText("you have be baned"); // 显示被拉黑
                return;
            }
            ui->situation->setText("Log in successful"); // 显示登录成功的信息
            temple_name = name.toStdString(); // 保存读者姓名
            temple_id = keystr; // 保存读者密钥
            openreader_page(); // 切换到读者功能页面
        } else {
            ui->situation->setText("Incorrect name or key"); // 显示姓名或密钥错误的信息
        }
    }
    ui->key->clear(); // 清空密钥输入框
    ui->name->clear(); // 清空姓名输入框
    saveData(); // 保存数据
}

// 处理用户点击“关闭”按钮的事件
void MainWindow::on_close_clicked()
{
    saveData(); // 保存数据
    this->~MainWindow(); // 析构 MainWindow 对象，关闭窗口
}
