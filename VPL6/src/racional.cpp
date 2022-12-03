#include "racional.h"

#include <cmath>
#include <iostream>

void Racional::Normalizar() {
 int menor = 0;
 bool negativo = false;
 if(numerador() < denominador()){
    menor = numerador();
 } else {
    menor = denominador();
 }
 if(menor < 0){
    menor = menor * -1;
    negativo = true;
 }
 if(numerador() !=1 && denominador() !=1){
    int numeradorFatorado = numerador();
    int denominadorFatorado = denominador();
    if(negativo){
        if(numeradorFatorado < 0 && denominadorFatorado < 0){
            negativo = false;
        }
        if(numeradorFatorado < 0){
            numeradorFatorado = -numeradorFatorado;
        }
        if(denominadorFatorado < 0){
            denominadorFatorado = -denominadorFatorado;
        }
        
    }
    for(int i =2; i <= menor; i ++){
        if(numeradorFatorado == 1 || denominadorFatorado == 1){
            break;
        }
        if(numeradorFatorado%i == 0 && denominadorFatorado%i ==0){
        numeradorFatorado/=i;
        denominadorFatorado/=i;
        i--;
    }
 }
 if(negativo){
    numerador_ = -numeradorFatorado;
 } else{
    numerador_ = numeradorFatorado;
 }
 denominador_ = denominadorFatorado;
 }
 
}

Racional::Racional() {
  numerador_ = 0;
  denominador_ = 1;
}

Racional::Racional(int n)  {
  numerador_ = n;
  denominador_ = 1;
}

Racional::Racional(int n, int d) {
  numerador_ = n;
  denominador_ = d;
}

int Racional::numerador() const {
  return numerador_;
}

int Racional::denominador() const {
  return denominador_;
}

Racional Racional::simetrico() const {
  Racional smt(numerador(), denominador());
  smt.Normalizar();
  return Racional(-smt.numerador(), smt.denominador());
}

Racional Racional::somar(Racional k) const {
  int novoDenominador = denominador() * k.denominador();
  int novoNumerador = k.denominador() * numerador() + k.numerador() * denominador();
  Racional racional(novoNumerador, novoDenominador);
  racional.Normalizar();
  return racional;
}

Racional Racional::subtrair(Racional k) const {
  int novoDenominador = denominador() * k.denominador();
  int novoNumerador = k.denominador() * numerador() - k.numerador() * denominador();
  Racional racional(novoNumerador, novoDenominador);
  racional.Normalizar();
  return racional;
}

Racional Racional::multiplicar(Racional k) const {
  int novoDenominador = denominador() * k.denominador();
  int novoNumerador = numerador() * k.numerador();
  Racional racional(novoNumerador, novoDenominador);
  racional.Normalizar();
  return racional;
}

Racional Racional::dividir(Racional k) const {
  int novoDenominador = denominador() * k.numerador();
  int novoNumerador = numerador() * k.denominador();
  Racional racional(novoNumerador, novoDenominador);
  racional.Normalizar();
  return racional;
}
