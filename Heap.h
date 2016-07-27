// Heap.h
// Cabecalho: heap

#ifndef HEAP_H
#define HEAP_H

#include "Tnode.h"
#include "BinTree.h"

class Heap : public BinTree
{
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Heap();
/*------------------------ METODOS: GET E SET ------------------------*/
		Tnode* getMaxHeap();
/*--------------------------- METODOS: CRUD --------------------------*/
		int deleteMinHeap();
		void merge();
		void heapify();
};
		
#endif // HEAP_H
