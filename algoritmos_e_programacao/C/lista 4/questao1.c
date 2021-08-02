#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "");
	
	

	int ano, mes, dia;
	

	printf("Digite o ano: ");
	scanf("%d", &ano);

	printf("Digite o m�s: ");
	scanf("%d", &mes);

	printf("Digite o dia: ");
	scanf("%d", &dia);

	int mesesComTrintaUm = mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12;
	int mesesComTrinta= mes == 4 || mes == 6 || mes == 9 || mes == 11;

	if (mesesComTrintaUm)
	{
		switch (dia)
		{
		case 0 ... 31:
			printf("Data V�lida.");
			break;
		default:
			printf("Data inv�lida");
			break;
		}
	}
	else if (mesesComTrinta)
	{
		switch (dia)
		{
		case 0 ... 30:
			printf("Data V�lida.");
			break;
		default:
			printf("Data inv�lida");
			break;
		}
	}

	else if (mes == 2)
	{
		if (ano % 4 == 0)
		{
			switch (dia)
			{
			case 0 ... 29:
				printf("Data V�lida.");
				break;
			default:
				printf("Data inv�lida");
				break;
			}
		}
		else
		{
			switch (dia)
			{
			case 0 ... 28:
				printf("Data V�lida.");
				break;
			default:
				printf("Data inv�lida");
				break;
			}
		}
	}
	else printf("Data Inv�lida!");
}