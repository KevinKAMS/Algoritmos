void dijkstra(node** grafo, int vertices, int arestas, int distS, int destino) 
{
	//Alocação
	int* distancias;
	distancias = new int[100000];
	for (int i = 0; i < vertices; ++i)
	{
		distancias[i] = INFINTE;
	}
	//Alocação

	//Inicialização
	distancias[distS] = 0;

	//Declaração HEAP
	dij* heap;
	heap = new dij[100000];
	//Declaração HEAP

	//Inicialização da HEAP
	int tam = 0;
	dij inicio;
	inicio.dist = 0;
	inicio.cur = distS;
	heap_insert(heap, inicio, &tam);
	//Inicialização da HEAP

	//Auxiliares
	node* E;
	dij info;
	dij aux;
	//Auxiliares

	//DIJKSTRA
	for (int i = 0; i < vertices; ++i)
	{
		info = heap_extract(heap, &tam);
		E = grafo[info.cur];
		while (E -> next != NULL)
		{
				if(distancias[info.cur] + E -> next -> peso  < distancias[E -> next -> val])
				{
					distancias[E -> next -> val] = distancias[info.cur] + E -> next -> peso;
					aux.cur = E -> next -> val;
					aux.dist =  distancias[E -> next -> val];
					heap_insert(heap, aux, &tam);
				}
			E = E-> next;
		}
	}
	//DIJKSTRA

	//Saida
	cout << distancias[destino] << endl;
	return;
}