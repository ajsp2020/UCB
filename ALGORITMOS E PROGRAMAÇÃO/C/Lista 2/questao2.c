#include <stdio.h>
#include <locale.h>
//#include <math.h>


void apresentacao() 
{
	printf("Quest�o 2\nEfetuar a leitura de um n�mero e apresent�-lo como o seu m�dulo (somente seu valor"
		"absoluto) elaborando os c�lculos matem�ticos para isso.\n\n");
}
void validanumero(int status, double* numero) 
{
	int input, temp;
	while (status != 1) {
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input invalido. Digite um novo valor: ");
		status = scanf("%lf", numero);
	}
}

void peganumero(double* numero) 
{
	int status;
	printf("Digite o valor de um n�mero: ");
	status = scanf("%lf", numero);
	validanumero(status, numero);
}

void calculaabs(double* numero) 
{
	//*numero = fabs(*numero);
	if (*numero < 0)
	{
		*numero = -(*numero);
	}
}

void imprimeresultado(double numero) 
{
	printf("%.2lf", numero);
}

int main() 
{
	setlocale(LC_ALL, "");

	double numero;

	apresentacao();
	peganumero(&numero);
	calculaabs(&numero);
	imprimeresultado(numero);
}