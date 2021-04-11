#include <windows.h>
#include <stdio.h>
#include <conio.h>

DWORD WINAPI FuncaoThread(LPVOID lpParam)
{
	int i=0;
	for(i=0;i<5;i++)
	{
		printf("Thread ID: %u\n", GetCurrentThreadId());
	}
	return 0;
}

int main()
{
	DWORD idThread, parametroThread = 1;
	HANDLE hThread;
	int i=0;
	for(i = 1; i <= 10; i++) // estrutura de repeticao
		{
			hThread = CreateThread( // inicio da funcao para criar thread
			NULL, // atributo de seguranca padrao
			0, // tamanho padrao
			FuncaoThread, // funcao thread
			&parametroThread, // grava parametro da thread na variavel
			0, // usa "flag" de contrucao padrao
			&idThread); // grava id da thread na variavel
			
			// checagem se a funcao de criar thread funcionou
			if (hThread == NULL) // se a funcao falhar
				printf("Funcao criar thread falhou, codigo do erro: %d.\n", GetLastError());
			
			// se nao der erro, significa que a criacao de thread funcionou
			else
			{	
				printf("Thread criada com sucesso!!\n");
				printf("O ID da thread e: %u.\n", idThread);
			}
		} 
		
	return 0;
}
