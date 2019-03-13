#pragma once

#include<iostream>
#include "priorityQueueNode.hpp"

template<typename Type>
using Node = PriorityQueueNode<Type>;

template<class Type>
class PriorityQueue{

    Node<Type>* top;
    Node<Type>* bottom;

  public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(const Type& newElement);
    Type dequeue();
    void display() const;
};

template<class Type>
PriorityQueue<Type>::PriorityQueue()
    : top(nullptr),
      bottom(nullptr)
{}

template<class Type>
PriorityQueue<Type>::~PriorityQueue()
{
 while(top)
 {
     Node<Type>* next = top->next;
     delete top;
     top=next;
 }
}
