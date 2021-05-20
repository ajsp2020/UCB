#include<stdio.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<stdlib.h>


int main()
{
	setlocale(LC_ALL, "Portuguese");
	char destinosNacionais[27][40] = { "Rio Branco", "Maceio", "Macapa", "Manaus", "Salvador", "Fortaleza", "Brasilia", "Vitoria", "Goiania", "Sao Luis",
									"Cuiaba", "Campo Grande", "Belo Horizonte", "Belem", "Joao Pessoa", "Curitiba", "Recife", "Teresina", "Rio de Janeiro",
									"Natal", "Porto Alegre", "Porto Velho", "Boa Vista", "Florianopolis", "Sao Paulo", "Aracaju", "Palmas" };
	char destino[40], resposta;
	int destinosNacionaisPosicao[27], assentosExistentes[27];

	for (int i = 0; i < 27; i++) destinosNacionaisPosicao[i] = i;
	for (int i = 0; i < 27; i++) assentosExistentes[i] = 0; // Assentos existentes por voo.

	// Desocupando todos os assentos dos voos:
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


	do {

		int temDestino = 0, posicao;
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

					printf("QUANTIDADE DE ASSENTOS EXISTENTES: ");
					status = scanf("%d", &assentosExistentes[i]);

					respostaValida = assentosExistentes[i] >= 90 && assentosExistentes[i] <= 200 && status == 1;

				} while (!respostaValida);
				posicao = i;
				temDestino = 1;
				break;
			}
		}

		if (temDestino == 1)
		{
			system("cls");

			printf("DESTINO: %s\n", destinosNacionais[posicao]);

			switch (posicao)
			{
			case 0:
				
				printf("QUANTIDADE DE ASSENTOS DISPON�VEIS: %d\n", assentosExistentes[posicao]);
				printf("POLTRONAS DISPON�VEIS: \n\n");

				printf("   abc  def");

				int corredor = 1;
				for (int i = 0; i < assentosExistentes[posicao]; i++)
				{
					
					if (i % 3 == 0) printf("\t");
					if (i % 6 == 0) printf("\n");
					if (i % 6 == 0 || i == 0)
					{
						if(corredor < 10) printf(" %d ", corredor);
						else printf("%d ", fileira);
			
						corredor++;
					}
					if(rioBranco[i] == 0) printf("D");
				}
				// -->  Arrumar para conseguir com a fileira e seu numero conseguir marcar como reservado. 

				printf("QUAL ASSENTO DESEJA RESERVAR? "); 
				printf("FILEIRA: ");
				int fileira;
				scanf("%c", fileira);
				printf("%d", fileira);

				break;

			default:
				break;
			}
		}
		else
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

		} while (!respostaValida);
	
	} while (resposta == 'S');
	
}