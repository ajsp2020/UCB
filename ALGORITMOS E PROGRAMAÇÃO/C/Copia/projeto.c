
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


// VALORES CONSTANTES PARA O PROCESSO DE VALIDA��O:

// VALIDANDO OS DADOS:
// VALIDA DADOS DE ENTRADA PARA VALORES INTEIRO
//void validavalor(int* status, int* valor, valor no switch, valor de entrada, contador)
#define NUM_SESSOES 2 // quantidade de sess�es permitidas
#define NUM_PESSOAS 10 // quantidade m�nima de pessoas permitida
#define TAM_FILME 1 // tamanho m�nimo que � aceito como input para o nome do filme
#define TAM_NOME 40 // tamanho m�ximo que � aceito como input para o tamanho do filme 

//STRUCTS
struct sexo
{
	char** sexo; // Define um array com {{valores_sessao1}, {valores_sessao2}}  (neste caso um ponteiro de ponteiro) para o sexo
	int* masculino; // Um array com tamanho de (int * sessoes) para salvar a quantidade de pessoas do sexo masculinho por sessao
	int* feminino; // Um array com tamanho de (int * sessoes) para salvar a quantidade de pessoas do sexo feninino por sessao
};
typedef struct sexo SEXO;

struct pessoas
{
	int* pessoas; // Um array com tamanho de (int * sessoes) para salvar a quantidade de pessoas por sessao
	int** idades; // Define um array com {{valores_sessao1}, {valores_sessao2}}  (neste caso um ponteiro de ponteiro) para a idade
	SEXO s;
};
typedef struct pessoas PESSOAS;

struct filme
{
	char* nome; // Define um array que vai guardar o nome do filme (um ponteiro)
	int sessoes; // Um array  para salvar a quantidade de sessoes 
	PESSOAS p;
};

typedef struct filme FILME;

struct classificacao // Salva a quantidade de pessoas por classifica��o
{
	int criancas;
	int adolecentes;
	int adultos;
	int idosos;
}; // Define as vari�veis criadas com o valor zero 
typedef struct classificacao CLASSIFICACAO;



FILME f;
CLASSIFICACAO c;

void validaValor(int* status, int* valor, int entrada, int contador);
void validaSexo(char* sexo, int j);
void validaFilme(char* nome_filme, int* len);
int pegaSessoes(FILME* f);
void pegaPessoas(FILME* f);
void pegaIdades(FILME* f, int sessao, int pessoa);
void pegaSexo(FILME* f, int i, int j);
void pegaFilmes(FILME* f);
void alocaMemoria(FILME* f);
void alocaMemoria_(FILME* f);
void liberaMemoria(FILME* f);
void contaIdades(FILME* f, CLASSIFICACAO* c, int sessoes);
int contaSexo(FILME* f, int valor, int questao, int sexo);
void menu();
void limpaTela();
int retornaSessoes(FILME f);
char* retornaFilme(FILME f);
void dadosAluno();
void direcionaResposta(int resp1, char* resp2);
void leTexto();
void Espera();
void imprimeMenu();
void imprimeFilme();
void imprimeSessoes();


void validaValor(int* status, int* valor, int entrada, int contador)
{
	int temp, input;

	if (entrada == 2 && (*valor < 3 || *valor > 100)) *status = 0;

	while (*status != 1 || *valor < 0)
	{
		while ((temp = getchar()) != EOF && temp != '\n');
		printf("Input inv�lido....\n");

		switch (entrada)
		{
		case 0: // Para sessoes 
			printf("Digite a quantidade de se��es que ser�o realizadas: ");
			break;

		case 1: // Para pessoas
			printf("Digite a quantidade de pessoas que assistiram a se��o: ");
			break;

		case 2: // Para idade
			printf("Digite a idade da pessoa %d: ", contador + 1);
			break;

		case 3:
			limpaTela();
			menu();
			break;
		}
		*status = scanf("%d", valor);
		if (entrada == 2 && (*valor < 3 || *valor > 100)) *status = 0;
	}
}

// PEGANDO OS DADOS: 
// VALIDA OS DADOS PARA O SEXO
void validaSexo(char* sexo, int j)
{
	int sexovalido = *sexo == 'M' || *sexo == 'F';
	while (!sexovalido)
	{
		printf("Input inv�lido... \nDigite o sexo da pessoa %d: ", j + 1);
		scanf(" %c", sexo);
		*sexo = toupper(*sexo);
		sexovalido = *sexo == 'M' || *sexo == 'F';
	}
}

