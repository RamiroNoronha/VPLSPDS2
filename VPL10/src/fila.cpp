#include <string>
#include "fila.h"
#include <iostream>
using namespace std;

Fila::Fila(){
    primeiro_ = nullptr;
    ultimo_ = nullptr;

}

std::string Fila::primeiro(){
    if(!vazia())
        return primeiro_->chave;
}

std::string Fila::ultimo(){
    if(!vazia()){
        if(tamanho() == 1){
            return primeiro_->chave;
        }
        return ultimo_->chave;
    }
    
}

bool Fila::vazia(){
    return primeiro_ == nullptr;
}

void Fila::Inserir(std::string k){
    if(vazia()){
        
        primeiro_ = new No[1];
        primeiro_->chave = k;
        primeiro_->proximo = nullptr;
        
    } else if(ultimo_ == nullptr){
        ultimo_ = new No[1];
        ultimo_->chave = k;
        ultimo_->proximo = primeiro_;
        primeiro_->proximo = ultimo_;
    } else {
        for(No* operador = primeiro_; operador != ultimo_; operador = operador->proximo){
            if(operador->proximo == ultimo_){
                No* aux = new No[1];
                aux->chave = ultimo_->chave;
                aux->proximo = ultimo_;
                operador->proximo = aux;
                ultimo_->chave = k;
                break;
            }
    }
    }
    
}

void Fila::Remover(){
    if(!vazia()){
        if(tamanho() == 1){
            delete[] primeiro_;
            primeiro_ = nullptr;
        } else if (tamanho() == 2){
            primeiro_->chave = ultimo_->chave;
            delete[] ultimo_;
            primeiro_->proximo = nullptr;
            ultimo_ = nullptr;
        } else {
            for(No* operador = primeiro_; operador != ultimo_ ; operador = operador->proximo){
            operador->chave = operador->proximo->chave;
            if(operador->proximo->proximo == ultimo_){
                No* aux = operador->proximo;
                operador->proximo = ultimo_;
                delete [] aux;
                break;
            }
            
        }
        }   
        

        
    }
}

int Fila::tamanho(){
    int i = 0;
    if(primeiro_ == nullptr){
        return 0;
    } else if(ultimo_ == nullptr){
        return 1;
    }
    i = 1;
    for(No* operador = primeiro_; operador != ultimo_; operador = operador->proximo){
        i++;
    }

    return i;
}

Fila::~Fila(){
    delete primeiro_;
    delete ultimo_;
}

