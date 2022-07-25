#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iterator>
using std::string;
using std::getline;

typedef struct lista{
    string dado;
    struct lista *proximo;
}lista;

int hash(string dado, int m);
void insercaoHash(lista *v[], string dado, int m);
int colisoes(lista *v[]);
lista *busca(lista *v[], string palavra, int m);

int main() {
    lista *v[1];
    return 0;
}

int hash(string dado, int m){
    int tamanhoStr = dado.size();
    int linha, ascii=0, i;
    for(i = 0; i < tamanhoStr; i++){
        ascii += dado[i];
    }
    linha = ascii % m;
    return linha;
}


void insercaoHash(lista *v[], string dado, int m){
    int linha;
    lista *novo;
    linha = hash(dado, m);
    if (v[linha] == NULL) {
        novo = (lista *) malloc(sizeof(lista));
        novo->dado = dado;
        novo->proximo = NULL;
        v[linha] = novo;
    } else {
        while (v[linha]->proximo != NULL) {
            v[linha] = v[linha]->proximo;
        }
        novo = (lista *) malloc(sizeof(lista));
        novo->dado = dado;
        novo->proximo = NULL;
        v[linha]->proximo = novo;
    }
}

int colisoes(lista *v[]){
    int linha=0, colisoes=0;
    while(v[linha]!=NULL){
        while(v[linha]->proximo!=NULL){
            v[linha]=v[linha]->proximo;
            colisoes++;
        }
        linha++;
    }
    return colisoes;
}

lista *busca(lista *v[], string palavra, int m){
    int linha;
    linha=hash(palavra, m);
    if((v[linha]->dado==palavra)&&(v[linha]!=NULL)){
        return v[linha];
    }
    else if (v[linha]==NULL) return NULL;
    else{
        while((v[linha]->dado!=palavra)&&(v[linha]->proximo!=NULL)){
            v[linha]=v[linha]->proximo;
        }
        if(v[linha]->dado==palavra)
            return v[linha];
        else return NULL;
    }
}
