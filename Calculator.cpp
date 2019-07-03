//
//  Calculator.cpp
//  Project 2
//
//  Created by Mai Pham on 10/7/17.
//  Copyright © 2017 Mai Pham. All rights reserved.
//

#include "Calculator.h"
#include "Stack.h"
#include <iostream>
#include <string>
#include <math.h>
#include <sstream>
using namespace std;

Calculator::Calculator(string exp)
{
    infix = exp;
    postfix = "";
    answer = 0;
}
bool Calculator::validate()
{
    Stack<char> s;
    
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ')
            continue;
        if(infix[i] >= '0' && infix[i] <= '9')
            continue;
        if (check(infix[i]) > 0)
            continue;
        if (infix[i] == '(')
            s.push(infix[i]);
        else if (infix[i] == ')')
        {
            if (s.top() == '(')
                s.pop();
            else
                s.push(infix[i]);
        }
        else
            s.push(infix[i]);
    }
    if (s.empty())
        return true;
    else
        return false;
}
void Calculator::convert()
{
    Stack<char> s;
    
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == ' ')
            continue;
        else if(infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
            while(infix[i+1] >= '0' && infix[i+1] <= '9')
            {
                postfix += infix[i+1];
                i++;
            }
            postfix += ' ';
        }
        else if (infix[i] == '(')
            s.push(infix[i]);
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.pop();
        }
        else
        {
            while(!s.empty() && check(infix[i]) <= check(s.top()))
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(infix[i]);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }
}
void Calculator::evaluate()
{
    Stack<int> s;
    
    istringstream stream(postfix);
    string n;
    int m;
    
    while(stream >> n)
    {
        if (n == " ")
            continue;
        else if (isdigit(n[0]))
        {
            m = stoi(n);
            s.push(m);
        }
        else
        {
            int value2 = s.top();
            s.pop();
            int value1 = s.top();
            s.pop();
            switch (n[0])
            {
                case '+':
                    s.push(value1 + value2);
                    break;
                case '-':
                    s.push(value1 - value2);
                    break;
                case '*':
                    s.push(value1 * value2);
                    break;
                case '/':
                    s.push(value1 / value2);
                    break;
                case '%':
                    s.push(value1 % value2);
                    break;
                case '^':
                    s.push(pow(value1, value2));
                    break;
                default:
                    break;
            }
        }
    }
    answer = s.top();
}
int Calculator::check(char c)
{
    switch (c)
    {
        case '+':
        case '-':
            return 1;
            
        case '*':
        case '/':
        case '%':
            return 2;
            
        case '^':
            return 3;
    }
    return -1;
}
string Calculator::inFix()
{
    return infix;
}
string Calculator::postFix()
{
    return postfix;
}
int Calculator::result()
{
    return answer;
}

