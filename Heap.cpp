// Heap.cpp
// Implementacao de Heap usando arvore de busca binaria

#include "Heap.h"

Heap::Heap(){}

Dnode* Heap::getMaxHeap()
{
	return getRoot();
}

//int deleteMinHeap();
//void merge();
//void heapify();
