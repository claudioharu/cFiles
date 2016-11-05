#include<iostream>

using namespace std;

int main(){

    string nome;
    string tel;

    cout << "insira um nome: ";
    //Conseguir do terminal uma linha (string com espaços)
    getline (cin, nome);

    cout << "insira um telefone: ";
    //Conseguir do terminal uma linha (string com espaços)
    getline(cin, tel);

    cout << "nome inserido: " << nome + "\nnumero inserido: " <<tel << "\n";    
    
    return 0;
}
