#include "system.h"

// opsystem 类的默认构造函数
opsystem::opsystem() {}

// 添加新书到系统中，如果该书尚不存在
void opsystem::addbooks(const std::string& bookname, const std::string& writername, const std::string& bookid, const std::string& accessid) {
    if(bmap.find(accessid) == bmap.end()) { // 检查系统中是否已经存在该 accessid 的书籍
        bmap[accessid] = book(bookname, writername, bookid, accessid); // 将新书添加到 map 中
        mymap[bookname].innumbers++;
    }
}

// 根据书籍的 bookid 删除书籍
void opsystem::deletebook(const std::string& bookid) {
    mymap[bmap[bookid].showname()].innumbers--;
    bmap.erase(bookid); // 从 map 中移除书籍
}

// 处理借书操作，记录借书的详细信息
void opsystem::borrowbook(book& btemple, reader& rtemple, int day, int month, int year) {
    mymap[btemple.showname()].innumbers--;
    mymap[btemple.showname()].outnumbers++;
    btemple.borrowbook(rtemple.showkey(), day, month, year); // 更新书籍状态为已借出
    rtemple.borrow(btemple.showaccid(), btemple.showid()); // 更新读者状态以反映已借书籍
}

// 运行 OCR（光学字符识别），处理图片并提取文本
void opsystem::ocr() {
    QProcess *process = new QProcess(); // 创建一个新的 QProcess 实例来执行命令

    // 运行 tesseract OCR 工具的命令，用于处理图片文件
    QString command = "cd 'C:\\Users\\jiaxi\\Desktop' ; tesseract picture.png answer";
    process->start("powershell", QStringList() << "-Command" << command); // 在 PowerShell 中执行该命令
}

// 处理读者归还书籍的操作
void opsystem::returnbook(book& btemple, reader& rtemple) {
    rtemple.returnbooks(btemple.showaccid(),btemple.showid()); // 更新读者状态以反映已归还书籍
    btemple.returnbook(); // 更新书籍状态为可用
    mymap[btemple.showname()].innumbers++;
    mymap[btemple.showname()].outnumbers--;
}

// 向系统中添加新读者
void opsystem::addreader(const std::string name, const std::string key) {
    rmap[key] = reader(name, key); // 将新读者添加到 map 中
}

// 从文件中读取书籍信息并填充到书籍 map 中
void opsystem::readbookfile(const QString& bookfilepath) {
    QFile file(bookfilepath); // 打开文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 检查文件是否成功打开
        qDebug() << "Cannot open file for reading:" << file.errorString(); // 如果文件不能打开，打印错误信息
        return;
    }

    QTextStream in(&file); // 创建一个文本流来读取文件
    while (!in.atEnd()) { // 逐行读取文件内容
        QString line = in.readLine(); // 读取一行
        QStringList fields = line.split(','); // 按逗号分隔字段

        if (fields.size() < 9) { // 检查行的字段数是否足够
            qDebug() << "Line format is incorrect, skipping line:" << line; // 如果字段数不正确，跳过该行
            continue;
        }

        std::string bookname = fields.at(0).trimmed().toStdString(); // 书名
        std::string writername = fields.at(1).trimmed().toStdString(); // 作者名
        std::string bookid = fields.at(2).trimmed().toStdString(); // 书籍ID
        std::string accessid = fields.at(3).trimmed().toStdString(); // 访问ID
        std::string readerid = fields.at(4).trimmed().toStdString(); // 读者ID
        bool bout = fields.at(5).trimmed() == "1"; // 将 "1" 转换为 true，"0" 转换为 false
        int day = fields.at(6).trimmed().toInt(); // 借书日期的日
        int month = fields.at(7).trimmed().toInt(); // 借书日期的月
        int year = fields.at(8).trimmed().toInt(); // 借书日期的年

        bmap[accessid] = book(bookname, writername, bookid, accessid, readerid, bout, day, month, year); // 将书籍信息添加到 map 中
        if(bout==0)
        {
            mymap[bookname].innumbers++;
        }
        else
        {
            mymap[bookname].outnumbers++;
        }
    }
    file.close(); // 关闭文件
}

