#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iterator>
using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;
using namespace std;

typedef struct lista{
    string dado;
    struct lista *proximo;
}lista;

int hashCode(string str, int M);
void insercaoHash(lista *v[], string dado, int m);
int colisoes(lista *v[]);
int lerArquivo(lista *v[], int m);
void inicializaVetor(lista *v[], int m);
vector<string> lerArquivo2(string db);

int main() {
    lista *v[31], *v2[79], *v3[151];
    inicializaVetor(v, 31);
    inicializaVetor(v2, 79);
    inicializaVetor(v3, 151);
    lerArquivo(v, 2);
    colisoes(v);
}

void inicializaVetor(lista *v[], int m){
    for(int i = 0; i < m; i++){
        v[i] = nullptr;
    }
}

int hashCode(string str, int M){
    int tamanhoStr;
    tamanhoStr= str.length();
    int ascii = 0, codigo;
    int i;
    for(i = 0; i < tamanhoStr; i++){
        ascii += str[i];
    }
    codigo = ascii % M;
    return codigo;
}


void insercaoHash(lista *v[], string dado, int m){
    int linha;
    lista *novo;
    linha = hashCode(dado, m);
    if (v[linha] == nullptr) {
        novo = (lista *) malloc(sizeof(lista));
        novo->proximo = nullptr;
        v[linha] = novo;
    } else {
        while ((v[linha])->proximo != nullptr) {
            (v[linha]) = (v[linha])->proximo;
        }
        novo = (lista *) malloc(sizeof(lista));
        novo->proximo = nullptr;
        (v[linha])->proximo = novo;
    }
}

int colisoes(lista *v[]){
    int linha=0, colisoes=0;
    while(v[linha]!=nullptr){
        while(v[linha]->proximo!=nullptr){
            v[linha]=v[linha]->proximo;
            colisoes++;
            printf("linha %d: colisao: %d\n", linha, colisoes);
        }
        linha++;
    }
    printf("Numero de colisoes total %d\n", colisoes);
    return colisoes;
}

int lerArquivo(lista *v[], int m){
    string filename("1000 palavras.txt");
    vector<string> lines;
    string line;
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
        insercaoHash(v,line, m);
    }

    for (const auto &i : lines)
        cout << i << endl;

    input_file.close();
    return EXIT_SUCCESS;
}
