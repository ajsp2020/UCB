#include <stdio.h>
#include <locale.h>

void apresentacao() 
{
	printf("Quest�a 6:\n");
	printf("Escrever um algoritmo que determine se um n�mero inteiro qualquer � PAR ou IMPAR.\n\n");
}

void validanumero(int status, int* numero)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido...\nDigite um n�mero inteiro: ");
		status = scanf("%d", numero);
	}
}

int ehpar(int numero)
{
	if (numero % 2 == 0) return 1;
	return 0;
}

void peganumero(int* numero)
{
	printf("Digite um n�mero inteiro: ");
	int status = scanf("%d", numero);
	validanumero(status, numero);
}

void imprimeresultado(int numero)
{
	if (ehpar(numero)) printf("O valor � par.");
	else printf("O valor � impar.");
}

int main()
{
	int numero;
	setlocale(LC_ALL, "");
	apresentacao();
	peganumero(&numero);
	imprimeresultado(numero);
}