// 从文件中读取读者信息并填充到读者 map 中
void opsystem::readreaderfile(const QString& readerfilepath) {
    QFile file(readerfilepath); // 打开文件
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) { // 检查文件是否成功打开
        qDebug() << "Cannot open file for reading:" << file.errorString(); // 如果文件不能打开，打印错误信息
        return;
    }

    QTextStream in(&file); // 创建一个文本流来读取文件
    while (!in.atEnd()) { // 逐行读取文件内容
        QString line = in.readLine(); // 读取一行
        QStringList fields = line.split(','); // 按逗号分隔字段

        if (fields.size() < 8) { // 检查行的字段数是否足够
            qDebug() << "Line format is incorrect, skipping line:" << line; // 如果字段数不正确，跳过该行
            continue;
        }

        std::string rname = fields.at(0).trimmed().toStdString(); // 读者姓名
        std::string rkey = fields.at(1).trimmed().toStdString(); // 读者ID
        std::string baccessid1 = fields.at(2).trimmed().toStdString(); // 书籍ID1
        std::string bid1 = fields.at(3).trimmed().toStdString(); // 书名1
        std::string baccessid2 = fields.at(4).trimmed().toStdString(); // 书籍ID2
        std::string bid2 = fields.at(5).trimmed().toStdString(); // 书名2
        int numbers = fields.at(6).trimmed().toInt(); // 借书总数
        int situations = fields.at(7).trimmed().toInt(); // 借书状态

        rmap[rkey] = reader(rname, rkey, baccessid1, bid1, baccessid2, bid2, numbers, situations); // 将读者信息添加到 map 中
    }
    file.close(); // 关闭文件
}

// 将书籍信息写入到文件中
void opsystem::writebookfile(const QString& bookfilepath) {
    QFile file(bookfilepath); // 打开文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { // 检查文件是否成功打开
        qDebug() << "Cannot open file for writing:" << file.errorString(); // 如果文件不能打开，打印错误信息
        return;
    }

    QTextStream out(&file); // 创建一个文本流来写入文件
    for (const auto& entry : bmap) { // 遍历所有书籍信息
        const std::string& accessid = entry.first; // 访问ID
        const book& bookInfo = entry.second; // 书籍信息
        QString bookname = QString::fromStdString(bookInfo.showname()); // 书名
        QString writername = QString::fromStdString(bookInfo.showwritername()); // 作者名
        QString bookid = QString::fromStdString(bookInfo.showid()); // 书籍ID
        QString readerid = QString::fromStdString(bookInfo.showreaderid()); // 读者ID
        bool bout = bookInfo.outsit(); // 借出状态
        int day = bookInfo.showday(); // 借书日期的日
        int month = bookInfo.showmonth(); // 借书日期的月
        int year = bookInfo.showyear(); // 借书日期的年

        out << bookname << ","
            << writername << ","
            << bookid << ","
            << QString::fromStdString(accessid) << ","
            << readerid << ","
            << (bout ? "1" : "0") << "," // 将 true/false 转换为 "1"/"0"
            << day << ","
            << month << ","
            << year << "\n"; // 写入一行数据
    }
    file.close(); // 关闭文件
}

// 将读者信息写入到文件中
void opsystem::writereaderfile(const QString& readerfilepath) {
    QFile file(readerfilepath); // 打开文件
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) { // 检查文件是否成功打开
        qDebug() << "Cannot open file for writing:" << file.errorString(); // 如果文件不能打开，打印错误信息
        return;
    }

    QTextStream out(&file); // 创建一个文本流来写入文件
    for (const auto& entry : rmap) { // 遍历所有读者信息
        const reader& readerinfo = entry.second; // 读者信息
        QString name = QString::fromStdString(readerinfo.showname()); // 读者姓名
        QString id = QString::fromStdString(readerinfo.showkey()); // 读者ID
        QString baccessid1 = QString::fromStdString(readerinfo.showbaccessid1()); // 书籍ID1
        QString bid1 = QString::fromStdString(readerinfo.showbid1()); // 书名1
        QString baccessid2 = QString::fromStdString(readerinfo.showbaccessid2()); // 书籍ID2
        QString bid2 = QString::fromStdString(readerinfo.showbid2()); // 书名2
        int numbers = readerinfo.shownumbers(); // 借书总数
        int situations = readerinfo.showsituation(); // 借书状态

        out << name << "," << id << ","
            << baccessid1 << "," << bid1 << ","
            << baccessid2 << "," << bid2 << ","
            << numbers << "," << situations << "\n"; // 写入一行数据
    }
    file.close(); // 关闭文件
}
