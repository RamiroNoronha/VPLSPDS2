#include <string>
#include <iostream>
#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  if(estoque_.find(mercadoria) == estoque_.end()){
    estoque_[mercadoria] = qtd;
    return;
  }
  estoque_[mercadoria]+=qtd;
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  if(estoque_.find(mercadoria) == estoque_.end()){
    std::cout << "inexistente" << std::endl;
    return;
  }
  if(estoque_[mercadoria] < qtd){
    std::cout << "insuficiente" << std::endl;
    return;
  }
  estoque_[mercadoria]-=qtd;
}



unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO
  if(estoque_.find(mercadoria) == estoque_.end()){
    return 0;
  }
  return estoque_.find(mercadoria)->second;
}

void Estoque::imprime_estoque() const {
  // TODO
  for(auto item : estoque_){
    std::cout << item.first << ", " << item.second << std::endl;
  }

}

Estoque& Estoque::operator += (const Estoque& rhs) {
  // TODO
  for(auto itemRHS : rhs.estoque_){
    this->add_mercadoria(itemRHS.first, itemRHS.second);
  }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  // TODO
  for(auto itemRHS : rhs.estoque_){
    this->sub_mercadoria(itemRHS.first, itemRHS.second);
  }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  // TODO
  if(lhs.estoque_.size() > rhs.estoque_.size())
    return false;
  for(auto item : lhs.estoque_){
    if(rhs.estoque_.find(item.first) == rhs.estoque_.end())
        return false;
         
    if(rhs.estoque_[item.first] <= item.second)
        return false;
  }

  return true;
  
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  // TODO
  if(lhs.estoque_.size() < rhs.estoque_.size())
    return false;
  for(auto item : rhs.estoque_){
    if(lhs.estoque_.find(item.first) == lhs.estoque_.end())
        return false;
         
    if(lhs.estoque_[item.first] <= item.second)
        return false;
  }
  return true;
}