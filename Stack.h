// Stack.h
// Cabecalho de pilhas

#ifndef STACK_H
#define STACK_H

#include "Dnode.h"

class Stack
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		Dnode *base; // Ponteiro para o ultimo elemento da pilha
		Dnode *top; // Ponteiro para o topo da pilha
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Stack(); // Construtor padrao da pilha
		
/*------------------------ METODOS: GET E SET ------------------------*/
		Dnode* getBase(); // Retorna node da base da pilha
		Dnode* getTop(); // Retorna node do topo da pilha
		void setBase(Dnode* destination); // Configura node da base da pilha
		void setTop(Dnode* destination); // Configura node do topo da pilha
		
/*--------------------------- METODOS: CRUD --------------------------*/
		int push(int new_value); // empilha um novo valor na pilha
		int pop(); // desempilha o topo da pilha, retorna o topo da pilha
		int isEmpty(); // verifica se a pilha esta vazia
		void printStack(); // imprime os valores empilhados
};

#endif // STACK_H
