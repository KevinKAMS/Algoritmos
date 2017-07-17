void prim(node** grafo, int vertices, int arestas, int distS, int destino)
{
	
	//Declaração
	int* distancias;
	distancias = new int[100000];
	for (int i = 0; i < vertices; ++i)
	{
		distancias[i] = INFINTE;
	}
	//Declaração

	//Decalração
	int* precursor;
	precursor = new int[100000];
	for (int i = 0; i < vertices; ++i)
	{
		precursor[i] = -1;
	}
	//Decalração
	//Declaração
	int* visitado;
	visitado = new int[100000];
	for (int i = 0; i < vertices; ++i)
	{
		visitado[i] = 0;
	}
	//Declaração

	//Inicialização
	distancias[distS] = 0;
	precursor[distS] = 0;
	//Inicialização

	//HEAP
	dij* heap;
	heap = new dij[100000];
	//HEAP

	//Inicialização
	int tam = 0;
	dij inicio;
	inicio.dist = 0;
	inicio.cur = distS;
	heap_insert(heap, inicio, &tam);
	//Inicialização

	//Declaração do vetor de listas de adjacencias novo
	node** T;
	T = new node*[100000];
	for (int i = 0; i < vertices; ++i)
	{
		T[i] = novanodeSentinela();
	}
	//Declaração do vetor de listas de adjacencias novo

	//Auxiliar
	node* E;
	int c = 0;
	dij info;
	dij aux;
	int u;
	//Auxilizar

	int testeArestas;

	for (int i = 0; i < vertices; ++i)
	{

		info = heap_extract(heap, &tam);
		while(visitado[info.cur] == 1) //Paranaue pro Prim funcionar
		{
			info = heap_extract(heap, &tam);
		}
		visitado[info.cur] = 1;
		c = c + info.dist;
		if (info.cur != distS)
		{
			u = precursor[info.cur];
			inserir(T[u], info.cur, info.dist);
			inserir(T[info.cur], u, info.dist);
			testeArestas = testeArestas + 2;
		}
		E = grafo[info.cur];
		while(E != NULL & E -> next != NULL)
		{
			if (distancias[E-> next -> val] > E -> next -> peso && visitado[E-> next -> val] == 0)
			{
				distancias[E -> next -> val] = E -> next -> peso;
				precursor[E -> next -> val] = info.cur;
				aux.cur = E -> next -> val;
				aux.dist = distancias[E -> next -> val];
				heap_insert(heap, aux, &tam);

			}
			E = E -> next;
		}
	}

	int atual = destino;
	int distanciaTotal = 0;
	int *caminho;
	caminho = new int[100000];
	int x = 0;
	while(atual != distS)
	{
		distanciaTotal = distanciaTotal + distancias[atual];
		caminho[x] = distancias[atual];
		x++;
		atual = precursor[atual];
	}

	cout << distanciaTotal << endl;
	cout << distS << " ";
	for (int i = x-1; i >= 0 ; --i)
	{
		cout << caminho[i] << " ";
	}
	cout << destino;
}