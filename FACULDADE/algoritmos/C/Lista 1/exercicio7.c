#include <stdio.h>
#include <locale.h>
#include<string.h>

struct trabalho {

	int horas;
	float salariohora;
	float salario;
	
};
typedef struct trabalho TRABALHO;


struct funcionario
{
	char nome[50];
	char sexo[1];
	char matricula[10];
	TRABALHO t;

};
typedef struct funcionario FUNCIONARIO;

void setsexo();
void apresentacao();
int  validasexo();
void setsexo();
void setnome();
void setmatricula();
void sethorastrabalhadas();
void setsalariohora();
void calculasalario();
void imprimeresultado();
void salvaarquivo();

int main() {
	setlocale(LC_ALL, "");
	apresentacao();
	int quantidade = 0;
	int funcionarios;

	printf("Digite a quantidade de funcion�rios: ");
	scanf("%d", &funcionarios);
	do {
		FUNCIONARIO f1;	
		setnome(&f1);
		setsexo(&f1);
		setmatricula(&f1);
		sethorastrabalhadas(&f1);
		setsalariohora(&f1);
		calculasalario(&f1);
		imprimeresultado(&f1, &quantidade);
		salvaarquivo(&f1);

	} while (quantidade < funcionarios);
	
}


void apresentacao() {
	
	printf("Quest�o Sete:\n");
	printf("Escreva um programa que leia o nome do funcion�rio, o sexo (F ou M), o n�mero de\n"
		"matr�cula do funcion�rio, o n�mero de horas trabalhadas, o valor que recebe por hora\n"
		"e calcule o sal�rio desse funcion�rio.A seguir, mostre todos os dados na tela, os dados\n"
		"de entrada e os dados de sa�da.\n");
}
int  validasexo(FUNCIONARIO* f) {
	char valido[2] = {'M', 'F'};

	int ehvalido = f->sexo[0] == valido[0] || f->sexo[0] == valido[1];
	if (!ehvalido) {
		printf("Precione 'M' para sexo masculino ou 'F' Para sexo feminino \n");
		setsexo(&f);
	}
	else {
		return 0;
	}
	
}
void setsexo(FUNCIONARIO* f){
	printf("Digite o sexo (M/F): ");
	scanf("%s", f->sexo);
	validasexo(f);
}
void setnome(FUNCIONARIO* f) {

	printf("Digite o nome do funcionario: ");
	scanf("%s", f->nome);
	
}
void setmatricula(FUNCIONARIO* f) {
	printf("Digite a matr�cula do funcionario: ");
	scanf("%s", f->matricula);
}
void sethorastrabalhadas(FUNCIONARIO* f) {
	int horas;
	printf("Digite a quantidade de horas trabalhadas: ");
	scanf("%d", &horas);
	f->t.horas = horas;
	
}
void setsalariohora(FUNCIONARIO* f) {
	float salario;
	printf("Digite o sal�rio hora do funcion�rio: ");
	scanf("%f", &salario);
	f->t.salariohora = salario;
}
void calculasalario(FUNCIONARIO* f) {
	f->t.salario = f->t.horas * f->t.salariohora;
}
void imprimeresultado(FUNCIONARIO* f, int* quantidade) {
	printf("FUNCION�RIO(A): %s\n", f->nome);
	printf("SEXO: %c\n", f->sexo[0]);
	printf("MATR�CULA: %s\n", f->matricula);
	printf("HORAS DE TRABALHO (H): %d\n", f->t.horas);
	printf("SAL�RIO HORA (R$/H): %.2f\n", f->t.salariohora);
	printf("SAL�RIO (R$): %.2f\n", f->t.salario);
	(*quantidade)++;
}
void salvaarquivo(FUNCIONARIO *f ) {
	FILE* t;
	t = fopen("exercicio7.txt", "r+");
	int qtd;
	fscanf(t, "%d", &qtd);
	qtd++;
	fseek(t, 0, SEEK_SET);
	fprintf(t, "%d", qtd);

	fseek(t, 0, SEEK_END);

	fprintf(t, "FUNCION�RIO(A): %s\n", f->nome);
	fprintf(t, "SEXO: %c\n", f->sexo[0]);
	fprintf(t, "MATR�CULA: %s\n", f->matricula);
	fprintf(t, "HORAS DE TRABALHO: %d\n", f->t.horas);
	fprintf(t, "SAL�RIO HORA: %.2f\n", f->t.salariohora);
	fprintf(t, "SAL�RIO: %.2f\n", f->t.salario);
	fclose(t);
}


