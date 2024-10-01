#include "reader.h"
reader::reader(const std::string& name, const std::string& key,
               const std::string& baccessid1, const std::string& bid1,
               const std::string& baccessid2, const std::string& bid2,
               int t_numbers, bool t_bool)// 构造函数
    : m_key(key), m_name(name), numbers(t_numbers), black(t_bool)
{
    brobooks[0] = {baccessid1, bid1};
    brobooks[1] = {baccessid2, bid2};
}
reader::reader(const reader& temp)// 拷贝构造函数
    : m_key(temp.m_key), m_name(temp.m_name), numbers(temp.numbers), black(temp.black)
{
    brobooks[0] = temp.brobooks[0];
    brobooks[1] = temp.brobooks[1];
}
reader::reader()// 默认构造函数
    : black(false), numbers(0)
{
}
reader::~reader()// 析构函数
{
}
void reader::borrow(const std::string& baccessid, const std::string& bid) {// 借书函数
    if (numbers >= 2) {
        return; // 如果已经借了两本书，不能再借
    }
    brobooks[numbers] = {baccessid, bid}; // 借书信息存储到数组中
    numbers++;
}
void reader::returnbooks(const std::string& baccessid, const std::string& bid) {// 还书函数
    for (int i = 0; i < 2; ++i) {
        if (brobooks[i].m_baccessid == baccessid && brobooks[i].m_bid == bid) {
            brobooks[i].m_baccessid = "0";
            brobooks[i].m_bid = "0"; // 清空还书信息
            numbers--;
            return; // 找到书籍并处理后退出函数
        }
    }
}
// 展示函数
std::string reader::showkey() const {
    return m_key;
}

std::string reader::showname() const {
    return m_name;
}

std::string reader::showbaccessid1() const {
    return brobooks[0].m_baccessid;
}

std::string reader::showbid1() const {
    return brobooks[0].m_bid;
}

std::string reader::showbaccessid2() const {
    return brobooks[1].m_baccessid;
}

std::string reader::showbid2() const {
    return brobooks[1].m_bid;
}

int reader::shownumbers() const {
    return numbers;
}

bool reader::showsituation() const {
    return black;
}
void reader::turn_black()
{
    black = 1;
}
void reader::turn_white()
{
    black = 0;
}
