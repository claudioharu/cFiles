#include <iostream>
#include <fstream>

using namespace std;

void lendoArquivo(ifstream* file)
{
    //Checa fim de arquivo
    while(file->good())
    {
        string line;
        getline(*file, line);
        cout << line << endl;
    }
}

void escrevendoArquivo(ofstream* file)
{
     //Inserindo linhas no arquivo agenda
    *file << "laila 98989989" << endl;
}


int main()
{

    ofstream writingfile;
    ifstream readingfile;
    //Abertura do arquivo
    //std::ios::app significa que o arquivo nao vai ser apagado quando recriar,
    //vai ser inserido no final dele
	writingfile.open("agenda.txt", ios::app);

	escrevendoArquivo(&writingfile);

	//Fechando arquivo
	writingfile.close();

	//Abertura do arquivo para leitura
	readingfile.open("agenda.txt");

	lendoArquivo(&readingfile);

    readingfile.close();

    return 0;
}
