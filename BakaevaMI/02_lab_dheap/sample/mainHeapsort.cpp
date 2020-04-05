#include <iostream>
#include "../include/DHeap.h"
#include "../include/Heapsort.h"
#include <ctime>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int sizeArr = 0;
	int rangeA = 0;
	int rangeB = 0;
	srand((unsigned int)time(NULL));

	cout << "\t -Heapsort-" << endl;

	do
	{
		cout << "  Enter size of array ";
		cin >> sizeArr;
	} while (sizeArr <= 0);

	do
	{
		cout << "  Enter beginning of range ";
		cin >> rangeA;

		cout << "  Enter ending of range ";
		cin >> rangeB;
	} while (rangeA > rangeB);

	float* a = new float[sizeArr];

	for (int i = 0; i < sizeArr; i++)
	{
		a[i] = (float)(rand() % rangeB + rangeA);
	}

	//����� ������ �������
	for (int i = 0; i < sizeArr; i++)
		cout << " " << a[i];

	cout << endl; 
	Heapsort<float>::HeapSort(a, sizeArr);
	
	//����� ���������������� �������
	for(int i = 0; i < sizeArr; i++)
		cout << " " << a[i];

	delete[] a;
}
