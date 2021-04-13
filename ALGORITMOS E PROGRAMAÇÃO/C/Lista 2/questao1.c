#include <stdio.h>
#include <locale.h>
#include <string.h>

#define TAM_PLACA 8

void abertura() 
{
	printf("Quest�o 1:\nConstrua um algoritmo que a partir da leitura da velocidade e placa do carro, avise ao\n"
		"motorista somente se ele ser� multado, quando estiver trafegando no Eixo Rodovi�rio \n(limite"
		"de 80 km / h)\n\n");
}

void validavalor(int status, int* valor)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido....\n");
		if (*valor < 0) printf("N�o � aceito valores negativos!\n");

		printf("Digite a velocidade do ve�culo: ");
		status = scanf("%d", valor);
	}
}

void levelocidade(int* velocidade) 
{
	printf("Digite a velocidade do ve�culo: ");
	int status = scanf("%d", velocidade);
	validavalor(status, velocidade);
}

void leplaca(char placa[TAM_PLACA]) 
{
	printf("Digite a placa do carro: ");
	scanf("%s", placa);
}

int seramutado(int velocidade) 
{
	if (velocidade > 80) return 1;
	return 0;
}

void imprimedados(int vel, char placa[TAM_PLACA], int velocidade) 
{
	if (seramutado(velocidade)) printf("Ve�culo placa %s esta trafegando com velocidade de %d km/h: Ser� multado", placa, vel);
	else  printf("Ve�culo placa %s esta trafegando com velocidade de %d km/h: N�o ser� multado", placa, vel); //Resposta: Quest�o 5
}

int main() 
{
	setlocale(LC_ALL, "");

	int velocidade;
	char placa[TAM_PLACA];

	abertura();
	levelocidade(&velocidade);
	leplaca(placa);
	imprimedados(velocidade, placa, velocidade);
}