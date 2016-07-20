// Dlist.h
// Cabecalho: lista duplamente encadeada

#ifndef DLIST_H
#define DLIST_H

#include "Dnode.h"

class Dlist
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		Dnode *head; // Ponteiro para o primeiro elemento da lista (cabeca da lista)

	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Dlist(); // Construtor padrao de lista
		
/*------------------------ METODOS: GET E SET ------------------------*/
		Dnode* getHead(); // Retorna o node da cabeca da lista
		void setHead(Dnode* destination); // Configura a cabeca da lista
		
/*--------------------------- METODOS: CRUD --------------------------*/
		int insert(int new_value); // insere novo valor no fim da lista, se nao existir
		int remove(int value); // remove valor da lista, se existir
		int search(int value); // busca valor na lista
		int update(int old_value, int new_value); // troca old_value por new_value, se existir
		int isEmpty(); // verifica se a lista esta vazia
		void printList(); // imprime valores da lista a partir da cabeca da lista;
		void printListDesc(); // imprime valores da lista a partir do final da lista
};

#endif // DLIST_H
