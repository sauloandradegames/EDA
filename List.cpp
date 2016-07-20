// List.cpp

#include "List.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUTORES ---------------------------*/
List::List()
{
	head = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
Node* List::getHead()
{
	/* Retorna node da cabeca da lista */
	return head;
}

void List::setHead(Node* destination)
{
	/* Configura node da cabeca da lista */
	head = destination;
}

/*--------------------------- METODOS: CRUD --------------------------*/
int List::insert(int new_value)
{
	/* Insere new_value no final da lista, se nao existir.
	 * Retorna 0 se inserido com exito, -1 caso contrario.
	 */
	
	// Verificar se new_value ja existe na lista usando Search()
	if (search(new_value) != 0)
	{
		Node *toInsert = new Node(new_value); // Novo node que sera inserido
		Node *where = new Node; // Ponteiro para localizar onde inserir
		
		if (isEmpty() == 0)
		{
			// Se a lista eh vazia, insira na cabeca
			head = toInsert;
			return 0;
		}
		// Se nao, procure o final da lista para inserir
		where = head;
		while (where->getNext() != NULL)
		{
			where = where->getNext();
		}
		where->setNext(toInsert);
		return 0;
	}
	return 1; // Se new_value ja consta na lista, nao insira
}

int List::remove(int value)
{
	/* Remove value da lista, se existir
	 * Retorna 0 se removido com exito, -1 caso contrario
	 */
	 Node *toDelete = new Node;
	 
	 if (search(value) == 0)
	 {
		 Node *p = new Node;
		 
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
			 p->setNext(p->getNext()->getNext());
			 delete toDelete;
			 return 0;
		 }
	 }
	 return -1;
}

int List::search(int value)
{
	/* Varre a lista, verifica se value consta na lista
	 * Retorna 0 se achar, -1 se nao achar
	 */
	 
	 Node *p; // Ponteiro que varre a lista
	 
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

int List::update(int old_value, int new_value)
{
	/* Troca old_value (se existir) por new_value
	 * Retorna 0 se atualizado, -1 caso contrario
	 */
	 
	 // Procure old_value
	 if (search(old_value) == 0)
	 {
		 Node *toUpdate = new Node; // Ponteiro para o node a ser atualizado
		 
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

int List::isEmpty()
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

void List::printList()
{
	/* Imprime a lista */
	if (isEmpty() == 0)
	{
		cout << "|-|" << endl;
	}
	else
	{
		Node *p = new Node;
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
