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
    char *dado;
    struct lista *proximo;
}lista;

int hashCode(string str, int M);
void insercaoHash(lista *v[], string dado, int m);
int colisoes(lista *v[]);
lista *busca(lista *v[], string palavra, int m);
int lerArquivo(lista *v[], int m);
void inicializaVetor(lista *v[], int m);
void mostrar(lista *v[]);

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
    lista *novo=nullptr;
    linha = hashCode(dado, m);
    if (v[linha] == nullptr) {
        novo = (lista *) malloc(sizeof(lista));
        novo->proximo = nullptr;
        v[linha] = novo;
    } else {
        while (v[linha]->proximo != nullptr) {
            v[linha] = v[linha]->proximo;
        }
        novo = (lista *) malloc(sizeof(lista));
        novo->proximo = nullptr;
        v[linha]->proximo = novo;
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

lista *busca(lista *v[], string palavra, int m){
    int linha;
    linha=hashCode(palavra, m);
    if((v[linha]->dado==palavra)&&(v[linha]!=nullptr)){
        return v[linha];
    }
    else if (v[linha]==nullptr) return nullptr;
    else{
        while((v[linha]->dado!=palavra)&&(v[linha]->proximo!=nullptr)){
            v[linha]=v[linha]->proximo;
        }
        if(v[linha]->dado==palavra)
            return v[linha];
        else return nullptr;
    }
}


int lerArquivo(lista *v[], int m){
    string filename("100 palavras.txt");
    vector<string> lines;
    string line;
    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line)){
       // lines.push_back(line);
        insercaoHash(v,line, m);
    }

    for (const auto &i : lines)
        cout << i << endl;

    input_file.close();
    return EXIT_SUCCESS;
}
