// BinTree.h
// Cabecalho: arvore de busca binaria

#ifndef BINTREE_H
#define BINTREE_H

#include "Tnode.h"

class BinTree
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		Tnode *root; // Raiz da arvore
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		BinTree(); // Construtor padrao de arvore
		
/*------------------------ METODOS: GET E SET ------------------------*/
		Tnode* getRoot(); // Retorna node da raiz da arvore
		int getHeight(Tnode *root); // Retorna a altura da arvore de raiz root
		void setRoot(Tnode* destination); // Configura node da raiz da arvore
		
/*--------------------------- METODOS: CRUD --------------------------*/
		int insert(int value); // Insere um novo elemento na arvore
		int remove(int value); // Remove o elemento especificado na arvore
		int search(int value); // Executa uma busca em ordem na arvore
		int updateBF(Tnode* node); // Atualiza fator de balanceamento de cada node apos inserção
		int isEmpty(); // Verifica se a arvore esta vazia
		void printOrder(Tnode *node); // Imprime os nos da arvore a partir de uma busca em ordem
		void printPre(Tnode *node); // Imprime os nos da arvore a partir de uma busca pre-ordem
		void printPost(Tnode *node); // Imprime os nos da arvore a partir de uma busca pos-ordem
		void balanceCheck(Tnode *node, Tnode *prenode); // Verifica se a arvore de raiz node esta balanceada
		void rotateLeft(Tnode *preroot, Tnode *father, Tnode *pivot); // Executa rotacao esquerda na arvore de raiz father
		void rotateRight(Tnode *preroot, Tnode *father, Tnode *pivot); // Executa rotacao direita na arvore de raiz father
		void rotateDoubleLeft(Tnode *preroot, Tnode *father, Tnode *pivot); // Executa rotacao dupla a esquerda na arvore de raiz father
		void rotateDoubleRight(Tnode *preroot, Tnode *father, Tnode *pivot); // Executa rotacao dupla a direita na arvore de raiz father
		//TODO: criar metodo para balanceamento da arvore
};

#endif // BINTREE_H
