//
// Created by artur on 3/17/21.
//
#include "ComplexExpresion.h"


ComplexExpresion::ComplexExpresion() {
    this -> Com1 = ComplexNumber();
    this -> Com2 = ComplexNumber();
    this -> op = '+';
}

ComplexExpresion::ComplexExpresion(ComplexNumber Com1, ComplexNumber Com2, char op) {
    this -> Com1 = Com1;
    this -> Com2 = Com2;
    this -> op = op;
}

void ComplexExpresion::setCom1(ComplexNumber C) {
    this -> Com1 = C;
}

void ComplexExpresion::setCom2(ComplexNumber C) {
    this -> Com2 = C;
}

void ComplexExpresion::setOp(char op) {
    this -> op = op;
}

void ComplexExpresion::setResult(ComplexNumber C) {
    this -> result = C;
}

bool operator==(const ComplexExpresion &ComExp1, const ComplexExpresion &ComExp2) {
    if (ComExp1.Com1 == ComExp2.Com1 && ComExp1.Com2 == ComExp2.Com2 && ComExp1.op == ComExp2.op){
        return true;
    }else{
        return false;
    }

}

std::istream &operator>>(std::istream &ist, ComplexExpresion &ComExp) {

    ist >> ComExp.Com1;
    if (ist.fail()){
        throw std::invalid_argument("invalid argument");
    }
    ist >> ComExp.op;
    if ((ist.fail()) || (ComExp.op != '+' && ComExp.op != '-' && ComExp.op != '/' && ComExp.op != '*')){
        throw std::invalid_argument("invalid argument");
    }
    ist >> ComExp.Com2;
    if (ist.fail()){
        throw std::invalid_argument("invalid argument");
    }
    return ist;
}

std::ostream &operator<<(std::ostream &ost, const ComplexExpresion &comExp) {

    ost << comExp.Com1;
    if(ost.fail()){
        throw std::system_error();
    }
    ost << comExp.op;
    if(ost.fail()){
        throw std::system_error();
    }
    ost << comExp.Com2;
    if(ost.fail()){
        throw std::system_error();
    }
    return ost;
}