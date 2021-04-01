#include "gtest/gtest.h"
#include "ComplexNumber.h"
#include <iostream>
#include "ComplexExpresion.h"
#include "Exam.h"

TEST(ComplexNumber1, Subtract){
    ComplexNumber c1(1,1);
    ComplexNumber c2(2,3);
    EXPECT_EQ (c1 - c2, ComplexNumber(-1,-2));

}

TEST(ComplexNumber2, Add){
    ComplexNumber c1(1,1);
    ComplexNumber c2(2,3);
    EXPECT_EQ (c1 + c2, ComplexNumber(3,4));
}

TEST(ComplexNumber3, Constructor){
    ComplexNumber c1(1,1);
    EXPECT_EQ (c1, ComplexNumber(1,1));
}

TEST(ComplexNumber4, EmptyConstructor){
    ComplexNumber c1;
    EXPECT_EQ (c1, ComplexNumber(0,0));
}

TEST(ComplexNumber5, MultiplicationByConstans){
    ComplexNumber c1(10,10);
    ComplexNumber result;
    result = (ComplexNumber)10 * c1;
    EXPECT_EQ (result, ComplexNumber(100,100));
}

TEST(ComplexNumber6, MultiplicationByComplexNumber){
    ComplexNumber c1(10,10);
    ComplexNumber c2(2,1);
    EXPECT_EQ (c1 * c2, ComplexNumber(10,30));
}

TEST(ComplexNumber7, Comparision) {
    ComplexNumber c1(10.333333, 10.33333);
    ComplexNumber c2(2.5555555, 1.55555);
    EXPECT_EQ (c1, ComplexNumber(10.33, 10.33));
    EXPECT_EQ (c2, ComplexNumber(2.55, 1.55));
}

TEST(ComplexNumber8, DivisionByConstans){
    ComplexNumber c1(10,10);
    ComplexNumber result;
    result = c1 / (ComplexNumber)10;
    EXPECT_EQ (result, ComplexNumber(1,1));
}

TEST(ComplexNumber9, DivisionByComplexNumber){
    ComplexNumber c1(4,6);
    ComplexNumber c2(1,-5);
    EXPECT_EQ (c1 / c2, ComplexNumber(-1,1));
}

TEST(ComplexNumber10, DivisionByZero){
    ComplexNumber c1(4,4);
    ComplexNumber c2(0,0);
    EXPECT_THROW(c1/c2, std::exception);
}


TEST(ComplexNumber11, GettingComplexNum)
{
    ComplexNumber c1;
    std::stringstream ist;

    ist << "(4+4.67i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNumber(4,4.67));

    ist << "(0-4i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNumber(0,-4));

    ist << "(420.12345+0i)";
    ist >> c1;
    EXPECT_EQ (c1, ComplexNumber(420.12345,0));

    ist = std::stringstream();
    ist << "(420+0.i)";
    ist >> c1;
    EXPECT_EQ(c1, ComplexNumber(420,0));
}

TEST(ComplexNumber12, ErrorThrowsGetting)
{
    ComplexNumber c1;
    std::stringstream ist;

    ist = std::stringstream();
    ist << "420.12345+0i";
    ist >> c1;
    EXPECT_EQ(true, ist.fail());
    c1 = ComplexNumber();

    ist = std::stringstream();
    ist << "(42+0i";
    ist >> c1;
    EXPECT_EQ(true, ist.fail());
    c1 = ComplexNumber();

    ist = std::stringstream();
    ist << "42+0i)";
    ist >> c1;
    EXPECT_EQ(true, ist.fail());
    c1 = ComplexNumber();

    ist = std::stringstream();
    ist << "(42g0i)";
    ist >> c1;
    EXPECT_EQ(true, ist.fail());
    c1 = ComplexNumber();

    ist = std::stringstream();
    ist << "(t + 4i)";
    ist >> c1;
    EXPECT_EQ(true, ist.fail());
    c1 = ComplexNumber();

    ist = std::stringstream();
    ist << "(420+0.0)";
    ist >> c1;
    EXPECT_EQ(true, ist.fail());
    c1 = ComplexNumber();

}

