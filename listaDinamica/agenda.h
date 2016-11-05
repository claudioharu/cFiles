#include <iostream>
#include<stdlib.h>
#include<stdio.h>

#define MAX 20

using namespace std;

typedef int Apontador;

typedef struct DadosDasPessoas
{
    string nome;
    string tel;
} DadoPessoa;

typedef struct Nodo
{
    DadoPessoa pessoas;
    Nodo* prox;
} No;

int vazia(No lista);
void iniciaLista(No* lista);
void imprimeLista(No lista);
void insere(No *lista, char* nome, char* tel);
void altera(No* lista,  char* nomeAMudar, char* nome, char* tel);
void retira(No* lista, char* nome);
No* aloca(char* nome, char* tel);


void iniciaLista(No* lista)
{
    lista->prox = NULL;
}

void imprimeLista(No lista)
{
    if(lista.prox == NULL)
    {
        cout << "Agenda vazia \n";
        return;
    }

    No* aux = lista.prox;
    while(aux->prox != NULL)
    {
        cout << "Nome: "+aux->pessoas.nome+ " Tel: "+ aux->pessoas.tel+"\n";
        aux = aux->prox;
    }
    cout << "Nome: "+aux->pessoas.nome+ " Tel: "+ aux->pessoas.tel+"\n";
}

No* aloca(char* nome, char* tel)
{
	No* novo = new No;

    novo->prox = NULL;

	if(!novo)
	{
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else
	{
		//printf("Criando nó");

        novo->pessoas.nome = string(nome);
        novo->pessoas.tel = string(tel);

		//getchar();
		//getchar();


		return novo;
	}
}

void insere(No *lista, char* nome, char* tel)
{
	No *novo = aloca(nome, tel);

	if(vazia(*lista))
		lista->prox = novo;
	else{
		No* aux = lista->prox;

		while(aux->prox != NULL)
			aux = aux->prox;

		aux->prox = novo;
		lista = aux;
	}

}

void altera(No* lista, char* nomeAMudar, char* nome, char* tel)
{
    if(vazia(*lista)!= 1)
    {

        No* aux = lista;

        while(aux->prox != NULL)
        {
            if(!aux->pessoas.nome.compare(string( nomeAMudar)))
            {
                cout << aux->pessoas.nome + "\n";
                aux->pessoas.nome = string(nome);
                aux->pessoas.tel = string(tel);
                break;
            }
            cout << aux->pessoas.nome + "\n";
            aux = aux->prox;
        }

        if(!aux->pessoas.nome.compare(string(nomeAMudar)))
        {
            aux->pessoas.nome = string(nome);
            aux->pessoas.tel = string(tel);
        }



    }
    else{
        printf("Agenda vazia\n\n");
        getchar();
        getchar();
    }

}

void retira(No* lista, char* nome)
{

    if(vazia(*lista)!= 1)
    {

        if(lista->prox == NULL)
            cout << "lista vaziaaaaa \n\n";
        else{
            No* aux = lista;
            No* auxProx = lista->prox;

            while(auxProx->prox != NULL)
            {
                if(!auxProx->pessoas.nome.compare(string(nome)))
                {
                    aux->prox = auxProx->prox;
                    auxProx->prox = NULL;
                    free(auxProx);
                    break;
                }
                aux = auxProx;
                auxProx = auxProx->prox;
            }

            if(!auxProx->pessoas.nome.compare(string(nome)))
            {
                aux->prox = auxProx->prox;
                auxProx->prox = NULL;
                free(auxProx);
            }
        }


    }
    else{
        printf("Agenda vazia\n\n");
        getchar();
        getchar();
    }


}

int pesquisarNome(No* lista, char* nome)
{
    No* aux = lista;

    while (aux->prox != NULL)
    {
        if(!aux->pessoas.nome.compare(string(nome)))
        {
            return 1;
        }
        cout << aux->pessoas.nome + "\n";
        aux = aux->prox;
    }
    if(!aux->pessoas.nome.compare(string(nome)))
    {
        return 1;
    }    //nao tah na agenda
    return -1;
}

int vazia(No lista)
{
    if (lista.prox == NULL)
        return 1;
    else
        return 0;
}
