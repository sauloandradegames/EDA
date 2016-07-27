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

void loteria()
{
	List aposta;
	List sorteio;
	Node* alvo;
	int entrada;
	int acertos;
	
	alvo = new Node;
	entrada = 0;
	acertos = 0;
	
	cout << "Insira 6 numeros de sua aposta. \n";
	for (int i = 0; i < 6; i++)
	{
		cout << "[" << i+1 << "]: ";
		cin >> entrada;
		aposta.insert(entrada);
	}
	
	cout << "Insira 6 numeros do sorteio. \n";
	for (int i = 0; i < 6; i++)
	{
		cout << "[" << i+1 << "]: ";
		cin >> entrada;
		sorteio.insert(entrada);
	}
	
	aposta.printList();
	sorteio.printList();
	
	alvo = aposta.getHead();
	while (alvo != NULL)
	{
		if (sorteio.search(alvo->getValue()) == 0)
		{
			cout << "lol" << endl;
			acertos++;
		}
		alvo = alvo->getNext();
	}
	cout << "Voce acertou " << acertos << " de 6 numeros. \n";
	cout << acertos << endl;
}

int main()
{	
	//loteria();
	
	BinTree t;
	
	/* Exemplo de arvore balanceada */
	/*
	t.insert(8);
	t.insert(3);
	t.insert(10);
	t.insert(1);
	t.insert(6);
	t.insert(14);
	t.insert(4);
	t.insert(7);
	t.insert(13);
	*/
	
	/* Exemplo de arvore nao balanceada */
	t.insert(100);
	t.insert(90);
	t.insert(80);
	t.insert(70);
	t.insert(60);
	t.insert(50);
	
	t.printPre(t.getRoot());
	cout << endl;
	
	cout << t.getHeight(t.getRoot()) << endl;
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
