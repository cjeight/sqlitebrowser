#ifndef SQLITETABLEMODEL_H
#define SQLITETABLEMODEL_H

#include <QAbstractTableModel>
#include <QStringList>

class DBBrowserDB;

class SqliteTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit SqliteTableModel(QObject *parent = 0, DBBrowserDB* db = 0);

    int rowCount(const QModelIndex &parent) const;
    int totalRowCount() const;
    int columnCount(const QModelIndex &parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole);
    bool canFetchMore(const QModelIndex &parent) const;
    void fetchMore(const QModelIndex &parent);
    size_t queryMore(size_t offset);

    void setQuery(const QString& sQuery);
    void setTable(const QString& table);
    void setChunkSize(size_t chunksize);
    void sort(int column, Qt::SortOrder order = Qt::AscendingOrder);

    Qt::ItemFlags flags(const QModelIndex& index) const;

signals:
    
public slots:

private:
    DBBrowserDB* m_db;
    int m_rowCount;
    int m_columnCount;
    QStringList m_headers;
    QMap<int, QStringList> m_data;

    QString m_sQuery;
    QString m_sTable;
    int m_iSortColumn;
    QString m_sSortOrder;

    size_t m_chunkSize;
};

#endif // SQLITETABLEMODEL_H
