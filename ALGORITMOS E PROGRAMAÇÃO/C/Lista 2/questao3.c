#include <stdio.h>
#include <locale.h>

#define LADOS 3

void apresentacao() 
{
	printf("Quest�o 3:\nDado tr�s valores, verificar se eles podem constituir os lados de um tri�ngulo \n(tri�ngulo � uma"
		"figura geom�trica onde cada lado � menor do que a soma dos outros dois lados).\n\n");
}

void validavalor(int status, float* valor, int i)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido....\n");
		if (*valor < 0) printf("N�o � aceito valores negativos!\n");

		printf("Digite o valor do lado %d: ", i + 1);
		status = scanf("%d", valor);
	}
}

void pegalados(float lados[LADOS]) 
{
	float lado;
	int status;
		for (int i = 0; i < LADOS; i++) 
		{
			printf("Digite o valor do lado %d: ", i + 1);
			status = scanf("%f", &lado);
			validavalor(status, &lado, i);
			lados[i] = lado;
		}	
}

int ehtriangulo(float lados[LADOS]) 
{
	float soma = 0;
	for (int i = 0; i < LADOS; i++) 
	{
		for (int j = 0; j < LADOS; j++) 
		{
			if (i != j) 
			{
				soma += lados[j];
			}
		}
		if (lados[i] > soma) return 0;

		soma = 0;
	}
	return 1;	
}

void imprimevalor(float lados[LADOS]) 
{
	if (ehtriangulo(lados)) printf("Pode constituir os lados de um tri�ngulo.\n");
	else printf("N�o pode constituir os lados de um tr�ngulo.\n"); //Resposta: Quest�o 5
}

int main() 
{
	setlocale(LC_ALL, "");
	float lados[LADOS];

	apresentacao();
	pegalados(lados);
	imprimevalor(lados);

	return 0;
}