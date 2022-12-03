#include "vetor.h"
#include <string>

std::string* referencia;
int comeco;
int final;
Vetor::Vetor(int inicio, int fim){
    if(fim >=inicio){
        inicio_ = inicio;
        elementos_= new std::string[fim-inicio + 1];
    }
    referencia = elementos_;
    comeco = inicio_;
    final = fim;
}



void Vetor::atribuir(int i, std::string valor){
    if(i >= comeco && i <= final){
        referencia[i-comeco] = valor;
    }
}

std::string Vetor::valor(int i)const{
    if(i>= comeco && i <= final){
        return referencia[i - comeco];
    }
    return "";
}

Vetor::~Vetor() {}
