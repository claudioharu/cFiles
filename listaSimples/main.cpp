#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include <limits>       // std::numeric_limits
#include "agenda.h"


//https://www.youtube.com/watch?v=IxJgs1XG9sk

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
    char auxNome[20];
    char auxTel[20];

	Lista lista;

	iniciaLista(&lista);

    int indice = 0;
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

                inserirPessoaNaLista(&lista, auxNome, auxTel);

                indice ++;

                break;
            }

            case 2:
            {
                system("clear");

                printf("Digite um nome a ser removido: \n");
                scanf("%19s",auxNome);

                int index = pesquisarIndice(&lista, auxNome);
                printf("Indice: %d\n\n\n", index);
                if(index > -1){
                    lista = removerPessoaDaLista(lista, index);
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

                printf("Digite um nome: \n");
                scanf("%19s",auxNome);

                int index = pesquisarIndice(&lista, auxNome);
                if(index > -1){

                    auxNome[0] = '\0';

                    printf("Insira os novos dados: \n\n");

                    printf( "Digite um nome: \n");
                    scanf("%19s",auxNome);

                    printf("Insira o telefone: \n");

                    scanf("%19s", auxTel);

                    alterarPessoaDaLista(&lista, auxNome, auxTel, index);
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
                system("clear");
                imprimePessoasDaLista(&lista);

                getchar();
                getchar();


                break;
            }


        }
        opcao = menu();
    }

	return 0;
}

