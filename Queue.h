// Queue.h
// Cabecalho de filas

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
	private:
/*---------------------------- ATRIBUTOS -----------------------------*/
		Node *start; // Ponteiro para o comeco da fila
		Node *end; // Ponteiro para o final da fila
		
	public:
/*--------------------------- CONSTRUTORES ---------------------------*/
		Queue(); // Construtor padrao de filas
		
/*------------------------ METODOS: GET E SET ------------------------*/
		Node* getStart(); // Retorna node do comeco da fila
		Node* getEnd(); // Retorna node do final da fila
		void setStart(Node* destination); // Configura comeco da fila
		void setEnd(Node* destination); // Configura final da fila
		
/*--------------------------- METODOS: CRUD --------------------------*/
		int enqueue(int new_value); // Adiciona um novo elemento ao final da fila
		int dequeue(); // Remove um elemento do comeco da fila
		int isEmpty(); // Verifica se a fila esta vazia
		void printQueue(); // Imprime a configuracao atual da fila
};

#endif // QUEUE_H
