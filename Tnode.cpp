// Tnode.cpp
// Implementacao de node para arvore de busca binaria e heap

#include "Tnode.h"

/*--------------------------- CONSTRUTORES ---------------------------*/
Tnode::Tnode(); // Construtor padrao
Tnode::Tnode(int value); // Construtor com inicializacao de value
/*------------------------ METODOS: GET E SET ------------------------*/
int Tnode::getHeight(); // Retorna a altura do node
int Tnode::getValue(); // Retorna o valor guardado no node
Tnode* Tnode::getLeft(); // Retorna o node filho a esquerda
Tnode* Tnode::getRight(); // Retorna o node filho a direita
void Tnode::setValue(int new_value); // Ajusta new_value como valor do node
void Tnode::incHeight(); // Incrementa em 1 a altura do node
void Tnode::decHeight(); // Decrementa em 1 a altura do node
