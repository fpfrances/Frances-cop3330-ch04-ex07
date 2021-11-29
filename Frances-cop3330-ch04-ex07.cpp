/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Filipe Frances
 */
#include "header.h"

int digit_parse(std::string value){
    for (int i = 0; i < 10; ++i){
        if (value == spelled_digit[i] || value == digit[i])
            return i;
    }
    throw std::runtime_error("Bad input value!");
}

int Mini_calculator(){
    std::cout << "Enter two single digit values separated by an operator (+,-,* or /): ";
    std::string Num1;
    std::string Num2;
    char op = 0;
    while (std::cin >> Num1 >> op >> Num2){
        std::string oper;
        int n1 = digit_parse(Num1);
        int n2 = digit_parse(Num2);
        int result;
        switch (op){
        case '+':
            oper = "sum of ";
            result = n1 + n2;
            break;
        case '-':
            oper = "difference between ";
            result = n1 - n2;
            break;
        case '*':
            oper = "product of ";
            result = n1 * n2;
            break;
        case '/':
            oper = "division of ";
            result = n1 / n2;
            break;
        default:
            std::runtime_error("Bad operator.");
            return 0;
        }
        std::cout << oper << n1 << " and " << n2 << " is " << result << std::endl;
        std::cout << "Try again: " << std::endl;;
    }

}


int main(int argc, char const* argv[]){
    try{
        Mini_calculator();
    }
    catch (std::runtime_error& e){
        std::cout << e.what() << '\n';
    }
    catch (...){
        std::cout << "exiting\n";
    }
    system("pause>0");
}