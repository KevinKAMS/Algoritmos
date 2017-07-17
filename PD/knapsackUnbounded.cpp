int knapsackUnbounded(int brinquedos, int carteira, int diversao[], int aborrecimento[], int custo[])
{
	int* parcialSol;
	int* halfParcialSol;
	parcialSol = new int[brinquedos];
	halfParcialSol = new int[brinquedos];
	int finalSol;
	int* novaDiversao;
	novaDiversao = new int[brinquedos];
	novaDiversao = diversao;
	if (carteira == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < brinquedos; ++i)
		{
			if (carteira >= custo[i])
			{
				parcialSol[i] = knapsack(brinquedos, carteira - custo[i], novaDiversao, aborrecimento, custo);
			}
			else
				parcialSol[i] = 0;
		}
		for (int i = 0; i < brinquedos; ++i)
		{
			if (carteira >= custo[i])
			{
				halfParcialSol[i] = parcialSol[i] + novaDiversao[i];
				//novaDiversao[i] = novaDiversao[i] - aborrecimento[i];
			}
			else
				halfParcialSol[i] = 0;
		}

		finalSol = halfParcialSol[0];
		for (int i = 1; i < brinquedos; ++i)
		{
			if (halfParcialSol[i] > finalSol)
			{
				finalSol = halfParcialSol[i];
			}
		}
	}
	return finalSol;

}