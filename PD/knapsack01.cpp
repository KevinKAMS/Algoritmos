#include <iostream>

using namespace std;


int** knapsack(int itens, int carga, int valor[], int peso[])
{
	int** S;
	S = new int*[itens + 2];
	for (int i = 0; i < itens + 2; ++i)
	{
		S[i] = new int[carga + 1];
		for (int j = 0; j < carga + 1; ++j)
		{
			S[i][j] = 0;
		}
	}
	for (int i = 1; i < itens + 2; ++i)
	{
		for (int j = 1; j < carga + 1; ++j)
		{
			if (peso[i-1] <= j && valor[i-1] + S[i-1][j - peso[i-1]] > S[i-1][j])
			{
				S[i][j] = valor[i-1] + S[i-1][j-peso[i-1]];
			}
			else
			{
				S[i][j] = S[i-1][j];
			} 
		}
	}
	return S;
}

int main()
{
	ios::sync_with_stdio(false); 
	cin.tie(NULL);
	cout << "Oi" << endl;
	return 0;
}