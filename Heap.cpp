// Heap.cpp
// Implementacao de Heap usando arvore de busca binaria

#include "Heap.h"

Heap::Heap(){}

Tnode* Heap::getMaxHeap()
{
	return getRoot();
}

//int deleteMinHeap();
//void merge();
//void heapify();
