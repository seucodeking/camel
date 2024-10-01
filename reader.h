#ifndef READER_H
#define READER_H

#include <string>

// 结构体用于表示书籍信息
struct ibook {
    std::string m_baccessid; // 书籍ID
    std::string m_bid; // 书籍名称
};

// reader 类用于表示读者信息及其借阅情况
class reader {
public:
    // 构造函数
    reader(const std::string& name, const std::string& key,
           const std::string& baccessid1 = "0", const std::string& bid1 = "0",
           const std::string& baccessid2 = "0", const std::string& bid2 = "0",
           int t_numbers = 0, bool t_bool = false);

    // 拷贝构造函数
    reader(const reader& temp);

    // 默认构造函数
    reader();

    // 析构函数
    ~reader();

    // 借书函数
    void borrow(const std::string& baccessid, const std::string& bid);

    // 还书函数
    void returnbooks(const std::string& baccessid, const std::string& bid);

    // 访问器方法
    std::string showkey() const; // 显示读者的唯一标识
    std::string showname() const; // 显示读者的名字
    std::string showbaccessid1() const; // 显示第一个借书的ID
    std::string showbid1() const; // 显示第一个借书的名称
    std::string showbaccessid2() const; // 显示第二个借书的ID
    std::string showbid2() const; // 显示第二个借书的名称
    int shownumbers() const; // 显示当前借书数量
    bool showsituation() const; // 显示是否有黑名单标记
   void turn_black();
   void turn_white();
private:
    std::string m_key; // 读者的唯一标识
    std::string m_name; // 读者的名字
    ibook brobooks[2]; // 存储借阅的书籍信息
    int numbers; // 当前借书数量
    bool black = 0; // 黑名单标记（是否有欠款或违章记录）
};

#endif // READER_H
