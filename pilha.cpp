#include <stdio.h>
#include <iostream>
#include<stdlib.h>


using namespace std;

typedef struct tipoElemento
{
	string valor;
}TElemento;

typedef struct tipoPilha
{
	TElemento pilhaElementos[100];
	int topo;//indice do ultimo elemento inserido
}TPilha;


void inicializaPilha(TPilha* pilha){
	pilha->topo = -1;
}

void empilha(TPilha* pilha, string valor){
	if(pilha->topo < 99){
		pilha->topo ++;
		pilha->pilhaElementos[pilha->topo].valor = valor;
	}
	else{
		cout << "pilha cheia\n";
	}
}

string desempilha(TPilha* pilha){
	if(pilha->topo > -1){
		string value = pilha->pilhaElementos[pilha->topo].valor;
		pilha->topo--;
		return value;
	}
	else{
		cout << "pilha vazia\n";
		return "";
	}
}


int main()
{
	TPilha pilha;
	inicializaPilha(&pilha);

	string emp = "2";

	empilha(&pilha, emp);

	emp = "+";
	empilha(&pilha, emp);
	emp = "galo";
	empilha(&pilha, emp);

	string value = desempilha(&pilha);
	cout << "desempilhou: "+ value + "\n";
	
	value = desempilha(&pilha);
        cout << "desempilhou: "+ value + "\n";

	value = desempilha(&pilha);
        cout << "desempilhou: "+ value + "\n";

	value = desempilha(&pilha);
        cout << "desempilhou: "+ value + "\n";



	return 0;
}
