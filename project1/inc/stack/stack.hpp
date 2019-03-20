#pragma once

#include <iostream>
#include <exception>

#include "stackNode.hpp"

template<class Type>
class Stack
{
    StackNode<Type>* top;

public:
    Stack();
    ~Stack();
    void push(const Type& newElement);
    Type pop();
    void display() const;
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

template<class Type>
Type Stack<Type>::pop()
{

    if(top)
    {
        StackNode<Type>* toPop = top;
        Type value = toPop->value;
        top=toPop->next;
        delete toPop;
        return value;
    }
    else throw std::out_of_range("Stack is empty, nothing left to pop");
}

template<class Type>
void Stack<Type>::display() const
{
    StackNode<Type>* current = top;
    while(current)
    {
        std::cout<<current->value<<"\t";
        current = current->next;
    }
    std::cout<<std::endl;
}
