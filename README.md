# Initialization
1. Create "build" directory in main project directory
2. Move "hard.txt" and "easy.txt" to "build" directory  
3. Go to build and use "cmake .." command
4. Use "make" command
5. For running tests run build/tst/complex_number_tst
7. For running main program run /build/complex_number_run with argument "easy" or "hard"
8. Enjoy !

# Program structure
The program includes 3 classes. The first is standard ComplexNumber, next one is ComplexExpresion.
Is contains 2 complex numbers, operator, and result of operation. Final class is Exam. 
method examLoop with belong to this class read complex expresion from files "easy.txt" or "hard.txt"
and gets answer from "cin". Then if answer is equal to result of complex expresion that has been read, 
method give one score. Another method "calculateStats" give precentage of good answer, and prints it.

# Info
In lib directory is local version of "Gtests" external library used for tests. In tst directory are all test,
inferior CmakeList, and main function for running all tests.
