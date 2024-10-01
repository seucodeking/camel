#ifndef BOOK_TABLE_MODEL_H
#define BOOK_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <map>
#include <vector>
#include <QString>
#include "book.h"

// 定义列数常量
constexpr int COLUMN_COUNT = 9;

class BookTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit BookTableModel(QObject *parent = nullptr)
        : QAbstractTableModel(parent), in_regula(1) // 默认为1
    {}

    // 设置书籍数据
    void setBooks(const std::map<std::string, book>& bmap) {
        beginResetModel();
        books.clear();
        for (const auto& [id, b] : bmap) {//循环填入数据
            books.push_back(b);
        }
        endResetModel();
    }

    // 行数
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return books.size();
    }

    // 列数
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return COLUMN_COUNT;
    }

    // 单元格数据
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || index.row() >= int(books.size()))
            return QVariant();

        const book &b = books[index.row()];

        if (role == Qt::DisplayRole) {
            switch (index.column()) {
                case 0: return QString::fromStdString(b.showid());
                case 1: return QString::fromStdString(b.showname());
                case 2: return QString::fromStdString(b.showwritername());
                case 3: return QString::fromStdString(b.showaccid());
                case 4: return QString::fromStdString(b.showreaderid());
                case 5: return b.outsit() ? "Yes" : "No";
                case 6: return b.showday();
                case 7: return b.showmonth();
                case 8: return b.showyear();
                default: return QVariant();
            }
        }
        return QVariant();
    }

    // 表头数据
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override {
        if (role != Qt::DisplayRole)
            return QVariant();

        if (orientation == Qt::Horizontal) {
            switch (section) {
                case 0: return "ID";
                case 1: return "Name";
                case 2: return "Writer";
                case 3: return "Access ID";
                case 4: return "Reader ID";
                case 5: return "Out Status";
                case 6: return "Day";
                case 7: return "Month";
                case 8: return "Year";
                default: return QVariant();
            }
        }
        return QVariant();
    }
private:
    std::vector<book> books; // 存储书籍的向量
    int in_regula; // 控制是否显示 Reader ID
};

#endif // BOOK_TABLE_MODEL_H