// VALIDA OS DADOS PARA O NOME DO FILME
void validaFilme(char* nome_filme, int* len)
{
	while (*len == TAM_FILME) //	enquanto o valor for igual 1 vai:
	{
		limpaTela();  // Limpa a tela
		printf("Digite o nome do filme: "); // Pergunta o nome
		fgets(nome_filme, TAM_NOME, stdin);
		fflush(stdin);
		*len = strlen(nome_filme);
	}
}

// PEGANDO A QUANTIDADE DE SESSOES:
int pegaSessoes(FILME* f)
{
	printf("Digite a quantidade de se��es que ser�o realizadas: "); // Pega o numero de sessoes 
	int status = scanf("%d", &f->sessoes);
	fflush(stdin);
	validaValor(&status, &f->sessoes, 0, 0); //Valida o valor do input
	if (f->sessoes != NUM_SESSOES) // 2
	{
		printf("Somente � aceito 2 se��es como input:\n");
		pegaSessoes(f);
		return 0; // Evitar que continue 
	}
	alocaMemoria(f); // aloca a memoria
}

int retornaSessoes(FILME f) // Fun��o de retorno para a quantidade de sessoes
{
	return f.sessoes;
}
// PEGA A QUANTIDADE DE PESSOAS EM CADA SESSAO 
void pegaPessoas(FILME* f)
{
	for (int i = 0; i < f->sessoes; i++) // Adicionando a quantidade de pessoas por sessao e colocando no array.
	{
		printf("Digite a quantidade de pessoas que assistiram a se��o %d: ", i + 1);
		int status = scanf("%d", &f->p.pessoas[i]);
		fflush(stdin);
		validaValor(&status, &f->p.pessoas[i], 1, 0); // Valida o valor do input

		if (f->p.pessoas[i] < NUM_PESSOAS) // 10
		{
			printf("� aceito no m�nimo 10 por sess�o:\n");
			pegaPessoas(f); // Se for menor que o numero m�nimo volta a fun��o
		}
	}
	alocaMemoria_(f); // Alocando memoria de acordo com a quantidade pessoas por sessao
}

// PEGA O VALOR DA IDADE DE TODOS POR SESSAO
void pegaIdades(FILME* f, int sessao, int pessoa)
{
	for (int i = sessao; i < f->sessoes; i++) // Para cada sessao se adiciona as idades no array
	{
		printf("SESS�O %d:\n", i + 1);
		for (int j = pessoa; j < f->p.pessoas[i]; j++)
		{
			printf("Digite a idade da pessoa %d: ", j + 1);
			int status = scanf("%d", &f->p.idades[i][j]);
			validaValor(&status, &f->p.idades[i][j], 2, j);
			fflush(stdin);
			pegaSexo(f, i, j); // Pega o sexo das pessoas
		}
	}
}

// PEGA O VALOR DO SEXO DE TODOS POR SESSAO
void pegaSexo(FILME* f, int i, int j)
{
	printf("Digite o sexo da pessoa %d: ", j + 1);
	scanf("%c", &f->p.s.sexo[i][j]);
	f->p.s.sexo[i][j] = toupper(f->p.s.sexo[i][j]);
	validaSexo(&f->p.s.sexo[i][j], j);
}

// PEGA O NOME DO FILME
void pegaFilmes(FILME* f)
{
	fflush(stdin);
	f->nome = malloc(sizeof(char) * TAM_NOME); // aloca a mem�ria 
	printf("Digite o nome do filme: "); // Pede o nome do filme 
	fgets(f->nome, TAM_NOME, stdin);
	fflush(stdin);
	int len = strlen(f->nome); // conta o tamanho
	validaFilme(f->nome, &len); // Valida o nome
	printf("Nome do filme: %s\n", f->nome);
	pegaSessoes(f); // Pega as sessoes
}

char* retornaFilme(FILME f) // Fun�ao de retorno para o nome
{
	return f.nome;
}
// FIM DE PEGANDO OS DADOS

