#include <stdio.h>
// Construa um algoritmo que leia um n�mero inteiro de horas e mostre ao usu�rio o 
//correspondente em minutos e segundos destas horas.

int main() {
	int horas, minutos, segundos;

	printf("Digite a hora: ");
	scanf("%d", &horas);

	minutos = horas * 60;
	segundos = minutos * 60;

	printf("Valor em minutos: %d\n", minutos);
	printf("Valor em segundos: %d\n", segundos);

	return 0;
}