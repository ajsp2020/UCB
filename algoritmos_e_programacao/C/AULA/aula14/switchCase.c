#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "");
	printf("Aula: switch case\n");

	idade = 45;

	switch (idade)
	{
	case 0 ... 5: printf("Crian�a"); break;
	case 6 ... 10: printf("1111"); break;
	case 11 ... 15: printf("Cria22n�a"); break;
	case 16 ... 30: printf("Cri33an�a"); break;
	default: print("Valor inv�lido"); break;
	}

	return 0;
}