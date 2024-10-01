#ifndef READER_TABLE_MODEL_H
#define READER_TABLE_MODEL_H

#include <QAbstractTableModel>
#include <map>
#include <vector>
#include <QString>
#include "reader.h"

// 定义列数常量
constexpr int READER_COLUMN_COUNT = 7;

class ReaderTableModel : public QAbstractTableModel {
    Q_OBJECT

public:
    explicit ReaderTableModel(QObject *parent = nullptr)
        : QAbstractTableModel(parent), in_regula(1) // 默认为1
    {}

    // 设置读者数据
    void setReaders(const std::map<std::string, reader>& rmap) {
        beginResetModel();
        readers.clear();
        for (const auto& [id, r] : rmap) {
            readers.push_back(r);
        }
        endResetModel();
    }

    // 行数
    int rowCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return readers.size();
    }

    // 列数
    int columnCount(const QModelIndex &parent = QModelIndex()) const override {
        Q_UNUSED(parent);
        return READER_COLUMN_COUNT;
    }

    // 单元格数据
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override {
        if (!index.isValid() || index.row() >= readers.size())
            return QVariant();
        const reader &r = readers[index.row()];
        if (role == Qt::DisplayRole) {
            switch (index.column()) {
                case 0: return QString::fromStdString(r.showkey());
                case 1: return QString::fromStdString(r.showname());
                case 2: return QString::fromStdString(r.showbaccessid1());
                case 3: return QString::fromStdString(r.showbid1());
                case 4: return QString::fromStdString(r.showbaccessid2());
                case 5: return QString::fromStdString(r.showbid2());
                case 6: return r.showsituation() ? "Violated" : "Clear";
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
                case 0: return "Key";
                case 1: return "Name";
                case 2: return "Book 1 accessid";
                case 3: return "Book 1 ID";
                case 4: return "Book 2 accessid";
                case 5: return "Book 2 ID";
                case 6: return "situation";
                default: return QVariant();
            }
        }
        return QVariant();
    }

private:
    std::vector<reader> readers; // 存储读者的向量
    int in_regula; // 控制是否显示某些信息（如果需要）
};

#endif // READER_TABLE_MODEL_H
