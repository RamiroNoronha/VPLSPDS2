#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
   std::string retorno = std::to_string(m_qtd) + "X Comida japonesa - " + combinado_ + ", ";
   retorno+= std::to_string(sushis_) + " sushis, ";
   retorno+= std::to_string(temakis_) + " temakis e ";
   retorno+= std::to_string(hots_) + " hots.";
  return retorno;
}

Japonesa::Japonesa(const std::string &combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) : combinado_(combinado), sushis_(sushis), temakis_(temakis), hots_(hots)
{
    // TODO: Implemente este metodo.
    this->m_qtd = qtd;
    this->m_valor_unitario = valor_unitario;
}