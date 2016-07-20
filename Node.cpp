// Node.cpp
// Implementacao de node simples (1 ponteiro)

#include "Node.h"
#include <iostream>

/*--------------------------- CONSTRUTORES ---------------------------*/
Node::Node()
{
	next = NULL;
}

Node::Node(int v)
{
	value = v;
	next = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
int Node::getValue()
{
	return value;
}

void Node::setValue(int v)
{
	value = v;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* destination)
{
	next = destination;
}
