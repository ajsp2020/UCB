#include <stdio.h> // Inclus�o da biblioteca printf e scanf
#include <stdlib.h> // Biblioteca para o exit(1)
#include <locale.h> // Localiza o programa 
#include <math.h> // Biblioteca para opera��es matem�ticas

void abertura() { 
	printf("C�lculo da f�rmula de Bhaskara:\n");
	printf("x = (-b +/- raiz(b**2 - 4 * a * c)) / (2 * a)\n");
}

void entradadedados(double* a, double* b, double* c) { // Entra com os valores em a, b, c
	printf("Digite o valor de a: ");
	scanf("%lf", a);

	printf("Digite o valor de b: ");
	scanf("%lf", b);

	printf("Digite o valor de c: ");
	scanf("%lf", c);
}

void calculabhaskara(double* delta, double* x1, double* x2, double a, double b, double c) {
	*delta = pow(b, 2) - 4 * a * c; // Calcula o delta 
	int podecalcular = (*delta >= 0 & a != 0); // Verifica se � poss�vel fazer o c�lculo

	if (!podecalcular) { 
		printf("A equa��o do segundo grau n�o possui raizes reais.\n");
		exit(1);
	}
	else if (*delta == 0) {
		printf("A equa��o possui somente uma raiz real: \n");
		*x1 = -b / (2 * a);
	}
	else {
		printf("A equa��o possui duas raizes reais:\n");
		*x1 = ((-b + sqrt(*delta)) / (2 * a));
		*x2 = ((-b - sqrt(*delta)) / (2 * a));
	}
	
}

void imprimeresultado(double x1, double x2, double delta) {
	if (delta == 0) { // Imprime o resultado caso delta = 0
		printf("X = %.2f", x1);
	}
	else { // Imprime o resultado caso delta > 0
		printf("X1 = %.2f\t X2 = %.2f\n", x1, x2);
	}
}

int main() {
	double a, b, c, x1, x2, delta;

	setlocale(LC_ALL, "");
	abertura();
	entradadedados(&a , &b, &c);
	calculabhaskara(&delta, &x1, &x2, a, b, c);
	imprimeresultado(x1, x2, delta);
}