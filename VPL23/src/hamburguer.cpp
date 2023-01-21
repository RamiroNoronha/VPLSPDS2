#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada do Hamburguer.
   *
   * Exemplos:
   * 1X Hamburguer X-tudo artesanal.
   * 1X Hamburguer X-tudo simples.
   */
   std::string retorno =  std::to_string(m_qtd) + "X Hamburguer " + tipo_;
   arteranal_? retorno += " artesanal." : retorno+= " simples.";
  return retorno;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) : tipo_(tipo), arteranal_(artesanal){
                        this->m_qtd = qtd;
                        this->m_valor_unitario = valor_unitario;
  // TODO: Implemente este metodo.
}