#include<stdio.h>

#include<locale.h>

void apresentacao()
{
	printf("Quest�o 11:\nAlterar o exerc�cio do tri�ngulo (exerc�cio 9), de forma que o algoritmo apresente no caso de\n"
		 "tri�ngulo o seu tipo : equil�tero(todos os lados s�o iguais), is�sceles(dois lados iguais) ou um\n"
		 "outro tri�ngulo qualquer(escaleno).Apresente o algoritmo, fazendo o teste do algoritmo\n"
		 "(chinesinho) ao lado\n");
}

void validalado(int status, float* lado, int i) // Tem a fun��o de verifcar se os valores s�o v�lidos
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido... \nDigite o valor do lado %d: ", i + 1);
		status = scanf("%f", lado);
	}
}

void pegalados(float lados[3]) // Pegando os lados do tri�ngulo
{
	float lado;
	int status;
	for (int i = 0; i < 3; i++) 
	{
		printf("Digite o valor do lado %d: ", i + 1);
		status = scanf("%f", &lado); // lados = [1, 1, 2]
		validalado(status, &lado, i);
		lados[i] = lado;
	}
}
int ehtriangulo(float lados[3])// lados = [1, 1, 2] Vou pegar o valor de um lado, comparar com a soma dos dois e verificar se � ou n�o 
{
	float soma = 0;
	for (int i = 0; i < 3; i++) // i = 0 / i = 1
	{
		for (int j = 0; j < 3; j++) // j = 0 -> j = 1 -> j = 2 / j = 0 -> j = 1 -> j = 2 / ....
		{
			if (i != j) // (0 != 0)F -> (0 != 1) V -> V / (1 != 0) V -> (1 != 1)F -> (1 != 2) V / ....
			{
				soma += lados[j]; // F -> O + 1 -> 1 + 1 / 1 + 1 -> F -> 2 + 2 /....
			}
		}
		if (lados[i] > soma) return 0; // (1 > 2) F / (1 > 4)F /....

		soma = 0; // Zerando a soma
	}
	return 1;
}

void quetriangulo(float lado[3], int* ladosiguais) // Aqui estou iterando sobre todos os elementos desse array e verificando se um lado � igual ao outro
{
	for (int i = 0; i < 2; i++)
	{
		if (lado[i] == lado[i + 1]) (*ladosiguais)++; // caso seja igual estou somando um com o outro 
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
	int ladosiguais = 0; // assuminfo a princ�pio que todos os lados s�o diferentes 

	apresentacao();
	pegalados(lados);
	quetriangulo(lados, &ladosiguais);
	imprimevalor(lados, ladosiguais);
}