#ifndef _PROJETO_H_ // Checa se o valor � �nico e se n�o estiver definido o define e continua o resto da p�gina
#define _PROJETO_H_ 

//CONSTANTE COM O VALOR DO TAMANHO DO NOME: 

struct classificacao // Salva a quantidade de pessoas por classifica��o
{
	int criancas; 
	int adolecentes;
	int adultos;
	int idosos;
} CLASSIFICACAO_default = { 0 }; // Define as vari�veis criadas com o valor zero 
typedef struct classificacao CLASSIFICACAO;

void dadosautor();
void contaidades(CLASSIFICACAO* c, int sessoes);
void contasexo( int valor, int questao);
void limpatela();
void imprimemenu();
void imprimedadosfilme();
void imprimesessoes(CLASSIFICACAO* c);
void testaquestao( CLASSIFICACAO* c);
void direcionaresposta(CLASSIFICACAO* c, int resp1, char* resp2);
void letexto();
int contamaioresidade(int valor);

void Espera();

#endif