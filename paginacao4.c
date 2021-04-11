#include <stdio.h>
#define PROGRAMAS 8

int escrever(char memp[5][10], char mems[10][10]) // fun��o que escreve na tela todos os programas da memoria principal e da secundaria
{
	int i = 0;
	
	for(i=0;i<5;i++)
	{
		printf("O espaco %d da memoria principal esta sendo usado pelo programa: %s\n", i+1, memp[i]); // escrever programas da memoria principal
	}
	
	for(i=0;i<10;i++)
	{
		printf("O espaco %d da memoria secundaria esta sendo usado pelo programa: %s\n", i+1, mems[i]); // escrever programas da memoria secundaria
	}
}

int main()
{
	// declara��o de vari�veis
	char memoriaprincipal[5][10]={"avast","java","cortana","",""}, memoriasecundaria[10][10]={"","","","","","","","","",""}; // declara uma matriz para cada memoria, e ja inclui 3 programas que abrem como "boot" do pc na memoria principal
	char programa[10];
	int i=3, u=0, p=0, j=0, acertos=0;
	int slotusado = 1;

	escrever(memoriaprincipal,memoriasecundaria); // chama a fun��o que mostra todos os programas nas memorias principal e secundaria assim que a maquina liga
	
	// simula��o de abertura de programas
	for(p=0;p<PROGRAMAS;p++) // estrutura de repeti��o para abrir 5 programas
	{
		printf("Abra um programa: "); // escreve na tela "Abra um programa"
		scanf("%s", &programa); // recebe o nome do programa digitado pelo usuario
		
		for(i=0;i<5;i++)
		{
			if(memoriaprincipal[i][0]==0) // estrutura de condi��o para checagem de espa�o na memoria principal
			{
				for(u=0;u<10;u++)
				{
					memoriaprincipal[i][u] = programa[u]; // se for verdadeiro, escreve o nome do programa na memoria principal
				}
				break; // cancela o loop de checagem caso ja tenha encontrado espa�o vazio
			}
			else if(i==4) // checa se todos os espa�os da memoria principal foram checados
			{
				for(j=0;j<10;j++)
				{
					acertos=0;
					for(u=0;u<10;u++)
					{
						if(programa[u]==memoriasecundaria[j][u])
						acertos++;
					}
					if(acertos>=8)
					{
						for(u=0;u<10;u++) // SWAP IN
						{
							memoriasecundaria[j][u] = memoriaprincipal[3][u]; // um programa da memoria principal sera movido para a memoria secundaria
							memoriaprincipal[3][u] = programa[u]; // o programa que ja estava na memoria secundaria, e foi chamado novamente, voltar� para a memoria principal
						}
						break; // cancela o loop de checagem caso ja tenha encontrado espa�o vazio
					}
					else if(memoriasecundaria[j][0]==0) // estrutura de condi��o para checagem de espa�o na memoria secundaria
					{
						for(u=0;u<10;u++) // SWAP OUT
						{
							memoriasecundaria[j][u] = memoriaprincipal[4][u]; // um programa da memoria principal sera movido para a memoria secundaria
							memoriaprincipal[4][u] = programa[u]; // o programa que o usuario digitou ser� aberto na memoria principal
						}
						break; // cancela o loop de checagem caso ja tenha encontrado espa�o vazio
					}
				}
				break;	// cancela o loop de checagem caso ja tenha encontrado espa�o vazio			
			}
		}
		escrever(memoriaprincipal,memoriasecundaria); // chama a fun��o que mostra todos os programas nas memorias principal e secundaria
	}
	
	return 0;
}
