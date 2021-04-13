#include<stdio.h>
#include<locale.h>

void apresentacao()
{
	printf("Quest�o 11:\n");
	printf(" Alterar o exerc�cio do tri�ngulo (exerc�cio 9), de forma que o algoritmo apresente no caso de\n"
		 "tri�ngulo o seu tipo : equil�tero(todos os lados s�o iguais), is�sceles(dois lados iguais) ou um\n"
		 "outro tri�ngulo qualquer(escaleno).Apresente o algoritmo, fazendo o teste do algoritmo\n"
		 "(chinesinho) ao lado\n");
}

void validalado(int status, float* lado, int i)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido... \nDigite o valor do lado %d: ", i + 1);
		status = scanf("%f", lado);
	}
}

void pegalados(float lados[3])
{
	float lado;
	int status;
	for (int i = 0; i < 3; i++)
	{
		printf("Digite o valor do lado %d: ", i + 1);
		status = scanf("%f", &lado);
		validalado(status, &lado, i);
		lados[i] = lado;
	}
}
int ehtriangulo(float lados[3])
{
	float soma = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
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

void quetriangulo(float lado[3], char *triangulo, int* ladosiguais) // preciso mudar 
{	
	for (int i = 0; i < 2; i++)
	{
		for (int j = 1; j < 3; j++)
		{
			if (i != j) {
				if(lado[i] == lado [j]) (*ladosiguais)++;
			}
		}
	}
}

void imprimevalor(float lados[3], int ladosiguais)
{
	if (ehtriangulo(lados))
	{
		printf("Pode constituir os lados de um tri�ngulo.\n");

		if (ladosiguais == 1) printf("Tri�ngulo Is�celes");
		else if (ladosiguais == 0) printf("Tri�ngulo Escaleno");
		else printf("Tri�ngulo Equil�tero");
	}
	else printf("N�o pode constituir os lados de um tr�ngulo.\n");
}

int main()
{
	setlocale(LC_ALL, "");
	float lados[3];
	char triangulo[20];
	int ladosiguais = 0;

	apresentacao();
	pegalados(lados);
	quetriangulo(lados, triangulo, &ladosiguais);
	imprimevalor(lados, ladosiguais);
}