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

template<class Type>
void Stack<Type>::push(const Type &newElement)
{
    StackNode<Type>* node = new StackNode<Type>(newElement);
    if(!top) top = node;
    else
    {
        node->next = top;
        top = node;
    }
}
