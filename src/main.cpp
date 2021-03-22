#include <iostream>
#include "ComplexNumber.h"
#include "ComplexExpresion.h"
#include "Exam.h"

char argErrorHandling(int argc, char **argv);

int main(int argc, char** argv) {

    char level = argErrorHandling(argc, argv);
    Exam myExam = Exam(level);
    myExam.examLoop();
    std::cout << "The End!\n";
    myExam.calculateStats();
}

char argErrorHandling(int argc, char **argv){
    if(argc < 2){
        throw std::invalid_argument("Additional argument required");
    } else if(argc > 2){
        throw std::invalid_argument("Too many arguments");
    }

    std::string level = argv[1];

    if (level != "easy" && level != "hard"){
        throw std::invalid_argument("Unknown argument");
    }
    if(level == "easy"){
        return EASY;
    }else if(level == "hard"){
        return HARD;
    }
    return '1';
}
