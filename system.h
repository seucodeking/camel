#ifndef SYSTEM_H
#define SYSTEM_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <map>
#include "book.h"
#include "reader.h"
#include"qprocess.h"
struct numbers
{
    int outnumbers = 0;
    int innumbers = 0;
};

class opsystem {
public:
    opsystem();

    // Manage books

    void addbooks(const std::string& bookname, const std::string& writername, const std::string& bookid, const std::string& accessid);
    void deletebook(const std::string& bookid);
    void borrowbook(book& btemple, reader& rtemple, int day, int month, int year);
    void returnbook(book& btemple, reader& rtemple);
    void addreader(const std::string name,const std::string key);
    // File operations
    void readbookfile(const QString& bookfilepath);
    void readreaderfile(const QString& readerfilepath);
    void writebookfile(const QString& bookfilepath);
    void writereaderfile(const QString& readerfilepath);
    void ocr();
    std::map<std::string,numbers>mymap;
    std::map<std::string, book> bmap; // Book map
    std::map<std::string, reader> rmap; // Reader map
};

#endif // SYSTEM_H
