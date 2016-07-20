// CircularList.h
// Cabecalho: lista circular

#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "Node.h"

class CircularList
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		Node *head; // Ponteiro para a cabeca da lista circular (primeiro)
		Node *tail; // Ponteiro para a cauda da lista circular (ultimo)
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		CircularList(); // Construtor padrao de lista circular
		
/*------------------------ METODOS: GET E SET ------------------------*/
		Node* getHead(); // Retorna node da cabeca da lista circular
		Node* getTail(); // Retorna node da cauda da lista circular
		void setHead(Node* destination); // Configura node da cabeca da lista
		void setTail(Node* destination); // Configura node da cauda da lista
		
/*--------------------------- METODOS: CRUD --------------------------*/
		int insert(int new_value); // insere novo valor na cauda da lista, se nao existir tal valor
		int remove(int value); // remove valor da lista, se existir
		int search(int value); // busca valor na lista
		int update(int old_value, int new_value); // troca old_value por new_value, se existir
		int isEmpty(); // verifica se a lista esta vazia
		void printList(); // imprime valores da lista a partir da cabeca para a cauda
};

#endif // CIRCULARLIST_H
