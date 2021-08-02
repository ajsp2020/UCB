#include <stdio.h>
#include <locale.h>

void apresentacao()
{
	printf("Qust�o 2:\nFa�a um algoritmo que leia dois n�meros calcule o resultado da multiplica��o de um pelo\n"
		"outro sem utilizar a opera��o de multiplica��o(ou seja, utilizando apenas soma)\n");
}

int multiplicacao(int valor1, int valor2)
{
	if (valor2 == 0) return 0;
	else if (valor2 == 1) return valor1;
	else return valor1 + multiplicacao(valor1, valor2 - 1);
}


void pegaValor(int* valor1, int* valor2)
{
	int status;

		fflush(stdin);
		printf("Digite o primeiro valor: ");
		scanf("%d", valor1);
		printf("Digite o segundo valor: ");
		scanf("%d", valor2);
}

int main()
{
	int valor1, valor2;
	setlocale(LC_ALL, "");
	apresentacao();
	pegaValor(&valor1, &valor2);
	int resultado = multiplicacao(valor1, valor2);
	printf("%d X %d = %d",valor1, valor2, resultado);
}