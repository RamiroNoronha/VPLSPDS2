#include "dicionario.h"
#include<iostream>

Dicionario::Dicionario(){

}

int Dicionario::tamanho(){
    return elementos_.size();
}


bool Dicionario::pertence(std::string chave){
    for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
        if(itr->chave == chave){
            return true;
        }
    }
    return false;
}

std::string Dicionario::menor(){
    if(tamanho() > 0){
        string menor = elementos_.front().chave;
        for(auto elemento : elementos_){
            if(menor > elemento.chave){
                menor = elemento.chave;
            }
        }

        return menor;
    }
    
    DicionarioVazio erro;
    throw erro;
}

std::string Dicionario::valor(std::string chave){
    if(pertence(chave)){
        for(auto elemento : elementos_){
            if(elemento.chave == chave){
                return elemento.valor;
            }
        }
    }
    ChaveInexistente erro;
    erro.chave = chave;
    throw erro;
}

void Dicionario::Inserir(std::string chave, std::string valor){
    if(!pertence(chave)){
        Elemento elemento;
        elemento.chave = chave;
        elemento.valor = valor;
        elementos_.push_back(elemento);
        return;
    }
    ChaveRepetida erro;
    erro.chave = chave;
    throw erro;
}

void Dicionario::Remover(std::string chave){
    if(pertence(chave)){
        for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
            if(itr->chave == chave){
                elementos_.erase(itr);
                break;
            }
        }
        return;
    }
    ChaveInexistente erro;
    erro.chave = chave;
    throw erro;

}


void Dicionario::Alterar(std::string chave, std::string valor){
    if(pertence(chave)){
        for(auto itr = elementos_.begin(); itr!= elementos_.end(); itr++){
            if(itr->chave == chave){
                itr->valor = valor;
                break;
            }
        }
        return;
    }
    ChaveInexistente erro;
    erro.chave = chave;
    throw erro;

}

Dicionario::~Dicionario(){

}