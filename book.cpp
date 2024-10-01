#include "book.h"

book::book(const std::string& bookname, const std::string& writername,
           const std::string& bookid, const std::string& accessid,
           const std::string& readerid, bool out, int day, int month, int year)
    : m_bookname(bookname), m_writername(writername), m_boookid(bookid),
      m_accessid(accessid), m_readerid(readerid), m_bout(out),
      borrowdate{day, month, year} //构造函数，初始化
{

}
book::book(const book& other)//拷贝构造函数
    : m_bookname(other.m_bookname), m_writername(other.m_writername),
      m_boookid(other.m_boookid), m_accessid(other.m_accessid),
      m_readerid(other.m_readerid), m_bout(other.m_bout),
      borrowdate(other.borrowdate)
{
}
book::book()//默认构造函数
    : m_bout(false), borrowdate{0, 0, 0}
{
}
book::~book()//析构函数
{
}
void book::borrowbook(const std::string& readerid, int day, int month, int year)//借书
{
    m_readerid = readerid;
    borrowdate.m_day = day;
    borrowdate.m_month = month;
    borrowdate.m_year = year;
    m_bout = true;
}
void book::returnbook()//还书
{
    borrowdate.m_day = 0;
    borrowdate.m_month = 0;
    borrowdate.m_year = 0;
    m_readerid = "NA";
    m_bout = false;
}
//各个展示函数
std::string book::showid() const { return m_boookid; }
std::string book::showname() const { return m_bookname; }
std::string book::showwritername() const { return m_writername; }
std::string book::showaccid() const { return m_accessid; }
std::string book::showreaderid() const { return m_readerid; }
int book::outsit() const { return m_bout ? 1 : 0; } // 布尔值转换为整数值
int book::showday() const { return borrowdate.m_day; }
int book::showmonth() const { return borrowdate.m_month; }
int book::showyear() const { return borrowdate.m_year; }
