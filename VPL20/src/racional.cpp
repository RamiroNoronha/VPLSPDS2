#include "racional.h"

int MDC(int n1, int n2){
    int mdc = 1;
    int n1abs = abs(n1);
    int n2abs = abs(n2);
    int maior = 1;
    n1abs>n2abs? maior = n1abs : maior = n2abs;

    for(int i =2; i <=(maior/2 + 1); i++){
        if(n1abs%i == 0 && n2abs%i ==0){
            mdc*=i;
            n1abs/=i;
            n2abs/=i;
            i--;
        }
    }

    return mdc;

}

Racional::Racional(): numerador_(0), denominador_(1){}


Racional::Racional(int n): numerador_(n), denominador_(1){}

Racional::Racional(int n, int d) : numerador_(n){
    if(d == 0){
       ExcecaoDivisaoPorZero ex;
        throw ex;
    }
    denominador_ = d;
    this->Simplificar();
}

int Racional::numerador() const{
    return numerador_;
}

int Racional::denominador() const{
    return denominador_;
}

Racional Racional::operator-() const{
    Racional r(-(this->numerador()), (this->denominador()));
    return r;
}

Racional Racional::operator+(Racional k) const{
    int novoDenominador = this->denominador() * k.denominador();
    int novoNumerador = this->denominador() * k.numerador() + k.denominador() * this->numerador();
    Racional r(novoNumerador, novoDenominador);
    return r;
}

Racional Racional::operator-(Racional k) const{
    Racional s = -k;
    return *this + s;
}

Racional Racional::operator*(Racional k) const {
    int novoNumerador = this->numerador() * k.numerador();
    int novoDenominador = this->denominador() * k.denominador();
    Racional r(novoNumerador, novoDenominador);
    return r;
}

Racional Racional::operator/(Racional k) const {
    int novoNumerador = this->numerador() * k.denominador();
    int novoDenominador = this->denominador() * k.numerador();
    Racional r(novoNumerador, novoDenominador);
    return r;
}

void Racional::Simplificar() {
    int mdc = MDC(this->numerador(), this->denominador());
    numerador_/=mdc;
    denominador_/=mdc;
    if(numerador_*denominador_ < 0){
        denominador_ = abs(denominador_);
        numerador_ = -abs(numerador_);
    }
}

Racional::operator float() const {
    float numerador = this->numerador();
    float denominador = this->denominador();
    return numerador/denominador;
}

Racional::operator string() const{
    return std::to_string(this->numerador()) + '/' + std::to_string(this->denominador());
}

ostream& operator<<(ostream& out, Racional r) {
    out << string(r);
    return out;
}

istream& operator>>(istream& in, Racional& r){
    in >> r.numerador_ >> r.denominador_;
    r.Simplificar();
    return in;
}




