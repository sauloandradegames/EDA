// CircularList.cpp
// Implementacao de lista circular usando lista duplamente encadeada

#include "CircularList.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUTORES ---------------------------*/
CircularList::CircularList()
{
	/* Construtor padrao de lista circular */
	head = NULL;
	tail = NULL;
}
		
/*------------------------ METODOS: GET E SET ------------------------*/
Node* CircularList::getHead()
{
	/* Retorna node da cabeca da lista circular */
	return head;
}

Node* CircularList::getTail()
{
	/* Retorna node da cauda da lista circular */
	return tail;
}

void CircularList::setHead(Node* destination)
{
	/* Configura node da cabeca da lista */
	head = destination;
}

void CircularList::setTail(Node* destination)
{
	/* Configura node da cauda da lista */
	tail = destination;
}
		
/*--------------------------- METODOS: CRUD --------------------------*/
int CircularList::insert(int new_value)
{
	/* Insere novo valor na cauda da lista, se nao existir tal valor
	 * Retorna 0 em caso de insercao com exito, -1 caso contrario.
	 */
	Node *toInsert = new Node(new_value);
	
	if (search(new_value) != 0)
	{
		if (isEmpty() == 0)
		{
			// Caso lista vazia:
			setHead(toInsert);
			setTail(toInsert);
			toInsert->setNext(toInsert);
			return 0;
		}
		else
		{
			// Caso geral: cauda->next aponta para novo, novo->next aponta para cabeca
			tail->setNext(toInsert);
			toInsert->setNext(head);
			setTail(toInsert);
			return 0;
		}
	}
	return -1;
}

int CircularList::remove(int value)
{
	/* Remove valor da lista, se existir
	 * Retorna 0 se elemento for removido, -1 caso contrario
	 */
	Node *toRemove = new Node; // Ponteiro para o node a ser removido
	Node *preRemove = new Node; // Ponteiro para o node anterior ao node a ser removido
	
	if (search(value) == 0)
	{
		toRemove = getHead();
		preRemove = getTail();
		if (head == tail)
		{
			setHead(NULL);
			setTail(NULL);
			delete toRemove;
			return 0;
		}
		else
		{
			while (toRemove->getValue() != value)
			{
				preRemove = toRemove;
				toRemove = toRemove->getNext();
			}
			preRemove->setNext(toRemove->getNext());
			if (toRemove == getHead())
			{
				setHead(head->getNext());
			}
			else if (toRemove == getTail())
			{
				setTail(preRemove);
			}
			delete toRemove;
			return 0;
		}

	}
	return -1;
}

int CircularList::search(int value)
{
	/* Busca valor na lista
	 * Retorna 0 caso valor exista na lista, -1 caso contrario
	 */
	Node *target = new Node;
	target = getHead();
	if (isEmpty() != 0)
	{
		while (target != tail)
		{
			if (target->getValue() == value)
			{
				return 0;
			}
			target = target->getNext();
		}
		if (target->getValue() == value)
		{
			return 0;
		}
	}
	return -1;
}

int CircularList::update(int old_value, int new_value)
{
	/* Troca old_value por new_value, se existir
	 * Retorna 0 se elemento for atualizado, -1 caso contrario
	 */
	Node *toUpdate = new Node;
	
	if (search(old_value) == 0)
	{
		toUpdate = getHead();
		while (toUpdate->getValue() != old_value)
		{
			toUpdate = toUpdate->getNext();
		}
		toUpdate->setValue(new_value);
		return 0;
	}
	return -1;
}

int CircularList::isEmpty()
{
	/* Verifica se a lista esta vazia
	 * Retorna 0 caso lista vazia, -1 caso contrario
	 */
	if (head == NULL)
	{
		return 0;
	}
	return -1;
}

void CircularList::printList()
{
	/* Imprime valores da lista a partir da cabeca para a cauda */
	Node *toPrint = new Node; // ponteiro para o proximo elemento a ser impresso
	
	if (isEmpty() == 0)
	{
		cout << "|-|" << endl;
	}
	else
	{
		toPrint = getHead();
		while(toPrint != getTail())
		{
			cout << "|" << toPrint->getValue();
			toPrint = toPrint->getNext();
		}
		cout << "|" << toPrint->getValue() << "|" << endl;
	}
}
