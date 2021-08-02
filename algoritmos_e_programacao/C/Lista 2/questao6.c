#include <stdio.h>
#include <locale.h>

void apresentacao() 
{
	printf("Quest�a 6:\nEscrever um algoritmo que determine se um n�mero inteiro qualquer � PAR ou IMPAR.\n\n");
}

void validavalor(int status, int* valor)
{
	int temp, input;
	while (status != 1)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido....\n");

		printf("Digite um n�mero inteiro: ");
		status = scanf("%d", valor);
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
	validavalor(status, numero);
}

void imprimeresultado(int numero)
{
	if (ehpar(numero)) printf("O valor � par.");
	else printf("O valor � impar.");
}

int main()
{
	setlocale(LC_ALL, "");

	int numero;
	
	apresentacao();
	peganumero(&numero);
	imprimeresultado(numero);
}