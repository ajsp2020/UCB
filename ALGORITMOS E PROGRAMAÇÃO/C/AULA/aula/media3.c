/*
Leia quatro n�meros (N1, N2, N3, N4), cada um deles com uma casa decimal, correspondente �s quatro notas de um aluno. Calcule a m�dia com pesos 2, 3, 4 e 1, respectivamente, 
para cada uma destas notas e mostre esta m�dia acompanhada pela mensagem "Media: ". Se esta m�dia for maior ou igual a 7.0, imprima a mensagem "Aluno aprovado.". Se a m�dia 
calculada for inferior a 5.0, imprima a mensagem "Aluno reprovado.". Se a m�dia calculada for um valor entre 5.0 e 6.9, inclusive estas, o programa deve imprimir a mensagem "Aluno em exame.".
*/

#include<stdio.h>

int main()
{
	float n1, n2, n3, n4;

	printf("Digite os notas: ");
	scanf("%f%f%f%f", &n1, &n2, &n3, &n4);
	media = n1 * 0.2 + n2 * 0.3 + n3 * 0.4 + n4 * 0.1;
	printf("Media: %.1f", media);

	if (media >= 7) printf("Aprovado!\n");
	else if (media >= 5) printf("Exame final!\n");
	else printf("Reprovado!");

	return 0;
}