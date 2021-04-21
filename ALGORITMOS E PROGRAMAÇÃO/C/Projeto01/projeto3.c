#include<stdio.h> // Esta biblioteca cont�m v�rias fun��es de entrada e sa�da. 
#include<locale.h> // para implementar a localiza��o de programas.
#include<stdlib.h>
#include<string.h>
#include <ctype.h> // para incluir a biblioteca do tooper
#include"projeto.h"



void dadosautor()
{
	printf("Projeto pr�tico 01:\n"
			"NOME: Antonio Jo�o da Silva Pereira\n"
			"MATR�CULA: \n"
			"CURSO: Ci�ncias da Computa��o\n\n");
}

void validavalor(int* status, int* valor, int j, int k, int v)
{
	int temp, input;
	while (*status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido....\n");

		switch (j)
		{
		case 0:
			printf("Digite a quantidade de se��es que ser�o realizadas: ");
			break;

		case 1:
			printf("Digite a quantidade de pessoas que assistiram a se��o: ");
			break;

		case 2:

			printf("Digite a idade da pessoa %d: ", v + 1);
			break;
		}
		*status = scanf("%d", valor);
	}
}

void validasexo(char *sexo, int j)
{
	int sexovalido = *sexo == 'M' || *sexo == 'F';
	while (!sexovalido)
	{
		printf("Input inv�lido... \nDigite o sexo da pessoa %d: ", j + 1);
		scanf(" %c", sexo);
		*sexo= toupper(*sexo);
		sexovalido = *sexo == 'M' || *sexo == 'F';
	}
}

void validafilme(char *nome_filme, int *len)
{
	while (*len == TAM_FILME)
	{
		printf("Digite o nome do filme assistido pela pessoa: ");
		fgets(nome_filme, TAM_NOME, stdin);
		fflush(stdin);
		*len = strlen(nome_filme);
		printf("Nome do filme: %s\n", nome_filme);
	}
}

void pegasessoes(int* qtd_secoes)
{
	printf("Digite a quantidade de se��es que ser�o realizadas: ");
	int status = scanf("%d", qtd_secoes);
	fflush(stdin);
	validavalor(&status, qtd_secoes, 0, 0, 0);
	if (*qtd_secoes != 1) // 2
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
	validavalor(&status, qtd_pessoas, 1, 0, 0);
	if (*qtd_pessoas < 4) // 10
	{
		printf("� aceito no m�nimo 10 pessoas como input:\n");
		pegapessoas(qtd_pessoas);
	}
}

void pegaidades(PESSOAS* p, int qtd_sessoes, int qtd_pessoas,int k, int v)
{
	for (int i = k; i < qtd_sessoes; i++)
	{
		for (int j = v; j < qtd_pessoas; j++)
		{
			printf("Digite a idade da pessoa %d: ", j + 1);
			int status = scanf("%d", &p->idades[i][j]);
			fflush(stdin);
			validavalor(&status, &p->idades[i][j], 2, i, j);
			if (p->idades[i][j] < 3 || p->idades[i][j] > 100)
			{
				printf("� aceito somente idades entre 3 a 100 anos como input:\n");
				status = 0;			
			}
			validavalor(&status, &p->idades[i][j], 2, i, j);
			printf("idades[%d][%d] = %d\n", i, j, p->idades[i][j]);

			pegasexo(p, i, j); // Pega o sexo das pessoas

		}
	}
}

void pegasexo(PESSOAS *p, int i, int j)
{
	printf("Digite o sexo da pessoa %d: ", j + 1);
	scanf("%c", &p->sexo[i][j]);
	p->sexo[i][j] = toupper(p->sexo[i][j]);
	validasexo(&p->sexo[i][j], j);
	printf("sexo[%d][%d] = %c\n", i, j, p->sexo[i][j]);

}

void pegafilmes(char *nome_filmes)
{
	printf("Digite o nome do filme assistido pela pessoa: ");
	fgets(nome_filmes, TAM_NOME, stdin);
	fflush(stdin);
	int len = strlen(nome_filmes);
	printf("len = %d\n", len);
	printf("Nome do filme: %s\n", nome_filmes);
	validafilme(nome_filmes, &len);
}

void alocamemoria(PESSOAS* p, int qtd_sessoes, int qtd_pessoas)
{
	
	p->idades = malloc(sizeof(int*) * qtd_sessoes);
	p->sexo = malloc(sizeof(int*) * qtd_sessoes);

	for (int i = 0; i < qtd_sessoes; i++) // aloca um vetor com todos os elementos da matriz
	{
		printf("%d\n", i);
		p->idades[i] = malloc(sizeof(int) * qtd_pessoas);
		p->sexo[i] = malloc(sizeof(char) * qtd_pessoas);
	}
	printf("Memoria alocada\n");
}

void liberamemoria(PESSOAS* p, int qtd_sessoes)
{
	for (int i; i < qtd_sessoes; i++)
	{
		free(p->idades[i]);
		free(p->sexo[i]);
	}
	free(p->idades);
	free(p->sexo);
}

int main()
{
	
	setlocale(LC_ALL, "");

	// Vari�veis:
	PESSOAS p;
	int qtd_sessoes, qtd_pessoas, qtd_filmes;
	char* nome_filmes = malloc(sizeof(char) * TAM_NOME);

	dadosautor(); // Imprime os dados do autor
	pegafilmes(nome_filmes);
	pegasessoes(&qtd_sessoes); // Pega a quantidade de se��es 
	pegapessoas(&qtd_pessoas); // Pega a quantidade de pessoas
	alocamemoria(&p, qtd_sessoes, qtd_pessoas);
	pegaidades(&p, qtd_sessoes, qtd_pessoas, 0, 0); // Pega a idade das pessoas



	// Testando as sa�das: 
	printf("%d\n", qtd_sessoes);
	printf("%d\n", qtd_pessoas);
	printf("idades[0][2] = %d\n", p.idades[0][2]);
	printf("sexo[0][2] = %c\n", p.sexo[0][2]);

	// Liberendo a mem�ria da matriz:
	liberamemoria(&p, qtd_sessoes);
	free(nome_filmes);

}
