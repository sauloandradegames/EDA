// Node.h
// Cabecalho de node simples (1 ponteiro)
// Usado para listas encadeadas

#ifndef NODE_H
#define NODE_H

class Node
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		int value; // Valor de chave
		Node *next; // Ponteiro para proximo node
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Node(); // Construtor padrao
		Node(int v); // Construtor com insercao de valor
		
/*------------------------ METODOS: GET E SET ------------------------*/
		int getValue(); // Retorna valor armazenado no node
		Node* getNext(); // Retorna node apontado por next
		void setValue(int v); // Configura valor do node
		void setNext(Node* destination); // Configura proximo node
};

#endif // NODE_H
