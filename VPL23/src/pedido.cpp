#include "pedido.hpp"


Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  float total = 0.0f;
  for(auto item: m_produtos){
    total+=item->getValor() * item->getQtd();
  }
  return total;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
  std::string resumo = "";
  for(auto item : m_produtos){
    resumo+= item->descricao() + "\n";
  }
  resumo+=m_endereco;
  return resumo;
}