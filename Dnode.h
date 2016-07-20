// Dnode.h
// Cabecalho: node duplo (2 ponteiros)
// Usado para pilhas, filas, arvores e heaps

#ifndef DNODE_H
#define DNODE_H

class Dnode
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		int value; // Valor de chave
		Dnode *next; // Ponteiro para proximo node
		Dnode *prev; // Ponteiro para node anterior
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Dnode(); // Construtor padrao
		Dnode(int v); // Construtor com insercao de valor
		
/*------------------------ METODOS: GET E SET ------------------------*/
		int getValue(); // Retorna valor armazenado no node
		Dnode* getNext(); // Retorna node apontado por next
		Dnode* getPrev(); // Retorna node apontado por prev
		void setValue(int v); // Configura valor do node
		void setNext(Dnode* destination); // Configura proximo node
		void setPrev(Dnode* destination); // Configura node anterior
};

#endif // DNODE_H
