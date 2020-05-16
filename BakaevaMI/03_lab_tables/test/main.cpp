#include "..\include\ScanTable.h"
#include <iostream>
using namespace std;

void main()
{
    ScanTable<int, string> tab1(3);
    string* a = { "test" };
    a[0] = 15;
    a[1] = 3;

    tab1.InsertRecord(1, a);
    tab1.InsertRecord(2, a);
    cout << tab1;
    cout << tab1.FindRecord(2);

};