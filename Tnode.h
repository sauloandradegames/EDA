// Tnode.h
// Cabecalho: Node para arvore

#ifndef TNODE_H
#define TNODE_H

class Tnode
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		int height; // Altura do node em relacao a raiz da arvore (0 = raiz)
		int value; // Valor armazenado no node
		Tnode* left; // Ponteiro para o filho a esquerda do node
		Tnode* right; // Ponteiro para o filho a direita do node
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Tnode(); // Construtor padrao
		Tnode(int value); // Construtor com inicializacao de value
/*------------------------ METODOS: GET E SET ------------------------*/
		int getHeight(); // Retorna a altura do node
		int getValue(); // Retorna o valor guardado no node
		Tnode* getLeft(); // Retorna o node filho a esquerda
		Tnode* getRight(); // Retorna o node filho a direita
		void setValue(int new_value); // Ajusta new_value como valor do node
		void incHeight(); // Incrementa em 1 a altura do node
		void decHeight(); // Decrementa em 1 a altura do node
};

#endif // TNODE_H
