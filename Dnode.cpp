// Dnode.cpp
// Implementacao de node duplo (2 ponteiros)
// Usado para pilhas, filas, arvores e heaps

#include "Dnode.h"
#include <iostream>

/*--------------------------- CONSTRUTORES ---------------------------*/
Dnode::Dnode()
{
	/* Construtor padrao */
	next = NULL;
	prev = NULL;
}

Dnode::Dnode(int v)
{
	/* Construtor inicializando value */
	value = v;
	next = NULL;
	prev = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
int Dnode::getValue()
{
	return value;
}

void Dnode::setValue(int v)
{
	value = v;
}

Dnode* Dnode::getNext()
{
	return next;
}

Dnode* Dnode::getPrev()
{
	return prev;
}

void Dnode::setNext(Dnode* destination)
{
	next = destination;
}

void Dnode::setPrev(Dnode* destination)
{
	prev = destination;
}
