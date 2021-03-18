//
// Created by artur on 3/18/21.
//

#include "Exam.h"

Exam::Exam() {
    this -> score = 0;
    this -> questionNum =0;
    this -> comExp = CompexExpresion();
    this -> difficulty = EASY;
}

Exam::Exam(char difficulty) {
    this -> score = 0;
    this -> questionNum =0;
    this -> comExp = CompexExpresion();
    if(difficulty != EASY && difficulty != HARD){
        throw std::invalid_argument("invalid dificulty");
    }else{
        this -> difficulty = difficulty;
    }
}

void Exam::setScore(int score) {
    this -> score = score;
}

void Exam::setDifficulty(char difficulty) {
    this -> difficulty = difficultye
}

void Exam::setQuestionNum(int questionNum) {
    this -> questionNum = questionNum;
}

void Exam::setComExp(ComplexExpresion comExp) {
    this -> comExp = comExp;
}

bool operator==(const Exam &Exam1, const Exam &Exam2) {
    if ((Exam1.score == Exam2.score) && (Exam1.questionNum == Exam2.questionNum) &&
        (Exam1.comExp == Exam2.comExp) && (Exam1.difficulty == Exam2.difficulty)) {
        return true;
    }else{
        return false;
    }
}

