//
// Created by artur on 3/17/21.
//



#ifndef COMPLEXNUMBER_COMPLEXEXPRESION_H
#define COMPLEXNUMBER_COMPLEXEXPRESION_H
#include <iostream>
#include "ComplexNumber.h"

class ComplexExpresion {
private:
    ComplexNumber Com1;
    ComplexNumber Com2;
    char op;
    ComplexNumber result;



public:
    ComplexExpresion();
    ComplexExpresion(ComplexNumber Com1, ComplexNumber Com2, char oper);

    friend std::ostream & operator<<(std::ostream & ost, const ComplexExpresion &ComExp);
    friend std::istream & operator>>(std::istream & ist, ComplexExpresion &ComExp);
    friend bool operator==(const ComplexExpresion &ComExp1, const ComplexExpresion &ComExp2);


    void setCom1(ComplexNumber C);
    void setCom2(ComplexNumber C);
    void setOp(char op);
    void setResult(ComplexNumber C);
    void calculateResult();
    ComplexNumber getResult();

};
#endif //COMPLEXNUMBER_COMPLEXEXPRESION_H
