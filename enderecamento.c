#include <stdio.h>

int main()
{
	int endereco_virtual=0, endereco_fisico=0, i=0, u=0, encontrado=0;
	int mmu[8] = {12,28,16,0,8,4,20,24};
	
	for(i=0;i<5;i++)
	{
		printf("\nDigite o valor do endereco virtual: ");
		scanf("%d", &endereco_virtual);
		for(u=0;u<8;u++)
		{
			if(endereco_virtual==mmu[u])
			{
				endereco_fisico = u;
				encontrado = 1;
				break;
			}
		}
		if(encontrado)
		{
			printf("\nO endereco fisico e: %d\n", endereco_fisico);
			encontrado = 0;	
		}
		else
		printf("\nEste endereco nao se encontra na memoria\n");
	}
	return 0;
}
