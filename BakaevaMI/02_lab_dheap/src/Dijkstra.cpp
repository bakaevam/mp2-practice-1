#include "../include/Dijkstra.h"
#include "../include/Graph.h"
#include "../include/Pair.h"
#include <utility>

void Dijkstra::DijkstraAlg(const Graph& gr, int start)
{
	int* visited = new int[gr.GetSize()];
	Pair* dist = new Pair[gr.GetSize()];

	memset(visited, 0, sizeof(int) * gr.GetSize()); //������������ �������

	for (int i = 0; i < gr.GetSize(); i++)
	{
		dist[i].SetFirst(i); // �������
		dist[i].SetSecond(INT_MAX); //�����
	}

	dist[start].SetSecond(0);

	//�� ��������� ����� ��������� ������������ �������
	TDHeap<Pair> heapVisited(gr.GetSize(), 2, dist, gr.GetSize());
	heapVisited.Hilling();

	for (int i = 0; i < heapVisited.GetSize(); i++)
	{
		Pair min = heapVisited.GetElements()[0];

	}
};