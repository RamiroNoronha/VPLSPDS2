#include "pizza.hpp"

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
   std::string retorno = std::to_string(m_qtd) + "X Pizza " + sabor_ + ", " + std::to_string(pedacos_);
   borda_recheada_? retorno += " e borda recheada": retorno+= " sem borda recheada";
  return retorno;
}

Pizza::Pizza(const std::string &sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) : sabor_(sabor), pedacos_(pedacos), borda_recheada_(borda_recheada)
{
    // TODO: Implemente este metodo.
    this->m_qtd = qtd;
    this->m_valor_unitario = valor_unitario;
}