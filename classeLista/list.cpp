#include "lista.h"


using namespace std;

List::List()
{
    head = NULL;
    curr = NULL;
    temp = NULL;
    //ctor
}

/*List::~List()
{
    //dtor
}*/


void List::insere(string nome, string tel)
{
    No* novo = new No;
    novo->prox = NULL;
    novo->pessoas.nome = nome;
    novo->pessoas.tel = tel;

    if(head != NULL){
        curr = head;
        while(curr->prox != NULL){
            curr = curr->prox;
        }
        curr->prox = novo;
    }
    else{
        head = novo;
    }
}

void List::imprime(){
    curr = head;
    if(head == NULL){
        cout << "Agenda vazia \n";
        return;
    }

    while(curr != NULL)
    {
        cout << "Nome: "+curr->pessoas.nome+ " Tel: "+ curr->pessoas.tel+"\n";
        curr = curr->prox;
    }
}

void List::deleta(string nome){

    No* noPraDeletar = NULL;

    temp = head;
    curr = head;

    while(curr != NULL )
    {
        if(!curr->pessoas.nome.compare(string(nome)))
        {

            noPraDeletar = curr;
            curr = curr->prox;
            temp->prox = curr;

            if(noPraDeletar == head){
                head = head->prox;
                temp = NULL;
            }

            delete noPraDeletar;

            return;
        }
        temp = curr;
        curr = curr->prox;
    }

    if(curr == NULL){
        cout << "Nao esta na agenda\n";
        //delete noPraDeletar;
    }

}

