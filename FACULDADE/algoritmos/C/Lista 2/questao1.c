#include <stdio.h>
#include <locale.h>
#include <string.h>



void abertura() {
	printf("Primeira quest�o\n");
	printf("Construa um algoritmo que a partir da leitura da velocidade e placa do carro, avise ao"
		"motorista somente se ele ser� multado, quando estiver trafegando no Eixo Rodovi�rio (limite"
		"de 80 km / h)\n");
}

void levelocidade(int* velocidade) {
	int status, temp, input;
	printf("Digite a velocidade do ve�culo: ");
	status = scanf("%d", velocidade);
	
}

void leplaca(char placa[8]) {
	printf("Digite a placa do carro: ");
	scanf("%s", placa);
}

int seramutado(int velocidade) {
	if (velocidade > 80) return 1;
	return 0;
}

void imprimedados(int vel, char placa[8], int velocidade) {
	printf("%d\n", vel);
	printf("%s\n", placa);
	if (seramutado(velocidade)) printf("Ser� multado");
}

int main() {
	setlocale(LC_ALL, "");
	int velocidade;
	char placa[8];
	abertura();
	levelocidade(&velocidade);
	leplaca(placa);
	imprimedados(velocidade, placa, velocidade);
	

}