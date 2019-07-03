//
//  Calculator.hpp
//  Project 2
//
//  Created by Mai Pham on 10/7/17.
//  Copyright © 2017 Mai Pham. All rights reserved.
//

#ifndef Calculator_hpp
#define Calculator_hpp

#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

class Calculator
{
private:
    string infix;
    string postfix;
    int answer;
public:
    Calculator(string exp);
    bool validate();
    void convert();
    void evaluate();
    int check(char c);
    string inFix();
    string postFix();
    int result();
};
#endif /* Calculator_hpp */
