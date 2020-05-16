#ifndef TABRECORD_H
#define TABRECORD_H
#include <iostream>

using namespace std;

template<class TKey, class TData>
class TabRecord
{
protected:
    TKey key;
    TData* data;

public:
    TabRecord(TKey _key, TData* _data)
    {
        key = _key;
        data = _data;
    }


    TData* GetData() { return data; }
    TKey GetKey() { return key; }

    void SetKey(TKey _key) { key = _key; }
    void SetData(TData _data) { data = _data; }

   /* TabRecord& operator=(TabRecord& _tabRecord);
    virtual bool operator==(const TabRecord& _tabRecord);
    virtual bool operator<(const TabRecord& _tabRecord);
    virtual bool operator>(const TabRecord& _tabRecord);*/

    template<class TKey, class TData>
    friend ostream& operator<<(ostream& os, TabRecord<TKey, TData> _record);
};

template<class TKey, class TData>
ostream& operator<<(ostream& os, TabRecord<TKey, TData> _record)
{
    os << _record.GetKey() << " | " << _record.GetData();
    return os;
}
#endif
