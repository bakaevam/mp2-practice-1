#ifndef TABLE_H
#define TABLE_H
#include "TabRecord.h"
#include <iostream>
using namespace std;

template<class TKey, class TData>
class Table
{
protected:
    int tabSize;
    int dataCount;
    int currPos;

public:
    Table(int _tabSize) { tabSize = _tabSize; }

    //Информационные методы
    bool IsEmpty() const
    {
        return (dataCount == 0);
    }
    bool IsFull() const
    {
        return (dataCount >= tabSize);
    }
    int GetDataCount() const
    {
        return dataCount;
    }

    //Операции над наблицами
    virtual TabRecord<TKey, TData>* FindRecord(TKey key) = 0;
    virtual void InsertRecord(TKey key, TData* data) = 0;
    virtual void RemoveRecord(TKey key) = 0;

    template<class TKey, class TData>
    friend ostream& operator<<(ostream& os, Table<TKey, TData>& _table);

    //Навигация по таблице
    virtual bool IsTabEnded() const
    {
        return (currPos >= tabSize);
    }
    virtual bool Reset()
    {
        currPos = 0;
        return IsTabEnded();
    }
    virtual bool GetNext()
    {
        if (!IsTabEnded()) currPos++;
        return IsTabEnded();
    }

    //Доступ к текущей записи таблицы
    virtual TKey GetKey() const = 0;
    virtual TData* GetData() const = 0;
    virtual TabRecord<TKey, TData>* GetRecord() const = 0;
    int GetCurrPos() const { return currPos; };
};

template<class TKey, class TData>
ostream& operator<<(ostream& os, Table<TKey, TData>& _table)
{
    if (_table.IsEmpty())
        return os << " Table is empty";

    _table.Reset();
    while (!_table.IsTabEnded())
    {
        if (_table.GetRecord() != nullptr) {
            os << *_table.GetRecord() << endl;
        }
        _table.GetNext();
    }

    return os;
};
#endif
