/*
  Feito por Kevin Andrews Marques Silva - KAMS
Estudante de Engenharia da Computação no CIN - UFPE
      kams@cin.ufpe.br
*/
#include <iostream>

using namespace std;
//Estrutura para lista
typedef struct lista 
{
	int val;
	struct lista* next;
}lista;
//Estrutura para lista

//Aqui criamos uma nova lista utilizando sentinelas
lista* novaListaSentinela() 
{
  lista* sentinela;
	sentinela = new lista();
	sentinela -> next = NULL;
  lista* head = sentinela;
  return head;

}

//E aqui uma nova lista sem sentinela
//As funções podem ser alteradas para o uso com sentinela e sem sentinela
lista* novaListaSemSentinela(int value) 
{
  	lista* head;
	head = new lista();
	head -> val = value;
	head -> next = NULL;
  	return head;
  	
}

//Basicamente aqui encontramos o elemento por posicao, indo ate o final da lista
lista* encontrarElementoPos(lista* head, int posicao) 
{
  int i = 0;
  lista* cursor = head;
  while((i<posicao) && (cursor != NULL))
    {
      cursor = (cursor->next);
      ++i;
    }
  return cursor;
  
}

//E aqui encontramos por valor, percorrendo elemento por elemento
lista* encontrarElementoVal(lista* head, int value)
{
	lista* cursor = head;
	while(cursor -> next != NULL && cursor -> next -> val != value)
	{
		cursor = cursor->next;
	}
	return cursor;
}

//Aqui inserimos um novo elemento em algum ponto da lista
//Para isso passamos o parametro do cursor imediatamente antes do que sera inserido
lista* inserir (lista* cursor, int value) 
{

  lista* N;
  N = new lista();
  N->val = value;
  N->next = cursor->next;
  cursor->next = N;

  return cursor;
}

//Aqui removemos um elemento da lista
//Também devemos passar o elemento imediatamente antes do elemento removido
lista* removerElemento (lista* cursor) 
{
  lista* p;
  p = cursor->next;
  cursor->next = p->next;
  delete[] p;

  return cursor;
}

int main()
{
  return 0;
}