// ALOCANDO MEM�RIA:
void alocaMemoria(FILME* f)
{
	f->p.idades = malloc(sizeof(int*) * f->sessoes); // Ponteiro de ponteiro contendo todos os valores da idade por sessao
	f->p.s.sexo = malloc(sizeof(int*) * f->sessoes); // Ponteiro de ponteiro contendo todos os valores do sexo por sessao
	f->p.pessoas = malloc(sizeof(int) * f->sessoes); // Ponteiro contendo o valor todal de pessoas por sessao
	f->p.s.masculino = malloc(sizeof(int) * f->sessoes); // Ponteiro contento o valor das pessoas do sexo masculino por sessao
	f->p.s.feminino = malloc(sizeof(int) * f->sessoes); // Ponteiro contendo o valor das pessoas do sexo feninino por sessao

	pegaPessoas(f); // Pega a quantidade de pessoas
}

void alocaMemoria_(FILME* f) // Criando um array com os dados para cada sessao com a quantidade de pessoas 
{
	for (int i = 0; i < f->sessoes; i++) // aloca um vetor com todos os elementos da matriz
	{
		f->p.idades[i] = malloc(sizeof(int) * f->p.pessoas[i]);
		f->p.s.sexo[i] = malloc(sizeof(int*) * f->p.pessoas[i]);
	}
	pegaIdades(f, 0, 0); // Pegando as idades
}
// FIM ALOCANDO MEM�RIA

// LIBERANDO MEM�RIA:
void liberaMemoria(FILME* f)
{
	for (int i; i < f->sessoes; i++)
	{
		free(f->p.idades[i]);
		free(f->p.s.sexo[i]);
	}
	free(f->p.idades);
	free(f->p.s.sexo);
	free(f->nome);
	free(f->p.pessoas);
	free(f->p.s.masculino);
	free(f->p.s.feminino);
}

// CONTA A QUANTIDADE DE PESSOAS DO SEXO MASCULINO E FEMININO PARA O MESMO FILME
int contaSexo(FILME* f, int valor, int questao, int sexo)
{
	for (int i = valor; i <= valor; i++) // Zerando os valores de acordo com a sessao
	{
		f->p.s.masculino[i] = 0;
		f->p.s.feminino[i] = 0;
	}
	switch (questao)
	{
	case 1: // Caso seja a resposta da questao 1
		for (int i = valor; i <= valor; i++) // Para cada sessao sera:
		{
			for (int j = 0; j < f->p.pessoas[i]; j++) // Vai passar por cada elemento 
			{
				if (f->p.s.sexo[i][j] == 'M') f->p.s.masculino[i] += 1; // somar 1 se masculino
				else if (f->p.s.sexo[i][j] == 'F') f->p.s.feminino[i] += 1; // somar1 se feminino
			}
			if (sexo == 0) return  f->p.s.masculino[i]; // Se sexo = 0 vai retornar os valores masculinos
			else if (sexo == 1) return f->p.s.feminino[i]; // Se sexo = 1 vai retornar os valores femininos
		}

	case 2: // caso quest�o 2 : Igual ao anterior mas adicionando o crit�rio de idade
		for (int i = valor; i <= valor; i++)
		{
			for (int j = 0; j < f->p.pessoas[i]; j++)
			{
				if (f->p.idades[i][j] >= 18 && f->p.s.sexo[i][j] == 'M') f->p.s.masculino[i] += 1;
				else if (f->p.idades[i][j] >= 18 && f->p.s.sexo[i][j] == 'F') f->p.s.feminino[i] += 1;
			}
			if (sexo == 0) return  f->p.s.masculino[i];
			else if (sexo == 1) return f->p.s.feminino[i];
		}
		break;
	default:
		break;
	}
}

// CONTA A QUANTIDADE DE PESSOAS DE ACORDO A SUA CLASSIFICACAO: 
void contaIdades(FILME* f, CLASSIFICACAO* c, int sessoes)
{
	for (int i = 0; i < f->sessoes; i++) // Passa por cada sess�o e soma a idade de acordo com a classificacao
	{
		for (int j = 0; j < f->p.pessoas[i]; j++)
		{
			if (f->p.idades[i][j] >= 65) c->idosos += 1;
			else if (f->p.idades[i][j] >= 18) c->adultos += 1;
			else if (f->p.idades[i][j] >= 14) c->adolecentes += 1;
			else if (f->p.idades[i][j] >= 3) c->criancas += 1;
			else printf("Erro na contagem!");
		}
	}
}




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
