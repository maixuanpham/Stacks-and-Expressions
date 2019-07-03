//
//  main2.cpp
//  Project 2
//
//  Created by Mai Pham on 10/7/17.
//  Copyright © 2017 Mai Pham. All rights reserved.
//

#include "Calculator.h"
#include "Stack.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Project 2: Stacks & Expressions\n";
    cout << "Author: Mai Pham\n\n";
    string expression;
    
    cout << "Enter an arithmetic expression: ";
    getline(cin,expression);
    
    while (expression != "0")
    {
        cout << "The infix expression is: " << expression << endl;
        Calculator cal(expression);
        if (cal.validate() == true)
        {
            cal.convert();
            cal.evaluate();
            cout << "The postfix expression is: " << cal.postFix() << endl;
            cout << "The answer is: " << cal.result() << endl << endl;
        }
        else
            cout << "The expression is invalid." << endl << endl;
        
        cout << "Enter an arithmetic expression: ";
        getline(cin,expression);
    }
    cout << "Thank you for using the program." << endl;
    return 0;
}
