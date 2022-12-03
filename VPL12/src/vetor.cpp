#include "vetor.h"
#include <string>
#include <set>


std::string* referencia;
int comeco;
int final;
std::set<int> indicesUsados;
Vetor::Vetor(int inicio, int fim){
    if(fim >=inicio){
        inicio_ = inicio;
        elementos_= new std::string[fim-inicio + 1];
    } else {
        IntervaloVazio intervaloVazio;
        intervaloVazio.inicio = inicio;
        intervaloVazio.fim = fim;
        throw intervaloVazio;
    }
    referencia = elementos_;
    comeco = inicio_;
    final = fim;
}



void Vetor::atribuir(int i, std::string valor){
    if(i >= comeco && i <= final){
        referencia[i-comeco] = valor;
        indicesUsados.insert(i);
    } else {
        IndiceInvalido indiceInvalido;
        indiceInvalido.inicio = comeco;
        indiceInvalido.fim = final;
        indiceInvalido.indice = i;
        throw indiceInvalido;
    }
    
}

std::string Vetor::valor(int i)const{
    bool inicializado = false;
    if(i>= comeco && i <= final){
        for(auto indice: indicesUsados){
            if(i == indice){
                inicializado = true;
                break;
            }
           
        }
         if(!inicializado){
                IndiceNaoInicializado erro;
                erro.indice = i;
                throw erro;
            }
        return referencia[i - comeco];
    }
    IndiceInvalido indiceInvalido;
    indiceInvalido.inicio = comeco;
    indiceInvalido.fim = final;
    indiceInvalido.indice = i;
    throw indiceInvalido;
}

Vetor::~Vetor() {}