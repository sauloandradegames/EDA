// Tnode.h
// Cabecalho: Node para arvore

#ifndef TNODE_H
#define TNODE_H

class Tnode
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		int balance_factor; // Fator de balanceamento do node
		int value; // Valor armazenado no node
		Tnode* left; // Ponteiro para o filho a esquerda do node
		Tnode* right; // Ponteiro para o filho a direita do node
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Tnode(); // Construtor padrao
		Tnode(int new_value); // Construtor com inicializacao de value
/*------------------------ METODOS: GET E SET ------------------------*/
		int getBalanceFactor(); // Retorna o fator de balanceamento do node
		int getValue(); // Retorna o valor guardado no node
		Tnode* getLeft(); // Retorna o node filho a esquerda
		Tnode* getRight(); // Retorna o node filho a direita
		void setLeft(Tnode* destination); // Configura node a esquerda
		void setRight(Tnode* destination); // Configura node a direita
		void setValue(int new_value); // Ajusta new_value como valor do node
		void setBalanceFactor(int new_bf); // Ajusta new_bf como fator de balanceamento do node
};

#endif // TNODE_H
