#include "dicionario.h"
#include<iostream>

Dicionario::Dicionario(){

}

int Dicionario::tamanho(){
    return elementos_.size();
}


bool Dicionario::pertence(std::string chave){
    // for(auto elemento : elementos_){
    //     if(elemento.chave == chave){
    //         return true;
    //     }
    // }
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
}

std::string Dicionario::valor(std::string chave){
    if(pertence(chave)){
        for(auto elemento : elementos_){
            if(elemento.chave == chave){
                return elemento.valor;
            }
        }
    }
}

void Dicionario::Inserir(std::string chave, std::string valor){
    if(!pertence(chave)){
        Elemento elemento;
        elemento.chave = chave;
        elemento.valor = valor;
        elementos_.push_back(elemento);
    }
}

void Dicionario::Remover(std::string chave){
    if(pertence(chave)){
        for(auto itr = elementos_.begin(); itr != elementos_.end(); itr++){
            if(itr->chave == chave){
                elementos_.erase(itr);
                break;
            }
        }
    }
}


void Dicionario::Alterar(std::string chave, std::string valor){
    if(pertence(chave)){
        // for(auto elemento : elementos_){
        //     if(elemento.chave == chave ){
        //         std::cout << elemento.chave << std::endl;
        //         std::cout << elemento.valor << std::endl;
        //         elemento.valor = valor;
        //         std::cout << "Depois da mudança: " << elemento.valor << std::endl;
        //         std::cout << &elemento << std::endl;
        //         break;
        //     }
        // }
        for(auto itr = elementos_.begin(); itr!= elementos_.end(); itr++){
            if(itr->chave == chave){
                itr->valor = valor;
                break;
            }
        }
    }
}

Dicionario::~Dicionario(){
    delete[] &elementos_;
}