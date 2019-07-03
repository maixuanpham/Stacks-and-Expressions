//
//  Stack.h
//  Project 2
//
//  Created by Mai Pham on 10/7/17.
//  Copyright © 2017 Mai Pham. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack
{
private:
    T arr[20];
    int current;
public:
    Stack()
    {
        current = 0;
    }
    void push(T t)
    {
        arr[current] = t;
        current++;
    }
    void pop()
    {
        current--;
    }
    T top()
    {
        return arr[current-1];
    }
    int size()
    {
        return current;
    }
    bool empty()
    {
        if(current == 0)
            return true;
        return false;
    }
    bool full()
    {
        if(current == 20)
            return true;
        return false;
    }
};
#endif /* Header_h */

