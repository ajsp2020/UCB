#include <stdio.h>
#include<locale.h>

void apresentacao()
{
	printf("Quest�o 1:\nConstrua um algoritmo que calcule o fatorial de um n�mero usando a estrutura PARA...FA�A,\n"
		"baseando - se na defini��o matem�tica(N!= 1x2x3x...x N - 1 x N e 0!= 1 por defini��o\n");
}

int factorial(int n, int* soma)
{
	if (n == 0) return 1;
	else
	{
		*soma *= n;
		factorial(n - 1, soma);
	}
}
void pegavalor(int* n)
{
	int status;

	do
	{
		fflush(stdin);
		printf("Digite o valor de n: ");
		status = scanf("%d", n);

	} while (status != 1);
}

void imprimeresposta(int soma, int n)
{
	printf("O factorial de %d �: %d",n, soma);
}

int main()
{
	int n = 0, soma = 1;
	setlocale(LC_ALL, "");
	apresentacao();
	pegavalor(&n);
	factorial(n, &soma);
	imprimeresposta(soma, n);
	return 0;
}