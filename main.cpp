#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iterator>
#include <time.h>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>


using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;
using namespace std;

typedef struct lista{
    string dado;
    struct lista *proximo;
}lista;
void inicializaVetor(lista *v[], int m);
int hashCode(string str, int M);
int lerArquivo(lista *v[], int m);
void insercaoHash(lista **v[], string dado, int m);
void colisoes(lista *v[], int m);

int main() {
    clock_t start, end;
    start = clock();
    lista *v[31], *v2[79], *v3[151];
    inicializaVetor(v, 31);
    inicializaVetor(v2, 79);
    inicializaVetor(v3, 151);
    lerArquivo(v, 31);
    colisoes(v,31);
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "\nTime taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
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


void insercaoHash(lista **v[], string dado, int m){
    int linha;
    lista *novo, **aux;
    linha = hashCode(dado, m);
    if ((*v)[linha] == nullptr) {
        novo = (lista *) malloc(sizeof(lista));
        novo->proximo = nullptr;
        (*v)[linha] = novo;
    } else {
        aux=&(*v)[linha];
        while((*aux)->proximo!=nullptr){
            aux=&(*aux)->proximo;
        }
        novo = (lista *) malloc(sizeof(lista));
        novo->proximo = nullptr;
        (*aux)->proximo = novo;
    }
}

void colisoes(lista *v[], int m) {
    int linha = 0, i, colisoestotal=0;
    for (i = 0; i < m; i++) {
        while (v[linha] != nullptr) {
            while (v[linha]->proximo != nullptr) {
                v[linha] = v[linha]->proximo;
                colisoestotal++;
            }
            linha++;
        }
    }
    printf("colisoes total: %d", colisoestotal);

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
        insercaoHash(&v,line, m);
    }

    for (const auto &i : lines)
        cout << i << endl;

    input_file.close();
    return EXIT_SUCCESS;
}
