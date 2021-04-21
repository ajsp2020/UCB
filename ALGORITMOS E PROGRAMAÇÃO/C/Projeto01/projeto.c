#include<stdio.h> // Esta biblioteca cont�m v�rias fun��es de entrada e sa�da. 
#include<locale.h> // para implementar a localiza��o de programas.
#include<stdlib.h>
#include<string.h>

#define TAM_NOME 20
#define TAM_LISTA 2

void dadosautor()
{
	printf("Projeto pr�tico 01:\n"
			"NOME: Antonio Jo�o da Silva Pereira\n"
			"MATR�CULA: \n"
			"CURSO: Ci�ncias da Computa��o\n\n");
}

void validavalor(int status, int* valor, int j, int i)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido....\n");

		if (j == 0)
		{
			printf("Digite a quantidade de se��es que ser�o realizadas: ");
		}
		if (j == 1)
		{
			printf("Digite a quantidade de pessoas que assistiram a se��o: ");
		}
		if (j == 2)
		{
			printf("Digite a idade da pessoa %d: ", i + 1);
		}

		status = scanf("%d", valor);
		fflush(stdin);
	}
}

void pegasessoes(int* qtd_secoes)
{
	printf("Digite a quantidade de se��es que ser�o realizadas: ");
	int status = scanf("%d", qtd_secoes);
	fflush(stdin);
	validavalor(status, qtd_secoes, 0, 0);
	if (*qtd_secoes != 2)
	{
		printf("Somente � aceito 2 se��es como input:\n");
		pegasessoes(qtd_secoes);
	}
	
}

void pegapessoas(int* qtd_pessoas)
{
	printf("Digite a quantidade de pessoas que assistiram a se��o: ");
	int status = scanf("%d", qtd_pessoas);
	fflush(stdin);
	validavalor(status, qtd_pessoas, 1, 0);
	if (*qtd_pessoas < 10)
	{
		printf("� aceito no m�nimo 10 pessoas como input:\n");
		pegapessoas(qtd_pessoas);
	}
}

void pegaidades(int* idades, int qtd_pessoas, int v)
{
	int idade;
	for (int i = v; i < qtd_pessoas; i++)
	{
		printf("Digite a idade da pessoa %d: ", i + 1);
		int status = scanf("%d", &idades[i]);
		fflush(stdin);
		validavalor(status, &idades[i], 2, i);
		if (idades[i] < 3 || idades[i] > 100)
		{
			printf("� aceito somente idades entre 3 a 100 anos como input:\n");
			pegaidades(idades, qtd_pessoas, i);
			break;
		}
	}
}

int main()
{
	setlocale(LC_ALL, ""); 
	// Vari�veis:
	int qtd_sessoes, qtd_pessoas;
	int *idades = malloc(sizeof(int*) * qtd_pessoas);
	char nome_filmes[TAM_LISTA][TAM_NOME];
	char *sexo = malloc(sizeof(char*) * qtd_pessoas);

	// fun��es
	dadosautor(); // Imprime os dados do autor
	pegasessoes(&qtd_sessoes); // Pega a quantidade de se��es 
	//pegafilmes(); // Pega o nome do filme
	pegapessoas(&qtd_pessoas); // Pega a quantidade de pessoas
	//pegasexo(); // Pega o sexo das pessoas
	pegaidades(idades, qtd_pessoas, 0); // Pega a idade das pessoas
	printf("%d\n", qtd_sessoes);
	printf("%d\n", qtd_pessoas);
	printf("idades[6] = %d\n", idades[6]);
	free(idades);
	free(sexo);
}