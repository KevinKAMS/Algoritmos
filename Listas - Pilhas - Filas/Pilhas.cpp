/*
  Feito por Kevin Andrews Marques Silva - KAMS
Estudante de Engenharia da Computação no CIN - UFPE
      kams@cin.ufpe.br
*/
#include <iostream>

using namespace std;
//Estrutura de pilha
typedef struct pilha
{
	int val;
	struct pilha* next;
}pilha;
//Estrutura de pilha

//Declaramos uma nova pilha
//OBS: com uso de sentinela
pilha* novaPilha() {
  pilha* sentinela;
  sentinela = new pilha();
  
  sentinela->next = NULL;
  pilha* top = sentinela;

  return top;
}

//Aqui um simples push
//O elemento entra sempre no topo da pilha
pilha* push(pilha* top, int valor)
{
  pilha* S;
  S = new pilha();
  
  S->val = valor; 
  S->next = top->next;
  top->next = S;


  return top;
}

//Aqui um pop
//O elemento a sair é tambem o do topo da pilha
//Last in -> First Out
pilha* pop (pilha* top) {
  pilha* S;
  S = top->next;
  top->next = S->next;
  delete[] S;

  return top;
}

int main()
{
	return 0;
}