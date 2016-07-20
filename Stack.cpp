// Stack.cpp
// Implementacao de pilha

#include "Stack.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUTORES ---------------------------*/
Stack::Stack()
{
	base = NULL;
	top = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
Dnode* Stack::getBase()
{
	/* Retorna node da base da pilha */
	return base;
}

Dnode* Stack::getTop()
{
	/* Retorna node do topo da pilha */
	return top;
}

void Stack::setBase(Dnode* destination)
{
	/* Configura node da base da pilha */
	base = destination;
}

void Stack::setTop(Dnode* destination)
{
	/* Configura node do topo da pilha */
	top = destination;
}
		
/*--------------------------- METODOS: CRUD --------------------------*/
int Stack::push(int new_value)
{
	/* Empilha um novo valor na pilha
	 * Retorna -1 em caso de erro.
	 */
	Dnode *toPush = new Dnode(new_value);
	
	if (this->isEmpty() == 0)
	{
		base = toPush;
		top = toPush;
		return 0;
	}
	else
	{
		top->setNext(toPush);
		toPush->setPrev(top);
		top = top->getNext();
		return 0;
	}
	return -1;
}

int Stack::pop()
{
	/* Desempilha o topo da pilha
	 * Retorna o valor armazenado no topo da pilha, -1 em caso de erro.*/
	int popValue; // Armazena valor do topo da pilha
	Dnode *toDelete; // Ponteiro para node a ser removido
	
	if (isEmpty() != 0)
	{
		if (base == top)
		{
			popValue = getTop()->getValue();
			base = NULL;
			delete top;
			return popValue;
		}
		else
		{
			popValue = getTop()->getValue();
			toDelete = top;
			top = top->getPrev();
			top->setNext(NULL);
			delete toDelete;
			return popValue;
		}
	}
	return -1;
	
}

int Stack::isEmpty() // verifica se a pilha esta vazia
{
	/* Verifica se a pilha esta vazia
	 * Retorna 0 se pilha vazia, -1 caso contrario
	 */
	if (base == NULL)
	{
		return 0;
	}
	return -1;
}

void Stack::printStack()
{
	/* Imprime valores empilhados */
	if (isEmpty() == 0)
	{
		cout << "|-|" << endl;
	}
	else
	{
		Dnode *p = new Dnode;
		p = base;
		cout << "|" << base->getValue();
		while (p->getNext() != NULL)
		{
			cout << "|" << p->getNext()->getValue();
			p = p->getNext();
		}
		cout << "|" << endl;
	}
}
