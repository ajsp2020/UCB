#include<stdio.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "");
	int idade;
	printf("Informe a idade: ");
	scanf("%d", &idade); //%i
	fflush(stdin); // Limpar buffer de mem�ria


	if (idade >= 61) printf("Idoso");
	else if (idade >= 41) printf("Aldulto2");
	else if (idade >= 18) printf("Adulto");
	else if (idade >= 11) printf("Adolecente");
	else if (idade >= 4) printf("Crian�a");
	else if (idade >= 0) printf("Beb�");
	else {
		printf("N�o pode idade negativa\n");
		main();
	}

	return 0;
}