// BinTree.cpp
// Implementacao de arvore de busca binaria

// TODO: CONSERTAR TRANSVERSAIS

#include "BinTree.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUTORES ---------------------------*/
BinTree::BinTree()
{
	root = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
Dnode* BinTree::getRoot()
{
	/* Retorna node da raiz da arvore */
	return root;
}

void BinTree::setRoot(Dnode* destination)
{
	/* Configura node da raiz da arvore */
	root = destination;
}

/*--------------------------- METODOS: CRUD --------------------------*/
int BinTree::insert(int value)
{
	/* Insere um novo elemento na arvore
	 * Retorna 0 em caso de insercao com exito, -1 caso contrario 
	 */
	Dnode *toInsert = new Dnode(value); // Node a ser inserido na arvore
	Dnode *where = new Dnode; // Ponteiro para onde inserir
	
	// Verificar se o elemento ja existe na arvore
	if (search(value) != 0)
	{
		where = root;
		
		if (isEmpty() == 0) // Caso arvore vazia: insira na raiz da arvore
		{
			root = toInsert;
			return 0;
		}
		else // Caso geral: busca em ordem e insira no melhor local
		{
			while (where->getNext() != NULL && where->getPrev() != NULL)
			{
				if ((value < where->getValue()) ? where = where->getPrev() : where = where->getNext());
			}
			if (value < where->getValue())
			{
				where->setPrev(toInsert);
				return 0;
			}
			else
			{
				where->setNext(toInsert);
				return 0;
			}
		}
	}
	return -1;
}

int BinTree::remove(int value)
{
	/* Remove o valor especificado na arvore
	 * Retorna 0 caso o valor seja removido, -1 caso contrario.
	 */
	Dnode *toRemove = new Dnode; // Ponteiro para o node a ser removido
	Dnode *father = new Dnode; // Ponteiro para o node pai do node a ser removido
	Dnode *substitute = new Dnode; // Ponteiro para o sucessor do node a ser removido
	char direction = '-'; // flag: indica qual foi a ultima direcao tomada durante a busca (l ou r)
	 
	// Verifique se a arvore esta vazia
	if (isEmpty() != 0)
	{
		toRemove = root;
		father = NULL;
		while (toRemove->getValue() != value && (toRemove->getPrev() != NULL || toRemove->getNext() != NULL))
		{
			if (value < toRemove->getValue())
			{
				father = toRemove;
				toRemove = toRemove->getPrev();
				direction = 'l';
			}
			else if (value > toRemove->getValue())
			{
				father = toRemove;
				toRemove = toRemove->getNext();
				direction = 'r';
			}
		}
		if (toRemove->getValue() == value)
		{
			if (toRemove->getPrev() == NULL && toRemove->getNext() == NULL)
			{
				// remover node folha
				if (direction == 'l')
				{
					father->setPrev(NULL);
				}
				else
				{
					father->setNext(NULL);
				}
				delete toRemove;
				return 0;
			}
			else if (toRemove->getPrev() != NULL && toRemove->getNext() == NULL)
			{
				// remover node com 1 filho a esquerda
				if (direction == 'l')
				{
					father->setPrev(toRemove->getPrev());
				}
				else
				{
					father->setNext(toRemove->getPrev());
				}
				delete toRemove;
				return 0;
			}
			else if (toRemove->getPrev() == NULL && toRemove->getNext() != NULL)
			{
				// remover node com 1 filho a direita
				if (direction == 'l')
				{
					father->setPrev(toRemove->getNext());
				}
				else
				{
					father->setNext(toRemove->getNext());
				}
				delete toRemove;
				return 0;
			}
			else
			{
				// remover node com 2 filhos
				substitute = toRemove->getNext();
				while (substitute->getPrev() != NULL)
				{
					substitute = substitute->getPrev();
				}
				toRemove->setValue(substitute->getValue());
				remove(substitute->getValue());
			}
		}
	}
	return -1;
}

int BinTree::search(int value)
{
	/* Executa uma busca em ordem na arvore
	 * Retorna 0 caso o elemento informado conste na arvore, -1 caso contrario
	 */
	if (isEmpty() != 0)
	{
		Dnode *p = new Dnode;
		p = getRoot();
		while (p != NULL && p->getValue() != value)
		{
			if (value < p->getValue() ? (p = p->getPrev()) : (p = p->getNext()));
		}
		if (p == NULL)
		{
			return -1;
		}
		else if (p->getValue() == value)
		{
			return 0;
		}
	}
	return -1;
}

int BinTree::isEmpty()
{
	/* Verifica se a arvore esta vazia 
	 * Retorna 0 caso vazia, -1 caso contrario
	 */
	if (root == NULL)
	{
		return 0;
	}
	return -1;
}

int BinTree::printOrder(Dnode *node)
{
	/* Imprime os nos da arvore a partir de uma busca em ordem
	 * Busca em ordem: esquerda -> visita -> direita
	 */
	if (node == NULL)
	{
		cout << "1";
		return 0;
	}
	else
	{
		cout << " left ";
		printOrder(node->getPrev());
		cout << "|" << node->getValue() << "|";
		cout << " right ";
		printOrder(node->getNext());
	}
	return -1;
}

int BinTree::printPre(Dnode *node)
{
	/* Imprime os nos da arvore a partir de uma busca pre-ordem
	 * Busca pre-ordem: visita->esquerda->direita
	 */
	if (node == NULL)
	{
		cout << endl;
		return 0;
	}
	else
	{
		cout << "|" << node->getValue() << "|";
		cout << " left ";
		printPre(node->getPrev());
		cout << " right ";
		printPre(node->getNext());
	}
	return -1;
}

int BinTree::printPost(Dnode *node)
{
	/* Imprime os nos da arvore a partir de uma busca pos-ordem
	 * Busca pos-ordem: esquerda->direita->visita
	 */
	if (node == NULL)
	{
		cout << endl;
		return 0;
	}
	else
	{
		cout << " left ";
		printPost(node->getPrev());
		cout << " right ";
		printPost(node->getNext());
		cout << "|" << node->getValue() << "|";
	}
	return -1;
}