TEST (ComplexNumber13, showInformationAboutComplexNumber) {
    ComplexNumber z1(2, 5);
    ComplexNumber z2(0, -3);
    ComplexNumber z3(-5, 0);
    ComplexNumber z4(0, -1);
    ComplexNumber z5(3, 1);
    ComplexNumber z6(0, 1);
    ComplexNumber z7(10, -7);
    std::stringstream os;

    os << z1;
    ASSERT_EQ("(2+5i)", os.str());

    os = std::stringstream();
    os << z2;
    ASSERT_EQ("(-3i)", os.str());

    os = std::stringstream();
    os << z3;
    ASSERT_EQ("(-5)", os.str());

    os = std::stringstream();
    os << z4;
    ASSERT_EQ("(-i)", os.str());

    os = std::stringstream();
    os << z5;
    ASSERT_EQ("(3+i)", os.str());

    os = std::stringstream();
    os << z6;
    ASSERT_EQ("(i)", os.str());

    os = std::stringstream();
    os << z7;
    ASSERT_EQ("(10-7i)", os.str());
}

TEST (ComplexNumber14, GettingComplexNumber) {
    ComplexNumber z1;
    std::stringstream is;

    is << "(51+55.2i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(51, 55.2));

    is << "(10-5i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(10, -5));

    is << "(-3-1i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(-3, -1));

    is << "(0-1i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(0, -1));

    is << "(1.5+0i)";
    is >> z1;

    ASSERT_EQ(z1, ComplexNumber(1.5, 0));
}

TEST (ComplexNumber15, PrintingEasierVersionOfComplexNumber) {
    ComplexNumber z1;
    std::stringstream is;

    is << "(i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(0, 1));
    z1 = ComplexNumber();

    is << "(-i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(0, -1));
    z1 = ComplexNumber();

    is << "(2i)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(0, 2));
    z1 = ComplexNumber();

    is << "(2)";
    is >> z1;
    ASSERT_EQ(z1, ComplexNumber(2, 0));
    z1 = ComplexNumber();

    is << "(-4i)";
    is >> z1;
    EXPECT_EQ(z1, ComplexNumber(0, -4));
    z1 = ComplexNumber();

    is << "(3-i)";
    is >> z1;
    EXPECT_EQ(z1, ComplexNumber(3, -1));
    z1 = ComplexNumber();
}

TEST (ComplexNumber16, SyntaxErrorGettingComplexNumber) {
    ComplexNumber z1;
    std::stringstream is;

    is << "5+6i)";
    is >> z1;
    EXPECT_EQ(true, is.fail());
    is = std::stringstream();

    is << "(5+6i";
    is >> z1;
    EXPECT_EQ(true, is.fail());
    is = std::stringstream();

    is << "(5+6";
    is >> z1;
    EXPECT_EQ(true, is.fail());
    is = std::stringstream();

    is << "(5+6)";
    is >> z1;
    EXPECT_EQ(true, is.fail());
    is = std::stringstream();

    is << "(5%6i";
    is >> z1;
    EXPECT_EQ(true, is.fail());
    is = std::stringstream();

    is << "(a+6i)";
    is >> z1;
    EXPECT_EQ(true, is.fail());
    is = std::stringstream();

}

TEST (ComplexExpresion1, ConstructorEmpty) {

    ComplexExpresion ComExp;
    ComplexNumber C1;
    EXPECT_EQ(ComExp, ComplexExpresion(C1, C1, '+'));
}

TEST (ComplexExpresion2, Constructor) {


    ComplexExpresion ComExp1;
    ComExp1.setCom1(ComplexNumber(1,1));
    ComExp1.setCom2(ComplexNumber(2,2));
    ComExp1.setOp('-');
    EXPECT_EQ(ComExp1, ComplexExpresion(ComplexNumber(1,1), ComplexNumber(2,2), '-'));
}

TEST (ComplexExpresion3, Comparision) {

    ComplexExpresion ComExp1;
    ComExp1.setCom1(ComplexNumber(1,1));
    ComExp1.setCom2(ComplexNumber(2,2));
    ComExp1.setOp('-');
    ComplexExpresion ComExp2 = ComplexExpresion(ComplexNumber(1,1), ComplexNumber(2,2), '-');
    bool statment = (ComExp2 == ComExp1);
    EXPECT_EQ(true, statment);
}

