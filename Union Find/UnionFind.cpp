#include <iostream>

using namespace std;

typedef struct tree
{
	int val;
	int altura;
	struct tree* par;
}tree;

tree* make_set(int x)
{
	tree* n;
	n = new tree();
	n -> val = x;
	n -> altura = 1; 
	n -> par = n;
	return n;
}

tree* find(tree* x)
{
	if (x-> par == x)
	{
		return x;
	}
	else
	{
		return find(x->par);
	}
}

tree* union_find(tree* x, tree* y)
{
	tree* R = find(x); 
	tree* S = find(y);
	if (R == S)
	{
		return R;
	}
	else if (R -> altura < S -> altura)
	{
		R -> par = S;
		return S;
	}
	else
	{
		S -> par = R;
		if (R -> altura == S -> altura)
		{
			R -> altura = R -> altura + 1;
		}
		return R;
	}
}

tree* find_pc(tree* x)
{
	if (x -> par != x)
	{
		x -> par = find_pc(x -> par);
	}
	return (x -> par);
}

int main()
{

	return 0;
}