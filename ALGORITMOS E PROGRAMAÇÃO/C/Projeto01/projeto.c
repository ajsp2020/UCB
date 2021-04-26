
/*
NOME: Antonio Jo�o da Silva Pereira\n"
MATR�CULA: UC21106344
CURSO: Ci�ncias da Computa��o

Para esse projeto, eu tentei utilizar 3 conceitos implementados pelo autor do livro:

1- O uso do c�digo limpo do cap�tulo 1:

	Segundo Grandy Booch, autor do livro Object Oriented Analysis:

		"Um c�digo limpo � simple e direto. Ele � t�o bem legivel
		quanto uma prosa bem escrita. Ele jamais torna confuso o
		objetivo do desenvolvedor, em vez disso, ele est� repleto de
		abstra��es claras e linhas de controle objetivas.

2- Uso de Nomes Significativos do cap�tulo 2:

	"O nome de uma vari�vel, fun��o ou classe deve responder a todas as grandes quest�es.
	Ela deve lhe dizer porque existe, o que faz e como � usado. Se um nome requer um
	coment�rio, ent�o n�o revela seu prop�sito.

3 - cap�tulo 3:

	Fun��es pequenas com no m�ximo 20 linhas, bem endentadas e com um prop�sito �nico.
	(A fun��o deve fazer apenas uma coisa).
*/

#include<stdio.h> // Esta biblioteca cont�m v�rias fun��es de entrada e sa�da. 
#include<locale.h> // para implementar a localiza��o de programas.
#include<stdlib.h> // nescess�rio para usar as fun��es malloc e free e system
#include<string.h> //  Manipula��o de strings
#include <ctype.h> // para incluir a biblioteca do tooper
#include"projeto.h" // header file
#include "dados.h" // header file

// VALORES CONSTANTES PARA O PROCESSO DE VALIDA��O:

FILME f;
CLASSIFICACAO c;


// IMPRIME OS DADOS DO ALUNO:

void dadosAluno()
{
	printf("NOME: Antonio Jo�o da Silva Pereira\n"
			"MATR�CULA: UC21106344\n"
			"CURSO: Ci�ncias da Computa��o\n\n");
	Espera();
}

// LIMPA A TELA 
void limpaTela()
{
	system("cls");
}

// APLICA AS FUN��ES DE ACORDO COM OS INPUTS DO IMPRIMEMENU();
void direcionaResposta(int resp1, char* resp2)
{
	if (resp1 < 1 || resp1 > 6)
	{
		printf("Input inv�lido!\n");
		imprimeMenu();
	}
	//DIRECIONA AS FUN��ES DE ACORDO COM O INPUT:
	else if (resp1 == 1) pegaFilmes(&f);
	else if (resp1 == 2) imprimeFilme();
	else if (resp1 == 3) imprimeSessoes(c);
	else if (resp1 == 4) leTexto();
	else if (resp1 == 5) dadosAluno(); 
	else if (resp1 == 6)
	{
		// PERGUNTA SE DESEJA SAIR OU CONTINUAR NO MENU
		printf("Deseja sair (S/N): ");
		scanf(" %c", resp2);
		*resp2 = toupper(*resp2);
	}
}

// L� O TEXTO COM O ASSUNTO TE�RICO
void leTexto()
{
	FILE* arq;
	char Linha[150];
	char* result;
	int i;

	// Abre um arquivo TEXTO para LEITURA
	arq = fopen("introducao.txt", "rt");
	if (arq == NULL)  // Se houve erro na abertura
	{
		printf("Problemas na abertura do arquivo\n");
		return;
	}
	i = 1;
	while (!feof(arq))
	{
		// L� uma linha (inclusive com o '\n')
		result = fgets(Linha, 150, arq);  // o 'fgets' l� at� 149 caracteres ou at� o '\n'
		if (result)  // Se foi poss�vel ler
			printf("Linha %d : %s", i, Linha);
		i++;
	}
	fclose(arq);
	Espera();
}

// DA UMA PAUSE NO PROGRAMA E ESPERA "ENTER" COMO INPUT:
void Espera()  // Defini��o da fun��o "Espera"
{
	int tecla;
	while (tecla != 10) // nl(newline) = 10 na tabela ASCII (\n)
	{
		tecla = getchar();
		printf("Digite ENTER\n");
	}
}

// MENU
void menu()
{
	printf("Digite 1 para inserir os dados:\n"
		   "Digite 2 para imprimir o nome do filme, a quantidade de pessoas do sexo feminino e a quantidade de pessoas do sexo\n"
		   "         masculino que assistiram ao filme:\n"
		   "Digite 3 para imprimir quantidade de pessoas maiores de idade(idade maior ou igual a 18 anos) do sexo masculino e a\n"
		   "         quantidade de pessoas maiores de idade do sexo feminino que estiveram presentes em cada sess�o:\n"
		   "Digite 4 para ler o texo com a base te�rica:\n"
		   "Digite 5 para imprimir os dados do aluno:\n"
		   "Digite 6 para sair:\n");
}

// 
void imprimeMenu()
{
	int resp1;
	char resp2 = 'N';

	do 
	{    
		menu();
		// Iniciar meu struct com as vari�veis iniciar com 0 como padr�o
		// INPUT

		int status = scanf("%d", &resp1);
		validaValor(&status, &resp1, 3, 0);
		limpaTela();

		// JOGA PARA AS FUN��ES DE ACORDO COM O INPUT
		direcionaResposta(resp1, &resp2);
		Espera();
		limpaTela();

	} while (resp2 == 'N'); 
}

// IMPRIME DADOS DE ACORDO COM A QUEST�O 1 DO PROJETO
void imprimeFilme()
{
	int soma_f = 0;
	int soma_m = 0;
	for (int i = 0; i < retornaSessoes(f); i++)
	{
		soma_f += contaSexo(&f, i, 1, 1);
		soma_m += contaSexo(&f, i, 1, 0);
	}

	printf("NOME DO FILME: %s", retornaFilme(f));
	printf("PESSOAS DO SEXO FEMININO: %d\n", soma_f);
	printf("PESSOAS DO SEXO MASCULINO: %d\n", soma_m);
	Espera();
}

// IMPRIME DADOS DE ACORDO COM A QUEST�O 2 DO PROJETO
void imprimeSessoes()
{
	contaIdades(&f,&c,retornaSessoes(f));
	printf("QUANTIDADE DE PESSOAS POR CLASSIFICA��O DE IDADE:\n\n");
	printf("CRIAN�AS (3 AT� 13 ANOS): %d\n", c.criancas);
	printf("ADOLESCENTES (14 AT� 17 ANOS): %d\n", c.adolecentes);
	printf("ADULTOS (18 AT� 64 ANOS): %d\n", c.adultos);
	printf("IDOSOS (65 AT� 100 ANOS): %d\n", c.idosos);
	
	int maiores;
	int masculino = 0;
	int feminino = 0;
	printf("\nPESSOAS MAIORES QUE 18: \n\n");
	for (int i = 0; i < retornaSessoes(f); i++)
	{
		printf("SESS�O %d:\n", i + 1);
		masculino = contaSexo(&f,i, 2, 0);
		feminino = contaSexo(&f,i, 2, 1);
		printf("PESSOAS MAIORES DE 18 DO SEXO MASCULINO: %d \n", masculino);
		printf("PESSOAS MAIORES DE 18 DO SEXO FEMININO: %d \n", feminino);
	}
	Espera();
}

int main()
{
	setlocale(LC_ALL, "");
	printf("Projeto pr�tico 01:\n");

	imprimeMenu();
	liberaMemoria(&f);

	return 0;
}