TEST (ComplexExpresion4, GettingComplexExpresion) {

    ComplexExpresion ComExp1 = ComplexExpresion(ComplexNumber(1,1), ComplexNumber(3,3), '*');
    ComplexExpresion ComExp2 = ComplexExpresion(ComplexNumber(1,1), ComplexNumber(3,3), '+');
    ComplexExpresion ComExp3 = ComplexExpresion(ComplexNumber(1,1), ComplexNumber(3,3), '-');
    ComplexExpresion ComExp4 = ComplexExpresion(ComplexNumber(1,1), ComplexNumber(3,3), '/');



    std::stringstream ost;
    ost << ComExp1;
    EXPECT_EQ("(1+i)*(3+3i)", ost.str());
    ost = std::stringstream();
    ost << ComExp2;
    EXPECT_EQ("(1+i)+(3+3i)", ost.str());
    ost = std::stringstream();
    ost << ComExp3;
    EXPECT_EQ("(1+i)-(3+3i)", ost.str());
    ost = std::stringstream();
    ost << ComExp4;
    EXPECT_EQ("(1+i)/(3+3i)", ost.str());
}


TEST (ComplexExpresion5, GettingComplexExpresion) {

    ComplexExpresion ComExp1;
    ComplexExpresion ComExp2 = ComplexExpresion(ComplexNumber(1,1), ComplexNumber(3,3), '*');
    std::stringstream ist;

    ist << "(1+i)*(3+3i)";
    ist >> ComExp1;
    EXPECT_EQ(ComExp1, ComExp2);
}

TEST (ComplexExpresion6, FailGettingComplexExpresion) {

    ComplexExpresion ComExp;
    std::stringstream ist;
    ist << "(1+i)^(3+3i)";
    EXPECT_THROW(ist >> ComExp, std::exception);
}

TEST (ComplexExpresion7, GettingResult) {

    ComplexExpresion ComExp1 = ComplexExpresion(ComplexNumber(1,1), ComplexNumber(3,3), '+');
    ComplexNumber result1 = ComExp1.getResult();
    EXPECT_EQ(result1, ComplexNumber(4,4));

    ComplexExpresion ComExp2 = ComplexExpresion(ComplexNumber(2,0), ComplexNumber(3,3), '*');
    ComplexNumber result2 = ComExp2.getResult();
    EXPECT_EQ(result2, ComplexNumber(6,6));

    ComplexExpresion ComExp3 = ComplexExpresion(ComplexNumber(2,4), ComplexNumber(2,0), '/');
    ComplexNumber result3 = ComExp3.getResult();
    EXPECT_EQ(result3, ComplexNumber(1,2));
}

TEST (Exam1, Constructor) {

    Exam exam1 = Exam();
    Exam exam2 = Exam();
    exam1.setScore(0);
    exam1.setComExp(ComplexExpresion(ComplexNumber(), ComplexNumber(), '+'));
    exam1.setDifficulty(EASY);
    exam1.setQuestionNum(0);
    EXPECT_EQ(exam1, exam2);
}

TEST (Exam2, CalculateStats) {

    Exam exam1 = Exam();

    exam1.setScore(10);
    exam1.setQuestionNum(110);
    double result = (double)(100 * (double)exam1.getScore() / (double)exam1.getQuestionNum());
    EXPECT_EQ(exam1.calculateStats(), result);
}

TEST (Exam3, FailCalculateStats) {

    Exam exam1 = Exam();

    exam1.setScore(10);
    exam1.setQuestionNum(0);
    EXPECT_THROW(exam1.calculateStats(), std::invalid_argument);
}

TEST (ComplexNumber, argument) {

    ComplexNumber com1 = ComplexNumber(1,0);
    ComplexNumber com2 = ComplexNumber(0,1);

    double arg1 = com1.argument();
    double arg2 = com2.argument();

    EXPECT_EQ(arg1, 0);
    EXPECT_EQ(arg2, (M_PI/2));
}

TEST (ComplexNumber, PlusEqual) {

    ComplexNumber com1 = ComplexNumber(1,2);
    ComplexNumber com2 = ComplexNumber(2,1);

    ComplexNumber result = ComplexNumber(3,3);

    EXPECT_EQ(com1+=com2, result);
    EXPECT_EQ(com1, result);
}

TEST (ComplexNumber, DivisionEqual) {

    ComplexNumber com1 = ComplexNumber(4,4);
    ComplexNumber com2 = ComplexNumber(1,1);

    ComplexNumber result = ComplexNumber(4,0);

    EXPECT_EQ(com1/=com2, result);
    EXPECT_EQ(com1, result);
}

TEST (ComplexNumber, FailDivisionEqual) {

    ComplexNumber com1 = ComplexNumber(4,4);
    ComplexNumber com2 = ComplexNumber(0,0);

    ComplexNumber result = ComplexNumber(4,0);

    EXPECT_THROW(com1/=com2, std::invalid_argument);
}
