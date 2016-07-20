// List.h
// Implementacao de lista encadeada

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		Node *head; // Ponteiro para o primeiro elemento da lista (cabeca da lista)
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		List(); // Construtor padrao de lista
		
/*------------------------ METODOS: GET E SET ------------------------*/
		Node* getHead(); // Retorna node da cabeca da lista
		void setHead(Node* destination); // Configura node da cabeca da lista
		
/*--------------------------- METODOS: CRUD --------------------------*/
		int insert(int new_value); // insere novo valor no fim da lista, se nao existir
		int remove(int value); // remove valor da lista, se existir
		int search(int value); // busca valor na lista
		int update(int old_value, int new_value); // troca old_value por new_value, se existir
		int isEmpty(); // verifica se a lista esta vazia
		void printList(); // imprime valores da lista;
};

#endif // LIST_H
