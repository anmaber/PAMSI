#pragma once

#include <iostream>

#include "queueNode.hpp"

template<class Type>
class Queue{

    QueueNode<Type>* top;
    QueueNode<Type>* bottom;

  public:
    Queue();
    ~Queue();
    void enqueue(const Type& newElement);
    Type dequeue();
    void display() const;
};

template<class Type>
Queue<Type>::Queue()
    : top(nullptr),
      bottom(nullptr)
{}

template<class Type>
Queue<Type>::~Queue()
{
 while(top)
 {
     QueueNode<Type>* next = top->next;
     delete top;
     top=next;
 }
}

template<class Type>
void Queue<Type>::enqueue(const Type &newElement)
{
    QueueNode<Type>* node = new QueueNode<Type>(newElement);
    if(!top)
    {
        top = node;
        bottom = node;
    }
    else
    {
        bottom->next = node;
        bottom = node;
    }

}

template<class Type>
Type Queue<Type>::dequeue()
{
    if(top)
    {
        QueueNode<Type>* toDequeue = top;
        Type value = toDequeue->value;
        top=top->next;
        delete toDequeue;
        return value;
    }
    else throw std::out_of_range("Queue is empty, nothing left to dequeue");
}

template<class Type>
void Queue<Type>::display() const
{
    QueueNode<Type>* current = top;
    while(current)
    {
        std::cout<<current->value<<"\t";
        current = current->next;
    }
    std::cout<<std::endl;

}

