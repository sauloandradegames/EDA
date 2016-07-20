// Dlist.cpp
// Implementacao de lista duplamente encadeada

#include "Dlist.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUTORES ---------------------------*/
Dlist::Dlist()
{
	head = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
Dnode* Dlist::getHead()
{
	/* Retorna o node da cabeca da lista */
	return head;
}

void Dlist::setHead(Dnode* destination)
{
	/* Configura a cabeca da lista */
	head = destination;
}

/*--------------------------- METODOS: CRUD --------------------------*/
int Dlist::insert(int new_value)
{
	/* Insere new_value no final da lista, se nao existir.
	 * Retorna 0 se inserido com exito, -1 caso contrario.
	 */
	
	// Verificar se new_value ja existe na lista usando Search()
	if (search(new_value) != 0)
	{
		Dnode *toInsert = new Dnode(new_value); // Novo node que sera inserido
		Dnode *where = new Dnode; // Ponteiro para localizar onde inserir
		
		if (isEmpty() == 0)
		{
			// Se a lista eh vazia, insira na cabeca
			setHead(toInsert);
			return 0;
		}
		// Se nao, procure o final da lista para inserir
		where = head;
		while (where->getNext() != NULL)
		{
			where = where->getNext();
		}
		toInsert->setPrev(where);
		where->setNext(toInsert);
		return 0;
	}
	return 1; // Se new_value ja consta na lista, nao insira
}

int Dlist::remove(int value)
{
	/* Remove value da lista, se existir
	 * Retorna 0 se removido com exito, -1 caso contrario
	 */
	 Dnode *toDelete = new Dnode;
	 
	 if (search(value) == 0)
	 {
		 Dnode *p = new Dnode; // ponteiro para o node anterior ao node a ser deletado
		 Dnode *n = new Dnode; // ponteiro para o node proximo ao node a ser deletado
		 
		 // Remover a cabeca da lista: cabeca aponta para o proximo da lista
		 if (head->getValue() == value)
		 {
			 toDelete = head;
			 head = head->getNext();
			 delete toDelete;
			 return 0;
		 }
		 else
		 {
			 // Varrer a lista e achar o elemento
			 // Fazer o anterior do elemento a ser removido apontar para o proximo do elemento a ser removido
			 p = head;
			 while (p->getNext()->getValue() != value)
			 {
				 p = p->getNext();
			 }
			 toDelete = p->getNext();
			 if (toDelete->getNext() != NULL)
			 {
				 n = toDelete->getNext();
				 n->setPrev(n->getPrev()->getPrev());
			 }
			 p->setNext(p->getNext()->getNext());
			 delete toDelete;
			 return 0;
		 }
	 }
	 return -1;
}

int Dlist::search(int value)
{
	/* Varre a lista, verifica se value consta na lista
	 * Retorna 0 se achar, -1 se nao achar
	 */
	 
	 Dnode *p; // Ponteiro que varre a lista
	 
	 // Verifique se lista vazia
	 if (isEmpty() != 0)
	 {
		 // Varrer a lista ate achar
		 p = head;
		 do
		 {
			 if (p->getValue() == value)
			 {
				 return 0;
			 }
			 p = p->getNext();
		 } while (p != NULL);
		 return 1;
	 }
	 return 1;
}

int Dlist::update(int old_value, int new_value)
{
	/* Troca old_value (se existir) por new_value
	 * Retorna 0 se atualizado, -1 caso contrario
	 */
	 
	 // Procure old_value
	 if (search(old_value) == 0)
	 {
		 Dnode *toUpdate = new Dnode; // Ponteiro para o node a ser atualizado
		 
		 // Se old_value eh cabeca da lista
		 if (head->getValue() == old_value)
		 {
			 head->setValue(new_value);
			 return 0;
		 }
		 else
		 {
			toUpdate = head;
			while (toUpdate->getNext()->getValue() != old_value)
			{
				toUpdate = toUpdate->getNext();
			}
			toUpdate = toUpdate->getNext();
			toUpdate->setValue(new_value);
			return 0;
		 }
	 }
	 return 1;
}

int Dlist::isEmpty()
{
	/* Verifica se a lista esta vazia 
	 * Retorna 0 se vazia, -1 caso contrario
	 */
	 
	 if (head == NULL)
	 {
		 return 0;
	 }
	 return 1;
}

void Dlist::printList()
{
	/* Imprime a lista a partir da cabeca da lista */
	if (isEmpty() == 0)
	{
		cout << "|-|" << endl;
	}
	else
	{
		Dnode *p = new Dnode;
		p = head;
		cout << "|" << head->getValue();
		while (p->getNext() != NULL)
		{
			cout << "|" << p->getNext()->getValue();
			p = p->getNext();
		}
		cout << "|" << endl;
	}
}

void Dlist::printListDesc()
{
	/* Imprime a lista a partir do final da lista */
	if (isEmpty() == 0)
	{
		cout << "|-|" << endl;
	}
	else
	{
		Dnode *p = new Dnode;
		p = head;
		
		// Avance ate o final da lista
		while(p->getNext() != NULL)
		{
			p = p->getNext();
		}
		
		// Comece a imprimir
		cout << "|" << p->getValue();
		while (p->getPrev() != NULL)
		{
			cout << "|" << p->getPrev()->getValue();
			p = p->getPrev();
		}
		cout << "|" << endl;
	}
}

