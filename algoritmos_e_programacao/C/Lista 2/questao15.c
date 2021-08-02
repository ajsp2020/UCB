#include<stdio.h>
#include<locale.h>


void apresentacao()
{
	printf("Quest�o 15:\n Fa�a um algoritmo que calcule e escreva o valor a ser pago a sua provedora de acesso �\n"
		"Internet, para isso voc� dever� ler a quantidade de horas que voc� utilizou.Sabe - se que voc�\n"
		"pagar� R$ 30, 00 por at� 20 horas de uso(va1or b�sico), caso voc� tenha usado mais de 20\n"
		"horas, ent�o voc� deve acrescentar 10 \\% do valor b�sico para cada hora extra utilizada.\n");
}

void validavalor(int status, float* valor)
{
	int temp, input;
	while (status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido....\n");
		printf("Digite a quantidade de horas de internet utilizada: ");

		status = scanf("%f", valor);
	}
}

void pegahoras(float* horas)
{
	printf("Digite a quantidade de horas de internet utilizada: ");
	int status = scanf("%f", horas);
	validavalor(status, horas);
}

void calculavalor(float* valor, float horas)
{
	if (horas <= 20) *valor = 30;
	else *valor = 30 + (horas - 20) * 30 * 0.1;
}

void imprimevalor(float valor)
{
	printf("Valor a ser pago R$ %.2f", valor);
}

int main()
{
	float horas, valor;
	setlocale(LC_ALL, "");
	apresentacao();
	pegahoras(&horas);
	calculavalor(&valor, horas);
	imprimevalor(valor);
}