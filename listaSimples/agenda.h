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

typedef struct Listas
{
    DadoPessoa pessoas[5];
    int inicio;
    int fim;
} Lista;

void iniciaLista(Lista* lista)
{
    lista->inicio = 0;
    lista->fim = 0;
}


void inserirPessoaNaLista(Lista* lista, char* nome, char* tel)
{
   if(lista->fim < MAX)
   {
        lista->pessoas[lista->fim].nome= string(nome);
        lista->pessoas[lista->fim].tel = string(tel);
        lista->fim++;
    }
    else
        cout << "lista cheia\n";

}

int pesquisarIndice(Lista* lista, char* nome)
{
    for(int i = 0; i < lista->fim; i++)
    {
        if(!lista->pessoas[i].nome.compare(string(nome)))
        {
            return i;
        }
    }

    //nome nao foi achado na agenda
    return -1;
}

void alterarPessoaDaLista(Lista* lista, char* nome, char* tel, int indice)
{
    lista->pessoas[indice].nome = string(nome);
    lista->pessoas[indice].tel = string(tel);
}

Lista removerPessoaDaLista(Lista lista, int indice)
{
    Lista aux;
    const char * nome;
    const char * tel;


    iniciaLista(&aux);
    for(int i = 0; i < lista.fim; i++){
        if(i != indice){
            nome = lista.pessoas[i].nome.c_str();
            tel = lista.pessoas[i].tel.c_str();
            inserirPessoaNaLista(&aux, (char*)nome, (char*)tel);
        }
    }

    return aux;
}

void imprimePessoasDaLista(Lista* lista)
{
    int i;
    //system("clear");
    for(i = 0; i < lista->fim; i++){
        cout << "Nome: " + lista->pessoas[i].nome + " Tel: " + lista->pessoas[i].tel + "\n";
    }
}
