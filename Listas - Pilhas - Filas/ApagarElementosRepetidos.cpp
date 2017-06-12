/*
  Feito por Kevin Andrews Marques Silva - KAMS
Estudante de Engenharia da Computação no CIN - UFPE
      kams@cin.ufpe.br
*/

//Esse é um codigo simples que criei para tirar todos os repetidos de uma lista
//Apesar de util, o codigo não tem sua melhor otimização possivel
//Tendo que percorrer a lista varias vezes
#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node* next;

}node;

node* novoNo(int val) 
{
	node* p;
	p = new node();
	p -> data = val;
	p -> next = NULL;
	return p;
}


node* list_delete (node* cursor) 
{
  	node* p = cursor->next;
  	cursor->next = p->next;
  	delete[] p;

  	return cursor;
}

node* apagarElementosRepetidos (node* cursor)
{
	node* cursorAux1;
	node* cursorAux2;
	if (cursor != NULL)
		cursorAux1 = cursor;
	else
		return cursor;
	if (cursor -> next != NULL)
		cursorAux2 = cursor -> next;
	else
		return cursor;
	while(cursorAux1 -> next != NULL)
	{
		if (cursorAux1 -> next != NULL)
			cursorAux2 = cursorAux1 -> next;
		else
			cursorAux2 -> next = NULL;
		while (cursorAux2 -> next != NULL)
		{
			if (cursorAux1 -> data == cursorAux2 -> data)
			{
				cursorAux2 = list_delete(cursorAux2);
			}
			else
			{
				if (cursorAux2 -> next != NULL)
					cursorAux2 = cursorAux2 -> next;
			}
		}
		cursorAux1 = cursorAux1 -> next;
	}
	return cursor;
	
}

int main()
{
	//TESTE
	node* a = novoNo(1);
	node* b = novoNo(2);
	a -> next = b;
	node* c = novoNo(3);
	b -> next = c;
	node* d = novoNo(1);
	c -> next = d;
	node* e = novoNo(2);
	d -> next = e;
	node* f = novoNo(3);
	e -> next = f;
	node* g = novoNo(4);
	f -> next = g;
	node* h = novoNo(4);
	g -> next = h;

	node* cursor = a;
	while(cursor -> next != NULL)
	{
		cout << "[" << cursor -> data << "]->";
	}
	cout << endl;
	//TESTE
	
}