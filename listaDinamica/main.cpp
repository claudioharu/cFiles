#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <limits>       // std::numeric_limits
#include "agenda.h"

using namespace std;

int menu()
{

	int opcao;
	do{
        system("clear");
		cout << "Escolha uma opcao: \n\n";
		cout << "1- Cadastrar\n";
		cout << "2- Excluir\n";
        cout << "3- Alterar por nome\n";
		cout << "4- Imprimir\n";
		cout << "0- Terminar\n";
		cout << "\nOpcao: ";
		cin >> opcao;
	}while(opcao < 0 || opcao > 4 );

	return opcao;

}

int main()
{

	int opcao = menu();
    char auxNomeAMudar[20];
    char auxNome[20];
    char auxTel[20];

	No lista;

	iniciaLista(&lista);

    while(opcao != 0)
    {
        switch(opcao){
            case 1:
            {
                system("clear");

                printf( "Digite um nome: \n");
                scanf("%19s",auxNome);

                printf("Insira o telefone: \n");

                scanf("%19s", auxTel);

                insere(&lista, auxNome, auxTel);

                break;
            }

            case 2:
            {
                system("clear");

                printf("Digite um nome a ser removido: \n");
                scanf("%19s",auxNome);
                int aux = pesquisarNome(&lista, auxNome);
                if(aux != -1){
                   retira(&lista, auxNome);
                }
                else
                {
                    printf("O nome inserido nao esta presente na agenda\n\n");
                     //system pause
                    getchar();
                    getchar();
                }

                break;
            }

            case 3:
            {
                system("clear");

                printf("Digite o nome a ser alterado: \n");
                scanf("%19s",auxNomeAMudar);

                int aux = pesquisarNome(&lista, auxNomeAMudar);
                if(aux != -1){
                    auxNome[0] = '\0';

                    printf("Insira os novos dados: \n\n");

                    printf( "Digite um nome: \n");
                    scanf("%19s",auxNome);

                    printf("Insira o telefone: \n");

                    scanf("%19s", auxTel);

                    altera(&lista, auxNomeAMudar, auxNome, auxTel);

                }
                else
                {
                    printf("O nome inserido nao esta presente na agenda\n\n");
                     //system pause
                    getchar();
                    getchar();
                }



                break;
            }

            case 4:
            {

                imprimeLista(lista);
                getchar();
                getchar();
                break;
            }


        }
        opcao = menu();
    }

	return 0;
}
