#include<stdio.h>
#include <stdlib.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int regioes;
	do {
		fflush(stdin);
		printf("Qual regi�o do pais gostaria de conhecer?:\n");
		printf("Menu de Op��es\n"
			"============\n"
			"1 � Norte\n"
			"2 � Nordeste\n"
			"3 � Centro - Oeste\n"
			"4 � Sudeste\n"
			"5 � Sul\n"
			"0 � Sair do programa\n");
		scanf("%d", &regioes);
		system("cls");
		if (regioes != 0)
		{
			switch (regioes)
			{
			case 1:
				printf("Voc� gostaria de conhecer a regi�o Norte:\n");
				break;
			case 2:
				printf("Voc� gostaria de conhecer a regi�o Nordeste:\n");
				break;
			case 3:
				printf("Voc� gostaria de conhecer a regi�o Centro-Oeste:\n");
				break;
			case 4:
				printf("Voc� gostaria de conhecer a regi�o Sudeste:\n");
				break;
			case 5:
				printf("Voc� gostaria de conhecer a regi�o Sul:\n");
				break;
			default:
				break;
			}

			system("pause");
		}
		
	} while (regioes != 0);

	return 0;

}