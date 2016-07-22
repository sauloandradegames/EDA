// Main.cpp
// Programa principal, usando estruturas implementadas

#include "Dlist.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "CircularList.h"
#include "Heap.h"
#include <iostream>
using namespace std;

int main()
{	
	BinTree t;
	
	t.insert(100);
	t.insert(19);
	t.insert(36);
	t.insert(17);
	t.insert(3);
	t.insert(25);
	t.insert(1);
	t.insert(2);
	t.insert(7);

	t.printPre(t.getRoot());
	cout << endl;
	
	return 0;
}

/* Objetivos: 
 * [X] Implementar lista simples
 * [X] Lista duplamente encadeada
 * [X] Lista circular
 * [X] Filas
 * [X] Pilhas
 * [X] Arvore de busca binaria
 * [ ] Heap
 */
