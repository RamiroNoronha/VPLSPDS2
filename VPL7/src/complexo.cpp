// Copyright 2022 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() {
    z_ = 0;
    arg_ = 0;
}

Complexo::Complexo(double a, double b) {
    double real = a;
    double img = b;
    z_ = sqrt(pow(real, 2) + pow(img, 2));
    arg_ = atan(img/real);
}

double Complexo::real() {
  return z_ * cos(arg_);
}

double Complexo::imag() {
  return z_ * sin(arg_);
}

bool Complexo::igual(Complexo x) {
  return x.real() == real() && x.imag() == imag();
}

void Complexo::Atribuir(Complexo x) {
    *this = x;
}

double Complexo::modulo() {
  return sqrt(pow(real(), 2) + pow(imag(), 2));
}

Complexo Complexo::conjugado() {
  Complexo c(real(), -imag());
  return c;
}

Complexo Complexo::simetrico() {
  Complexo c (-real(), -imag());
  return c;
}

Complexo Complexo::inverso() {
    Complexo a = this->conjugado();
    Complexo b = this->multiplicar(a);

    Complexo i(a.real()/b.real(), a.imag()/b.real());
    return i;
}

Complexo Complexo::somar(Complexo y) {
  Complexo s(y.real() + real(), y.imag() + imag());
  return s;
}

Complexo Complexo::subtrair(Complexo y) {
  Complexo s (real() - y.real(), imag() - y.imag());
  return s;
}

Complexo Complexo::multiplicar(Complexo y) {
  Complexo p(this->real() * y.real() - (this->imag() * y.imag()), this->real() * y.imag() + this->imag() * y.real());
  return p;
}

Complexo Complexo::dividir(Complexo y) {
  Complexo cy = y.conjugado();
  Complexo divisor = y.multiplicar(cy);
  Complexo dividendo = this->multiplicar(cy);
  Complexo d(dividendo.real()/divisor.real(), dividendo.imag()/divisor.real());
  return d;
}