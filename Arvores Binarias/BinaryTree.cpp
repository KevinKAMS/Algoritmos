#include <iostream>

using namespace std;

typedef struct node
{
	int data;
	struct node* right;
	struct node* left;

}node;

// Recebe a raiz root de uma árvore binária
// e imprime os conteúdos dos seus nós
// em ordem esquerda-raiz-direita.
void percursoLeftRootRight(node* root)
{
	if(root != NULL)
		percursoLeftRootRight(root -> left);
		cout << root -> data << " - ";
		percursoLeftRootRight(root -> right);
}

// Devolve a altura da árvore binária
// cuja raiz é root.
int alturaDaBST(node* root)
{
	if(root == NULL) 
		return -1; //Altura da arvore vazia
	else
	{
		int he = alturaDaBST(root -> left);
		int hd = alturaDaBST(root -> right);
		if (he < hd) return hd+1;
		else return he+1;
	}
}

//Funções para mostrar a BST completa
void _display(node* root, int spaces)
{
	if(root == NULL)
		return;

	_display(root->right, spaces+5);

	for(int i = 0; i < spaces; ++i)
		cout << " ";

	cout <<  root->data << endl;

	_display(root->left, spaces+5);
	return;
}

void display(node* root)
{
	_display(root, 0);
}

//Inserção de um novo nó de valor 'v'
//em uma arvore binaria de raiz 'raiz'
node* bstInsert(node* raiz, int v) 
{
	if (raiz == NULL) 
	{
		node* novo = new node;
		novo -> data = v;
		novo -> left = NULL;
		novo -> right = NULL;
		return novo;
	} 
	else if (v < raiz -> data) 
	{
		raiz -> left = bstInsert(raiz -> left, v);
		return raiz;
	} 
	else 
	{
		raiz -> right = bstInsert(raiz -> right, v);
		return raiz;
	}
}

//Busca de determinado valor 'v' em uma bst
//Retorna o nó onde ela se encontra
node* bstSearch(node* raiz, int v) {
	if (raiz == NULL) {
		return NULL;
	} else if (raiz -> data == v) {
		return raiz;
	} else if (v < raiz -> data) {
		return bstSearch(raiz->left, v);
	} else {
		return bstSearch(raiz->right, v);
	}
}

//Função minimal de bst delete
node* bstDeleteMin(node* raiz, int* val)
{

	if(raiz->left == NULL)
	{
		node* r = raiz->right;
		*val = raiz->data;
		delete[] raiz;
		return r;
	}
	else
	{
		raiz->left = bstDeleteMin(raiz->left, val);
		return raiz;
	}
}

//Funções para deleter determinado nó 'v' de uma BST
//Mantendo os pesos
node* bstDelete(node* raiz, int v)
{	
	int x=0;
	int *val = &x;

	if(raiz == NULL)
	{
		return NULL;
	}
	
	else if(v < (raiz->data))
	{
		(raiz->left) = bstDelete((raiz->left), v);
		return raiz;
	}

	else if((raiz->data) < v)
	{
		(raiz->right) = bstDelete((raiz->right), v);
		return raiz;
	}

	else
	{
		if((raiz->left) == NULL)
		{
			node* right = (raiz->right);
			delete[] raiz;
			return right;
		}

		else if((raiz->right) == NULL)
		{
			node* left = (raiz->left);
			delete[] raiz;
			return left;
		}
		else
		{
			(raiz->right) = bstDeleteMin((raiz->right), val);
			(raiz->data) = *val;
			return raiz;
		}
	}
}



int main()
{
	cout << "oi" << endl;
	return 0;
}