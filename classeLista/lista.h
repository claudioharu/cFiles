#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class List{

private:

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

No* head;
No* curr;
No* temp;

public:

List();

void deleta(string nome);
void insere(string nome, string tel);
void imprime();


};

#endif // LISTA_H_INCLUDED
