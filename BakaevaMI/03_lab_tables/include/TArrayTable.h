#ifndef TARRAYTABLE_H
#define TARRAYTABLE_H
#include "TabRecord.h"
#include "Table.h"
#define TabMaxSize 25

template<class TKey, class TData>
class TArrayTable : public Table<TKey, TData>
{
protected:
    TabRecord<TKey, TData>** pRecs;
public:
    TArrayTable() : Table<TKey, TData>(), pRecs(nullptr) {};
    TArrayTable(int _tabSize);
    ~TArrayTable();

    //Доступ
    virtual TKey GetKey() const;
    virtual TData* GetData() const;
    TabRecord<TKey, TData>* GetRecord() const;

   // friend TSortTable<TKey, TData>;
};

template<class TKey, class TData>
TArrayTable<TKey, TData>::TArrayTable(int _tabSize): Table<TKey, TData>(_tabSize)
{
    pRecs = new TabRecord<TKey, TData>*[this->tabSize];
    for (int i = 0; i < this->tabSize; i++)
         pRecs[i] = nullptr;
};

template<class TKey, class TData>
TArrayTable<TKey, TData>::~TArrayTable()
{
    for (int i = 0; i < this->tabSize; i++)
        delete pRecs[i];
    delete[] pRecs;

    this->tabSize = this->dataCount = this->currPos = 0;
};

template<class TKey, class TData>
TKey TArrayTable<TKey, TData>::GetKey() const
{
    return pRecs[this->GetCurrPos()]->GetKey();
};

template<class TKey, class TData>
TData* TArrayTable<TKey, TData>::GetData() const
{
    return pRecs[this->GetCurrPos()]->GetData();
};

template<class TKey, class TData>
TabRecord<TKey, TData>* TArrayTable<TKey, TData>::GetRecord() const
{
    return pRecs[this->GetCurrPos()];
};

#endif
