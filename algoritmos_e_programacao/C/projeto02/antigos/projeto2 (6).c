#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define TAM_RESERVA 100

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char destinosNacionais[27][40] = { "Rio Branco", "Maceio", "Macapa", "Manaus", "Salvador", "Fortaleza", "Brasilia", "Vitoria", "Goiania", "Sao Luis",
									"Cuiaba", "Campo Grande", "Belo Horizonte", "Belem", "Joao Pessoa", "Curitiba", "Recife", "Teresina", "Rio de Janeiro",
									"Natal", "Porto Alegre", "Porto Velho", "Boa Vista", "Florianopolis", "Sao Paulo", "Aracaju", "Palmas" };
	char destino[40], resposta;

	int destinosNacionaisPosicao[27];
	for (int i = 0; i < 27; i++) destinosNacionaisPosicao[i] = i;

	int assentosExistentes[27];
	for (int i = 0; i < 27; i++) assentosExistentes[i] = 0; // Assentos existentes por voo.

	int lista = 0; // Variavel que controla o ponteiro da lista de reservas
	/* INICIO: CRIANDO UM ARRAY COM TODAS AS RESERVAS POSS�VEIS */

	// reserva = {numero da reserva/ voo/ poltronas}
	int reservas[100];
	for (int i = 0; i < 100; i++) reservas[i] = 0;

	/* FIM: CRIANDO UM ARRAY COM TODAS AS RESERVAS POSS�VEIS */

	/* INICIO: CRIANDO UM ARRAY COM TODOS OS VOOS E VAGANDO TODOS OS LUGARES */

	// 0 -> Lugares dispon�veis;
	// 1 -> Lugares com reserva;
	// 2 -> Lugares Comfirmados;

	char rioBranco[200], maceio[200], macapa[200], manaus[200], salvador[200], fortaleza[200], brasilia[200];
	for (int i = 0; i < 200; i++)
	{
		rioBranco[i] = 0;
		maceio[i] = 0;
		macapa[i] = 0;
		manaus[i] = 0;
		salvador[i] = 0;
		fortaleza[i] = 0;
		brasilia[i] = 0;
	}
	/* FIM: CRIANDO UM ARRAY COM TODOS OS VOOS E VAGANDO TODOS OS LUGARES */

	/* INICIO: CRIA A QUANTIDADE DE ASSENTOS CADA VOO VAI TER: */

	char respostaSaida1;

	do {// INCIO DO WHILE MENU:

		/* INICIO: CRIANDO UM MENU: */
		int respostaMenu;
		printf("*****************************************************************************************************************************\n");
		printf("*                                                                                                                           *\n");
		printf("*                                                 SALUMAR LINHAS AEREAS                                                     *\n");
		printf("*                                                                                                                           *\n");
		printf("*****************************************************************************************************************************\n");
		printf("*                                                          MENU                                                             *\n");
		printf("*                                                                                                                           *\n");
		printf("*****************************************************************************************************************************\n");
		printf("*                                                                                                                           *\n");
		printf("*     - DIGITE:                                                                                                             *\n");
		printf("*                                                                                                                           *\n");
		printf("*     1 - ADICIONAR UM DESTINO:                                                                                             *\n");
		printf("*     2 - ADICIONAR QUANTIDADE DE ASSENTOS PARA O DESTINO:                                                                  *\n");
		printf("*     3 - FAZER UMA RESERVA:                                                                                                *\n");
		printf("*     4 - CONFIRMAR UMA RESERVA:                                                                                            *\n");
		printf("*     5 - CANCELAR UMA RESERVA:                                                                                             *\n");
		printf("*     6 - DADOS DO VOO:                                                                                                     *\n");
		printf("*     7 - SAIR:                                                                                                             *\n");
		printf("*                                                                                                                           *\n");
		printf("*****************************************************************************************************************************\n");
		scanf(" %d", &respostaMenu);
		/* FIM: CRIANDO UM MENU. */

		switch (respostaMenu)
		{
		case 1:

			break;

		case 2: // ADICIONAR QUANTIDADE DE ASSENTOS PARA O DESTINO:
			do {
				fflush(stdin);
				printf("DESTINO: ");
				fgets(destino, 40, stdin);

				for (int i = 0; i < 27; i++)
				{
					int status = 0;
					int respostaValida;

					if (strncmp(destinosNacionais[i], destino, 5) == 0)
					{
						printf("Destino encontrado\n");
						do {
							fflush(stdin);

							printf("QUANTIDADE DE ASSENTOS EXISTENTES PARA: %s ", destinosNacionais[i]);
							status = scanf("%d", &assentosExistentes[i]);

							respostaValida = assentosExistentes[i] >= 90 && assentosExistentes[i] <= 200 && status == 1;

						} while (!respostaValida);
					}
				}

				printf("DESEJA ADICIONAR MAIS VOOS? (S/N): ");
				scanf(" %c", &respostaSaida1);

			} while (respostaSaida1 == 'S' || respostaSaida1 == 's');

			break;

			/* FIM: CRIA A QUANTIDADE DE ASSENTOS CADA VOO VAI TER. */

		case 3:; // INICIO FAZER UMA RESERVA   
			
				int temDestino = 0, voo, numeroVoo;
				int numeroAssento;
				fflush(stdin);
				printf("DIGITE O DESTINO:");
				fgets(destino, 40, stdin);

				for (int i = 0; i < 27; i++)
				{

					if (strncmp(destinosNacionais[i], destino, 5) == 0)
					{
						voo = i;
						temDestino = 1;
					}
				}

				if (temDestino == 1)
				{

					system("cls");

					printf("DESTINO: %s\n", destinosNacionais[voo]);

					fflush(stdin);
					char respostaReserva;
					printf("DESEJA FAZER UMA RESERVA? ");
					scanf(" %c", &respostaReserva);



					if (respostaReserva == 'S') // INICIO DA RESERVA
					{
						/* INICIO: GERANDO UM C�DIGO DE RESERVA UNICO */

						int  temIgual, temNaLista;

						printf("LISTA %d\n", lista);

						srand((unsigned)time(NULL));
						int reserva = 1 + (rand() % 1000);
						do {

							for (temNaLista = 0; temNaLista < TAM_RESERVA; temNaLista += 8) temIgual = reservas[temNaLista] == reserva;
							if (temIgual) reserva = 1 + (rand() % 1000);
							else
							{
								reservas[lista] = reserva; // O primeiro vai receber a reserva
								numeroVoo = lista + 1;
								reservas[numeroVoo] = voo; // O segundo recebe o voo
								numeroAssento = numeroVoo + 1;
							}

						} while (temIgual == reserva);

						lista += 8;


						printf("NUMERO DA RESERVA: %d\n", reserva);

						/* FIM: GERANDO UM C�DIGO DE RESERVA UNICO */

						switch (voo) // DIRECIONA DE ACORDO COM O VOO
						{
						case 0:

							printf("DESTINO: %s\n", destinosNacionais[voo]);
							printf("QUANTIDADE DE ASSENTOS DISPON�VEIS: %d\n", assentosExistentes[voo]); // colocar o assento disponivel menos oq ja foi escolhido
							printf("POLTRONAS DISPON�VEIS: \n\n");

							/* INICIO: IMPRIMINDO O ESQUEMA DO AVI�O COM A OCUPA��O DAS POLTRONAS */

							int sairReserva;

							do { // do while do voo 0:

								int corredor = 1;
								printf("D - DISPON�VEL\n"
									"R - RESERVADO\n"
									"C - CONFIRMADO\n");

								printf("\n   a b c        d e f");
								for (int i = 0; i < assentosExistentes[voo]; i++)
								{

									if (i % 3 == 0) printf("\t");
									if (i % 6 == 0) printf("\n");
									if (i % 6 == 0 || i == 0)
									{
										if (corredor < 10) printf(" %d ", corredor);
										else printf("%d ", corredor);

										corredor++;
									}
									if (rioBranco[i] == 0) printf("D ");
									else if (rioBranco[i] == 1) printf("R ");
									else if (rioBranco[i] == 2) printf("C ");
								}
								/* FIM: IMPRIMINDO O ESQUEMA DO AVI�O COM A OCUPA��O DAS POLTRONAS */

								// -->  Criar uma forma de sair da area de reserva, dar o pre�o e perguntar de deseja confirmar a passagem

								/*INICIO: PERGUNTANDO E RESERVANDO O LOCAL DE ACORDOR COM A FILEIRA E SEU N�MERO */

								char fileira;
								int letraFileira;
								int numeroFileira;
								int posicao;


								fflush(stdin);
								printf("\nQUAL ASSENTO DESEJA RESERVAR? ");
								scanf("%c %d", &fileira, &numeroFileira);

								printf("%c", fileira);
								printf("%d\n", numeroFileira);

								/* FIM: PERGUNTANDO E RESERVANDO O LOCAL DE ACORDOR COM A FILEIRA E SEU N�MERO */

								/* INICIO: RESERVAR O LOCAL */

								if (fileira == 'a') letraFileira = 0;
								if (fileira == 'b') letraFileira = 1;
								if (fileira == 'c') letraFileira = 2;
								if (fileira == 'd') letraFileira = 3;
								if (fileira == 'e') letraFileira = 4;
								if (fileira == 'f') letraFileira = 5;

								posicao = letraFileira + (numeroFileira - 1) * 6;


								/* INICIO: VERIFICAR SE O ASSENTO FOI OU N�O J� RESERVADO */

								if (rioBranco[posicao] != 0)
								{
									printf("\nO ASSENTO N�O PODE SER RESERVADO:\n");
									system("pause");
								}
								else
								{
									if (numeroAssento > numeroVoo && numeroAssento < numeroVoo + 7)
									{
										rioBranco[posicao] = 1;
										reservas[numeroAssento] = posicao;
										numeroAssento++;
									}
									else
									{
										printf("N�O � PERMITIDO RESERVAR MAIS POLTRONAS:\n");
									}

								}
								for (int i = 0; i < 16; i++) // testando
								{
									printf("reservas[%d] = %d\n", i, reservas[i]);
								}

								/* FIM: VERIFICAR SE O ASSENTO FOI OU N�O J� RESERVADO */

								/* FIM: RESERVAR O LOCAL */

								int valoresValidos;
								do { // DO WHILE DA SAIDA DA RESERVA

									printf("DESEJA RESERVAR MAIS UM ASSENTO? \n");
									printf(" 1 - SIM: \n");
									printf(" 2 - N�O: \n");
									scanf("%d", &sairReserva);

									valoresValidos = sairReserva == 1 || sairReserva == 2;

								} while (!valoresValidos); // FIM DO DO WHILE DA SAIDA DA RESERVA
				
							} while (sairReserva == 1);

							continue;

						case 1:

							break;

						default:
							break;

						} // FINAL DO SWITH CASE:

					} // FINAL DA RESERVA
					
				}

			break;

		case 4:; // CONFIRMAR UMA RESERVA: 
			
			int codigoReserva;
			printf("DIGITE O C�DIGO DA RESERVA:");
			scanf("%d", &codigoReserva);

			/* INICIO: PEGANDO O VALOR DO ASSENTO */

	
			char letra[6];
			int numero[6];

			for (int i = 0; i < TAM_RESERVA; i += 8)
			{
				if (reservas[i] == codigoReserva)
				{
					printf("C�DIGO DE RESERVA: %d\n", reservas[i]);
					printf("DESTINO: %s\n", destinosNacionais[reservas[i + 1]]);

					for (int poltrona = i + 2; poltrona < i + 8; poltrona++)
					{
						if (reservas[poltrona] != 0) 
						{
							for (int fileiraNumero = 0; fileiraNumero < 33; fileiraNumero++)
							{
								for (int fileiraLetra = 0; fileiraLetra < 6; fileiraLetra++)
								{
									if (reservas[poltrona] == fileiraLetra + fileiraNumero * 6)
									{
										switch (fileiraLetra)
										{
										case 0:
											printf("POLTRONA = a %d \n", fileiraNumero + 1);
											break;

										case 1:
											printf("POLTRONA = b %d \n", fileiraNumero + 1);
											break;

										case 2:
											printf("POLTRONA = c %d \n", fileiraNumero + 1);
											break;

										case 3:
											printf("POLTRONA = d %d \n", fileiraNumero + 1);
											break;

										case 4:
											printf("POLTRONA = e %d \n", fileiraNumero + 1);
											break;

										case 5:
											printf("POLTRONA = f %d \n", fileiraNumero + 1);
											break;

										default:
											break;
										}
										
									}
								}
							}
						}		
					}

					// continuar
				}
			}
			

			/* INICIO: PEGANDO O VALOR DO ASSENTO */

			//for (int i = 0; i < TAM_RESERVA; i += 8)
			//{
			//	if (reservas[i] == codigoReserva)
			//	{
			//		printf("RESERVA N�MERO: %d\n", reservas[i]);
			//		printf("DESTINO: %s\n", destinosNacionais[reservas[i + 1]]);
			//		for (int i = 0; i < 6; i++) printf("ASSENTOS: %c%d", letra[i], numero[i]);
			//	}
			//}





			break;

		case 5:

			break;

		default:

			break;


				/*else
				{
					fflush(stdin);
					printf("\nDestino n�o encontrado! \n");
				}

				int respostaValida;

				do {
					fflush(stdin);
					printf("\nDeseja Procurar outro destino? (S/N): \n");
					scanf(" %c", &resposta);

					resposta = toupper(resposta);

					if (resposta == 'S')
					{
						main();
						break;
					}
					else if (resposta == 'N')
					{
						exit(0);
					}

					respostaValida = resposta == 'S' || resposta == 'N';

				} while (!respostaValida);*/

			

		}  // FIM DO WHILE MENU:

	} while (1);  // FINAL SWITH CASA MENU:
}