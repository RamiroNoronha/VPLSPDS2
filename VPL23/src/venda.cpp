#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
  int cont = 0;
  float total = 0.0f;
  for(auto pedido : m_pedidos){
    cont++;
    std::cout << "Pedido " << std::to_string(cont) << std::endl;
    std::cout << pedido->resumo() << std::endl;
    total+= pedido->calculaTotal();
  }
  std::cout << std::fixed << std::setprecision(2);
  std::cout.precision(2);
  std::cout << "Total de vendas: R$ " << total << std::endl;
  std::cout << "Total de pedidos: " << std::to_string(cont) << std::endl;
}