#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int mes;
	int dia;

	printf("Digite o dia: ");
	scanf("%d", &dia);

	printf("Digite o m�s: ");
	scanf("%d", &mes);

	switch (mes)
	{
	case 1:
		if (dia <= 20 && dia > 0) printf("Capric�rnio");
		else if (dia > 20 && dia <= 31) printf("Aqu�rio");
		break;

	case 2:
		if (dia <= 20 && dia > 0) printf("Aqu�rio");
		else if (dia > 20 && dia <= 28) printf("Peixes");
		break;

	case 3:
		if (dia <= 20 && dia > 0) printf("Peixes");
		else if (dia > 20 && dia <= 31) printf("�ries");
		break;

	case 4:
		if (dia <= 20 && dia > 0) printf("�ries");
		else if (dia > 20 && dia <= 30) printf("Touro");
		break;

	case 5:
		if (dia <= 20 && dia > 0) printf("Touro");
		else if (dia > 20 && dia <= 31) printf("G�meos");
		break;

	case 6:
		if (dia <= 20 && dia > 0) printf("G�meos");
		else if (dia > 20 && dia <= 30) printf("C�ncer");
		break;

	case 7:
		if (dia <= 20 && dia > 0) printf("C�ncer");
		else if (dia > 20 && dia <= 31) printf("Le�o");
		break;

	case 8:
		if (dia <= 20 && dia > 0) printf("Le�o");
		else if (dia > 20 && dia <= 31) printf("Virgem");
		break;

	case 9:
		if (dia <= 20 && dia > 0) printf("Virgem");
		else if (dia > 20 && dia <= 30) printf("Libra");
		break;

	case 10:
		if (dia <= 20 && dia > 0) printf("Libra");
		else if (dia > 20 && dia <= 31) printf("Escorpi�o");
		break;

	case 11:
		if (dia <= 20 && dia > 0) printf("Escorpi�o");
		else if (dia > 20 && dia <= 30) printf("Sargit�rio");
		break;

	case 12:
		if (dia <= 20 && dia > 0) printf("Sargit�rio");
		else if (dia > 20 && dia <= 31) printf("Capric�rnio");
		break;

	default:
		break;
	}


}