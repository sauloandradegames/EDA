// Main.cpp
// Programa principal, usando estruturas implementadas

#include "BinTree.h"
#include "Dlist.h"
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "CircularList.h"
#include <iostream>
using namespace std;

int main()
{	
	BinTree t;
	
	t.insert(1);
	t.insert(15);
	
	t.printOrder(NULL);
	
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
