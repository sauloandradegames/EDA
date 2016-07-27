// Tnode.cpp
// Implementacao de node para arvore de busca binaria e heap

#include <iostream>
#include "Tnode.h"

/*--------------------------- CONSTRUTORES ---------------------------*/
Tnode::Tnode()
{
	// Construtor padrao
	balance_factor = 0;
	left = NULL;
	right = NULL;
}

Tnode::Tnode(int new_value)
{
	// Construtor com inicializacao de value
	balance_factor = 0;
	value = new_value;
	left = NULL;
	right = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
int Tnode::getBalanceFactor()
{
	/* Retorna o fator de balanceamento do node*/
	return balance_factor;
}

int Tnode::getValue()
{
	/* Retorna o valor guardado no node */
	return value;
}

Tnode* Tnode::getLeft()
{
	/* Retorna o node filho a esquerda */
	return left;
}

Tnode* Tnode::getRight()
{
	/* Retorna o node filho a direita */
	return right;
}

void Tnode::setLeft(Tnode* destination)
{
	/* Configura node a esquerda */
	left = destination;
}

void Tnode::setRight(Tnode* destination)
{
	/* Configura node a direita */
	right = destination;
}

void Tnode::setValue(int new_value)
{
	/* Ajusta new_value como valor do node */
	value = new_value;
}

void Tnode::setBalanceFactor(int new_bf)
{
	/* Ajusta new_bf como fator de balanceamento do node */
	balance_factor = new_bf;
}
