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
	Heap t;
	
	t.insert(60);
	t.insert(33);
	t.insert(44);
	
	t.printOrder(t.getRoot());
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
