#pragma once

#include "stackNode.hpp"

template<class Type>
class Stack
{
    StackNode<Type>* top;

public:
    Stack();
    ~Stack();
    void push(const Type& newElement);
};



template<class Type>
Stack<Type>::Stack()
    : top(nullptr)
{}

template<class Type>
Stack<Type>::~Stack()
{
    while(top)
    {
        StackNode<Type>* next = top->next;
        delete top;
        top = next;
    }
}
