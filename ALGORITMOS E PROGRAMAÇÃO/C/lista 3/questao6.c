#include<stdio.h>
#include<locale.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "");
	float notas_homens, notas_mulheres, nota;
	char sexo;
	int M = 0, F = 0;
	int ehValido;
	do 
	{
	
		
		printf("Digite a nota do aluno(a): ");
		scanf("%f", &nota);
		if (nota < 0) continue;
		else 
		{
			do 
			{
				printf("Digite o sexo do aluno (M - Masculino / F - Ferminino): ");
				scanf(" %c", &sexo);
				ehValido = (sexo == 'M' || sexo == 'F');

			} while (!ehValido);

			if (sexo == 'M')
			{
				notas_homens += nota;
				M++;
			}

			else
			{
				notas_mulheres += nota;
				F++;
			}

		}


	} while (nota >= 0);
	

	printf("A m�dia das notas dos homens �: %.2f\n", notas_homens / M);
	printf("A m�dia das notas das mulheres �: %.2f\n", notas_mulheres / F);
}