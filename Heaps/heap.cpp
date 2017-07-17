#include <iostream>
#include <vector>

using namespace std;


void heapify (int v[], int i, int tam)
{ 

   int left = 2*i + 1, right = 2*i + 2, mid = i;
   if (left < tam && v[left] < v[mid]) {
      mid = left;
   }

   if (right < tam && v[right] < v[mid]) {
      mid = right;
   }

   if (mid != i) {
      int z = v[i];
      v[i] = v[mid];
      v[mid] = z;
      heapify(v, mid, tam);
   }

   return;
}

void constroiMinHeap(int tam, int v[])
{
    for (int k = (tam/2)-1; k >= 0; k--) {                   
      heapify(v, k, tam);      
    }
    return;
}

int heap_extract(int v[], int *tam) {
  int r = v[0];
  int z = v[0];
  v[0] = v[*tam - 1];
  v[*tam - 1] = z;
  *tam = *tam - 1;
  heapify(v, 0, *tam);
  return r;
}

void bubbleUp(int v[], int *tam) {
	int i = *tam;
	while(i > 0 && v[i] < v[(i-1)/2]) {
		int z = v[i];
    	v[i] = v[(i-1)/2];
      	v[(i-1)/2] = z;
      	i = (i-1)/2;
	}
	*tam = *tam + 1;
	return;
}

void heap_insert(int v[], int val, int *tam)
{
	/*
	if(tam == tamDoVetor)
		v.resize(tam*2);
	*/
	v[*tam] = val;
	bubbleUp(v, tam);
}

int main()
{
	int tam = 10;
	int rogerio[20];

	for (int i = 0; i < tam; ++i)
	{
		cin >> rogerio[i];
	}
	constroiMinHeap(tam, rogerio);
	for (int i = 0; i < tam; ++i)
	{
		cout << "[" << rogerio[i] << "] - ";
	}
	cout << endl;
	heap_extract(rogerio, &tam);
	for (int i = 0; i < tam; ++i)
	{
		cout << "[" << rogerio[i] << "] - ";
	}
	cout << endl;
	heap_extract(rogerio, &tam);
	for (int i = 0; i < tam; ++i)
	{
		cout << "[" << rogerio[i] << "] - ";
	}
	cout << endl;
	heap_insert(rogerio, 10, &tam);
	for (int i = 0; i < tam; ++i)
	{
		cout << "[" << rogerio[i] << "] - ";
	}
	cout << endl;
	return 0;
}