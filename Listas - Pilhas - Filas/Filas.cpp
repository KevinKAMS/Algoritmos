/*
	Feito por Kevin Andrews Marques Silva - KAMS
Estudante de Engenharia da Computação no CIN - UFPE
			kams@cin.ufpe.br
*/
#include <iostream>

using namespace std;
//Estrutura usada na fila
typedef struct fila
{
	int value;
	struct fila* next;
}fila;
//Estrutura usada na fila

//Função que enfileira o primeiro elemento
//FIRST IN
void enfileirar(fila* front, fila* rear, int val)
{
	fila* r;
	r = new fila();
	r -> next = NULL;
	r -> value = val;

	if (front -> next -> next == NULL) { //Aqui eu uso um sentinela no front, mas não uso um no rear
		front -> next -> next = r;
	}
	rear -> next -> next = r; //O ponteiro pro fim da lista aponta pra o ultimo elemento e o antigo ultimo elemento, 
	rear -> next = r;		 //aponta pro novo ultimo elemento
}

//Aqui removemos o elemento da fila
//FIRST OUT
int desenfileirar(fila* front, fila* rear)
{
	int especificValue;
	fila* r;
	r = front -> next -> next;
	especificValue = r -> value;
	front -> next -> next = r -> next;
	if (r -> next == NULL) //Caso a lista esteja vazia, front e rear apontam para o sentinela
	{
		rear -> next = front -> next;
	}
	delete[] r;
	return especificValue; //O valor que foi removido
}

int main()
{
	return 0;
}