#include <iostream>
#include "ComplexNumber.h"
#include "ComplexExpresion.h"

std::string argErrorHandling(int argc, char **argv);

int main(int argc, char** argv) {

//    ComplexNumber C;
//    char x;
//
//    std::cin >> C >>  x ;
//
//    std::cout << C << "__" << x << std::endl;

   ComplexExpresion ComExp;
   std::cin >> ComExp;
   std::cout << ComExp << " <- shown \n" << std::endl;

//    std::string level = argErrorHandling(argc, argv);
//
//    ComplexNumber Com;
//    std::cout << "podaj complex \n";
//    std::cin >> Com;
//    ComplexNumber Com1(2.0001,2.00001);
//    std::cout << "sparadzam czy takie same \n";
//    bool sprawdzam = (Com == Com1);
//    std::cout << sprawdzam << "; \n" << Com << std::endl;

}

std::string argErrorHandling(int argc, char **argv){
    if(argc < 2){
        throw std::invalid_argument("Additional argument required");
    } else if(argc > 2){
        throw std::invalid_argument("Too many arguments");
    }

    std::string level = argv[1];

    if (level != "easy" && level != "hard"){
        throw std::invalid_argument("Unknown argument");
    }

    return level;
}