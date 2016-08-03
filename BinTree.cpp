// BinTree.cpp
// Implementacao de arvore de busca binaria

#include "BinTree.h"
#include <iostream>
using namespace std;

/*--------------------------- CONSTRUTORES ---------------------------*/
BinTree::BinTree()
{
	root = NULL;
}

/*------------------------ METODOS: GET E SET ------------------------*/
Tnode* BinTree::getRoot()
{
	/* Retorna node da raiz da arvore */
	return root;
}

void BinTree::setRoot(Tnode* destination)
{
	/* Configura node da raiz da arvore */
	root = destination;
}

int BinTree::getHeight(Tnode *root)
{
	/* Retorna a altura da arvore de raiz root
	 * Extraido do material em http://www.ime.usp.br/~pf/algoritmos/aulas/bint.html
	 */
	if (root == NULL)
	{
		return -1;
	}
	else
	{
		int height_left = getHeight(root->getLeft());
		int height_right = getHeight(root->getRight());
		if (height_left > height_right)
		{
			return height_left + 1;
		}
		else
		{
			return height_right + 1;
		}
	}
}

/*--------------------------- METODOS: CRUD --------------------------*/
int BinTree::insert(int value)
{
	/* Insere um novo elemento na arvore
	 * Retorna 0 em caso de insercao com exito, -1 caso contrario 
	 */
	Tnode *toInsert = new Tnode(value); // Node a ser inserido na arvore
	Tnode *target = new Tnode; // Ponteiro que navega pela arvore
	Tnode *where = new Tnode; // Ponteiro que segue atras de target e define onde inserir
	
	// Verificar se o elemento ja existe na arvore
	if (search(value) != 0)
	{
		target = root;
		where = NULL;
		
		if (isEmpty() == 0)
		{
			// Caso arvore vazia: insira na raiz da arvore
			root = toInsert;
			balanceCheck(root, NULL);
			return 0;
		}
		else
		{
			// Caso geral: busca em ordem e insira no melhor local
			while (target != NULL)
			{
				if (value < target->getValue())
				{
					where = target;
					target = target->getLeft();
				}
				else
				{
					where = target;
					target = target->getRight();
				}
			}
			if (value < where->getValue())
			{
				where->setLeft(toInsert);
				updateBF(root);
				balanceCheck(root, NULL);
				return 0;
			}
			else
			{
				where->setRight(toInsert);
				updateBF(root);
				balanceCheck(root, NULL);
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
	Tnode *toRemove = new Tnode; // Ponteiro para o node a ser removido
	Tnode *father = new Tnode; // Ponteiro para o node pai do node a ser removido
	Tnode *substitute = new Tnode; // Ponteiro para o sucessor do node a ser removido
	char direction = '-'; // flag: indica qual foi a ultima direcao tomada durante a busca (l ou r)
	 
	// Verifique se a arvore esta vazia
	if (isEmpty() != 0)
	{
		toRemove = root;
		father = NULL;
		
		// Procure pelo node a ser removido e determine seu pai e seu sucessor
		while (toRemove->getValue() != value && (toRemove->getLeft() != NULL || toRemove->getRight() != NULL))
		{
			if (value < toRemove->getValue())
			{
				father = toRemove;
				toRemove = toRemove->getLeft();
				direction = 'l';
			}
			else if (value > toRemove->getValue())
			{
				father = toRemove;
				toRemove = toRemove->getRight();
				direction = 'r';
			}
		}
		
		if (toRemove->getValue() == value)
		{
			if (toRemove->getLeft() == NULL && toRemove->getRight() == NULL)
			{
				// Remover node folha
				// Pai do node aponta para NULL
				if (direction == 'l')
				{
					// Node eh filho a esquerda
					father->setLeft(NULL);
				}
				else
				{
					// Node eh filho a direita
					father->setRight(NULL);
				}
				delete toRemove;
				return 0;
			}
			else if (toRemove->getLeft() != NULL && toRemove->getRight() == NULL)
			{
				// Remover node com 1 filho a esquerda
				// Sucessor do node passa a ser filho a esquerda de seu antigo pai
				// Sucessor tem altura decrementada em 1
				if (direction == 'l')
				{
					father->setLeft(toRemove->getLeft());
				}
				else
				{
					father->setRight(toRemove->getLeft());
				}
				delete toRemove;
				return 0;
			}
			else if (toRemove->getLeft() == NULL && toRemove->getRight() != NULL)
			{
				// Remover node com 1 filho a direita
				// Sucessor do node passa a ser filho a direita de seu antigo pai
				// Sucessor tem altura decrementada em 1
				if (direction == 'l')
				{
					father->setLeft(toRemove->getRight());
				}
				else
				{
					father->setRight(toRemove->getRight());
				}
				delete toRemove;
				return 0;
			}
			else
			{
				// Remover node com 2 filhos
				// Valor do node passa a ser valor de seu sucessor
				// Remova o sucessor no lugar do node
				substitute = toRemove->getRight();
				while (substitute->getLeft() != NULL)
				{
					substitute = substitute->getLeft();
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
		Tnode *p = new Tnode;
		p = getRoot();
		while (p != NULL && p->getValue() != value)
		{
			if (value < p->getValue() ? (p = p->getLeft()) : (p = p->getRight()));
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

int BinTree::updateBF(Tnode* node)
{
	/* Atualiza fator de balanceamento dos nodes da arvore apos insercao */
	if (node == NULL)
	{
		return 0;
	}
	else
	{
		// Calcula a altura da subarvore esquerda e direita de node
		// Atualiza balance factor do node com a diferenca dessas alturas
		int height_l = 0; // Altura da subarvore esquerda
		int height_r = 0; // Altura da subarvore direita
		height_l = getHeight(node->getLeft());
		height_r = getHeight(node->getRight());
		node->setBalanceFactor(height_l - height_r);
		
		updateBF(node->getLeft());
		updateBF(node->getRight());
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

void BinTree::printOrder(Tnode *node)
{
	/* Imprime os nos da arvore a partir de uma busca em ordem
	 * Busca em ordem: esquerda -> visita -> direita
	 */
	if (node == NULL)
	{
		cout << "-";
	}
	else
	{
		cout << "L";
		printOrder(node->getLeft());
		
		cout << "|" << node->getValue() << ":" << node->getBalanceFactor() << "|";
		
		cout << "R";
		printOrder(node->getRight());
	}
}

void BinTree::printPre(Tnode *node)
{
	/* Imprime os nos da arvore a partir de uma busca pre-ordem
	 * Busca pre-ordem: visita->esquerda->direita
	 */
	if (node == NULL)
	{
		cout << "-";
	}
	else
	{
		cout << "|" << node->getValue() << ":" << node->getBalanceFactor() << "|";
		
		cout << "L";
		printPre(node->getLeft());
		
		cout << "R";
		printPre(node->getRight());
	}
}

void BinTree::printPost(Tnode *node)
{
	/* Imprime os nos da arvore a partir de uma busca pos-ordem
	 * Busca pos-ordem: esquerda->direita->visita
	 */
	if (node == NULL)
	{
		cout << "-";
	}
	else
	{
		cout << "L";
		printPost(node->getLeft());
		
		cout << "R";
		printPost(node->getRight());
		
		cout << "|" << node->getValue() << ":" << node->getBalanceFactor() << "|";
	}
}

void BinTree::balanceCheck(Tnode *node, Tnode *prenode)
{
	/* Verifica se a arvore de raiz node esta balanceada
	 * Caso contrario, executa as rotacoes necessarias
	 */
	if (node != NULL)
	{
		if (node->getBalanceFactor() == 2)
		{
			if (node->getLeft()->getBalanceFactor() == 1)
			{
				rotateRight(prenode, node, node->getLeft());
			}
			else if (node->getLeft()->getBalanceFactor() == -1)
			{
				rotateDoubleLeft(prenode, node, node->getLeft());
			}
		}
		else if (node->getBalanceFactor() == -2)
		{
			if (node->getRight()->getBalanceFactor() == 1)
			{
				rotateDoubleRight(prenode, node, node->getRight());
			}
			else if (node->getRight()->getBalanceFactor() == -1)
			{
				rotateLeft(prenode, node, node->getRight());
			}
		}
		balanceCheck(node->getLeft(), node);
		balanceCheck(node->getRight(), node);
	}
}

void BinTree::rotateLeft(Tnode *preroot, Tnode *father, Tnode *pivot)
{
	/* Executa rotacao a esquerda na arvore de raiz father.
	 * Requer father.getRight() == pivot
	 * Requer father.getBalanceFactor == -2 && pivot.getBalanceFactor == -1
	 * preroot precisa ser pai de father antes da rotacao.
	 * preroot eh reconectado a pivot apos a rotacao.
	 */
	father->setRight(pivot->getLeft());
	pivot->setLeft(father);
	if (preroot == NULL)
	{
		setRoot(pivot);
	}
	else if (preroot->getLeft() == father)
	{
		preroot->setLeft(pivot);
	}
	else if (preroot->getRight() == father)
	{
		preroot->setRight(pivot);
	}
	updateBF(root);
}

void BinTree::rotateRight(Tnode *preroot, Tnode *father, Tnode *pivot)
{
	/* Executa rotacao direita na arvore de raiz father
	 * Requer father.getLeft() == pivot
	 * Requer father.getBalanceFactor() == +2 && pivot.getBalanceFactor() == +1
	 * preroot precisa ser pai de father antes da rotacao
	 * preroot eh reconectado a pivot apos a rotacao
	 */
	father->setLeft(pivot->getRight());
	pivot->setRight(father);
	if (preroot == NULL)
	{
		setRoot(pivot);
	}
	else if (preroot->getLeft() == father)
	{
		preroot->setLeft(pivot);
	}
	else if (preroot->getRight() == father)
	{
		preroot->setRight(pivot);
	}
	updateBF(root);
}

void BinTree::rotateDoubleLeft(Tnode *preroot, Tnode *father, Tnode *pivot)
{
	/* Executa rotacao dupla a esquerda na arvore de raiz father
	 * Requer father.getLeft() == pivot
	 * Requer father.getBalanceFactor() == +2 && pivot.getBalanceFactor() == -1
	 * preroot precisa ser pai de father antes da rotacao
	 * preroot eh reconectado a pivot apos a rotacao
	 */
	rotateLeft(father, pivot, pivot->getRight());
	rotateRight(preroot, father, father->getLeft());
}

void BinTree::rotateDoubleRight(Tnode *preroot, Tnode *father, Tnode *pivot)
{
	/* Executa rotacao dupla a direita na arvore de raiz father
	 * Requer father.getRight() == pivot
	 * Requer father.getBalanceFactor() == -2 && pivot.getBalanceFactor() == +1
	 * preroot precisa ser pai de father antes da rotacao
	 * preroot eh reconectado a pivot apos a rotacao
	 */
	rotateRight(father, pivot, pivot->getLeft());
	rotateLeft(preroot, father, father->getRight());
}
