// Queue.cpp
// Implementacao de filas usando lista encadeada

#include "Queue.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUTORES ---------------------------*/
Queue::Queue()
{
	start = NULL;
	end = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
Node* Queue::getStart()
{
	/* Retorna node do comeco da fila */
	return start;
}

Node* Queue::getEnd()
{
	/* Retorna node do final da fila */
	return end;
}

void Queue::setStart(Node* destination)
{
	/* Configura comeco da fila */
	start = destination;
}

void Queue::setEnd(Node* destination)
{
	/* Configura final da fila */
	end = destination;
}

/*--------------------------- METODOS: CRUD --------------------------*/
int Queue::enqueue(int new_value)
{
	/* Adiciona um novo elemento ao final da fila
	 * Retorna 0 se enfilerado com sucesso, -1 caso contrario.
	 */
	Node *toEnqueue = new Node(new_value);
	
	// Caso: fila vazia
	if (isEmpty() == 0)
	{
		// Caso a fila esteja vazia: start e end apontam para o novo elemento
		setStart(toEnqueue);
		setEnd(toEnqueue);
		return 0;
	}
	else
	{
		// Caso geral: Novo aponta para end, end aponta para novo elemento
		toEnqueue->setNext(getEnd());
		setEnd(toEnqueue);
		return 0;
	}
}

int Queue::dequeue()
{
	/* Remove um elemento do comeco da fila
	 * Retorna 0 se a remocao suceder, -1 caso contrario
	 */
	if (getEnd() != NULL)
	{
		Node *toDelete = new Node;
		toDelete = getEnd();
		setEnd(toDelete->getNext());
		delete toDelete;
		return 0;
	}
	return -1;
}

int Queue::isEmpty()
{
	/* Verifica se a fila esta vazia
	 * Retorna 0 caso vazia, -1 caso contrario
	 */
	if (getStart() == NULL)
	{
		return 0;
	}
	return -1;
}

void Queue::printQueue()
{
	/* Imprime a configuracao atual da fila */
	Node *toPrint = new Node;
	if (isEmpty() == 0)
	{
		cout << "|-|" << endl;
	}
	else
	{
		toPrint = getEnd();
		while (toPrint != NULL)
		{
			cout << "|" << toPrint->getValue();
			toPrint = toPrint->getNext();
		}
		cout << "|" << endl;
	}
}
