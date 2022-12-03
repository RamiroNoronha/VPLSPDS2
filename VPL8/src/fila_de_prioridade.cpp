#include "fila_de_prioridade.h"
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;

void FilaDePrioridade::Adicionar(Pessoa p) {
    lista_.push_back(p);
}

string FilaDePrioridade::RemoverMaiorPrioridade() {
    list<Pessoa> listaNova;
    if(lista_.size() > 0){
        Pessoa prioridade;
        prioridade = lista_.front();
    for(Pessoa p: lista_){
        listaNova.push_back(p);
        if(p.prioridade > prioridade.prioridade){
            prioridade = p;
        }
    }
    lista_.clear();
    for(Pessoa p: listaNova){
        if(p.nome != prioridade.nome || p.prioridade !=  p.prioridade){
            lista_.push_back(p);
        }
    }
    return prioridade.nome;
    }
    return "";
}

void FilaDePrioridade::Remover(string nome) {
    list<Pessoa> listaNova;
    for(Pessoa p: lista_){
        if(!(p.nome == nome)){
            listaNova.push_back(p);
        }
    }  
    lista_.clear();
    for(Pessoa p: listaNova){
        lista_.push_back(p);
    } 
}

int FilaDePrioridade::tamanho() {
  return lista_.size();
}

bool ordernarPorPrioridade(Pessoa& a, Pessoa& b){
    return a.prioridade > b.prioridade;
}

vector<string> FilaDePrioridade::listar() {
  vector<string> c;
  vector<Pessoa> pessoas;
  for(Pessoa p : lista_){
    pessoas.push_back(p);
  }
  std::sort(pessoas.begin(), pessoas.end(), ordernarPorPrioridade);
    for(Pessoa p: pessoas){
        c.push_back(p.nome);
    }
  return c;

}



