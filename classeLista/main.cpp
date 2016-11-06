#include <iostream>
#include "lista.h"

using namespace std;

int main()
{

    List lista;

    lista.insere("claudio", "324234");
    lista.insere("claudia", "324234");
    lista.insere("claudif", "324234");

    lista.imprime();

    getchar();

    lista.deleta("claudia");
    lista.imprime();

    getchar();

    lista.deleta("claudif");
    lista.imprime();

    getchar();


    lista.deleta("claudio");
    lista.imprime();

    getchar();

    lista.deleta("galo");
    lista.imprime();

    getchar();




 //   cout << "Hello world!" << endl;
    return 0;
}
