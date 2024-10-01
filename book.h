#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <map>

// 结构体用于表示借书日期

struct Date {
    int m_day;
    int m_month;
    int m_year;
};
// book 类用于表示书籍信息和借阅状态
class book {
public:
    // 构造函数
    book(const std::string& bookname, const std::string& writername,
         const std::string& bookid, const std::string& accessid,
         const std::string& readerid="NA", bool out = 0, int day = 0, int month = 0, int year = 0);

    // 拷贝构造函数
    book(const book& other);

    // 默认构造函数
    book();

    // 析构函数
    ~book();

    // 借书函数
    void borrowbook(const std::string& readerid, int day, int month, int year);

    // 还书函数
    void returnbook();

    // 访问器方法
    std::string showid() const; // 显示书籍ID
    std::string showname() const; // 显示书名
    std::string showwritername() const; // 显示作者名
    std::string showaccid() const; // 显示访问ID
    std::string showreaderid() const; // 显示读者ID
    int outsit() const; // 返回借出状态（0 表示未借出，1 表示已借出）
    int showday() const; // 显示借书日期的日
    int showmonth() const; // 显示借书日期的月
    int showyear() const; // 显示借书日期的年

private:
    std::string m_bookname; // 书名
    std::string m_writername; // 作者名
    std::string m_boookid; // 书籍ID
    std::string m_accessid; // 访问ID
    std::string m_readerid; // 读者ID
    bool m_bout; // 借出状态（true 表示已借出，false 表示未借出）
    Date borrowdate; // 借书日期
};

#endif // BOOK_H

