//
// Created by artur on 3/18/21.
//

#include "Exam.h"

Exam::Exam() {
    this -> score = 0;
    this -> questionNum =0;
    this -> comExp = ComplexExpresion();
    this -> difficulty = EASY;
}

Exam::Exam(char difficulty) {
    this -> score = 0;
    this -> questionNum =0;
    this -> comExp = ComplexExpresion();
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
    this -> difficulty = difficulty;
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


void Exam::examLoop() {;
    std::string examFile;

    if(this -> difficulty == EASY){
        examFile = "easy.txt";
    }else if (this -> difficulty == HARD){
        examFile = "hard.txt";
    }else{
        throw std::invalid_argument("no difficulty selected");
    }
    int iterator = 0;
    int mistake = 0;
    int score = 0;
    ComplexNumber answer = ComplexNumber();
    ComplexExpresion tmpExp;
    std::stringstream sts;
    std::string tmp;
    std::ifstream myReadFile;
    myReadFile.open(examFile);
    if(myReadFile.is_open()){
        while(std::getline(myReadFile, tmp)){
            iterator++;
            setQuestionNum(iterator);
            sts << tmp;
            sts >> tmpExp;
            setComExp(tmpExp);
            std::cout << "Question number: " << iterator << std::endl;
            std::cout << (this -> comExp) << std::endl;
            answer = ComplexNumber();
            mistake = 0;

            while(mistake <3){
                if(std::cin >> answer){
                    std::cin.clear();
                    std::cin.ignore();
                    break;
                }
                if (!(std::cin >> answer)){
                    std::cin.clear();
                    std::cin.ignore();
                    std::cout << "correct your syntax\n";

                }
                mistake++;
            }

            comExp.calculateResult();
            if(comExp.getResult() == answer){
                std::cout << "Good answer\n";
                score ++;
                setScore(score);
            }else {
                std::cout << "Wrong answer, correct is:" << comExp.getResult() << std::endl;
            }
        }
    }
    myReadFile.close();
}

double Exam::calculateStats() {

    double result = (double)(100 * (double)(this -> score) / (double)(this -> questionNum));
    std::cout << "Your score: " << (this -> score) << "/" << (this -> questionNum) << std::endl;
    std::cout << "This is: " << result << "%\n";
    return result;
}

int Exam::getScore() {
    return (this->score);
}

int Exam::getQuestionNum() {
    return (this->questionNum);
}
