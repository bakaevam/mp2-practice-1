#ifndef SCANTABLE_H
#define SCANTABLE_H
#include "TArrayTable.h"

template<class TKey, class TData>
class ScanTable : public TArrayTable<TKey, TData>
{
public:
    ScanTable() : TArrayTable<TKey, TData>() {};
    ScanTable<TKey, TData>(int _tabSize) : TArrayTable<TKey, TData>(_tabSize) {};

    //Операции над таблицами
    virtual TabRecord<TKey, TData>* FindRecord(TKey key)
    {
        for (int i = 0; i < this->dataCount; i++)
        {
            if (this->pRecs[i]->GetKey() == key)
            {
                this->currPos = i;
                return this->pRecs[i];
            }
        }

        return NULL;
    }
    virtual void InsertRecord(TKey key, TData* data)
    {
        if (!this->IsFull())
        {
            this->pRecs[this->dataCount++] = new TabRecord<TKey, TData>(key, data);
        }
    }
    virtual void RemoveRecord(TKey key)
    {
        if (!this->IsEmpty())
        {
            if (FindRecord(key) != NULL)
            {
                delete this->pRecs[this->currPos];
                this->pRecs[this->currPos] = this->pRecs[--this->dataCount];
            }
        }
    }
};
#endif
