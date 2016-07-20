// BinTree.h
// Cabecalho: arvore de busca binaria

#ifndef BINTREE_H
#define BINTREE_H

#include "Dnode.h"

class BinTree
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		Dnode *root; // Raiz da arvore
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		BinTree(); // Construtor padrao de arvore
		
/*------------------------ METODOS: GET E SET ------------------------*/
		Dnode* getRoot(); // Retorna node da raiz da arvore
		void setRoot(Dnode* destination); // Configura node da raiz da arvore
		
/*--------------------------- METODOS: CRUD --------------------------*/
		int insert(int value); // Insere um novo elemento na arvore
		int remove(int value); // Remove o elemento especificado na arvore
		int search(int value); // Executa uma busca em ordem na arvore
		int isEmpty(); // Verifica se a arvore esta vazia
		int printOrder(Dnode *node); // Imprime os nos da arvore a partir de uma busca em ordem
		int printPre(Dnode *node); // Imprime os nos da arvore a partir de uma busca pre-ordem
		int printPost(Dnode *node); // Imprime os nos da arvore a partir de uma busca pos-ordem
		//TODO: criar metodo para balanceamento da arvore
};

#endif // BINTREE_H
