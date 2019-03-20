#pragma once
#include<iostream>
#include "priorityQueueNode.hpp"

template<typename Type>
using Node = PriorityQueueNode<Type>;

template<class Type>
class PriorityQueue{

    Node<Type>* top;

  public:
    PriorityQueue();
    ~PriorityQueue();
    void enqueue(const Type& newElement,int priority);
    Type dequeue();
    void display() const;
};

template<class Type>
PriorityQueue<Type>::PriorityQueue()
    : top(nullptr)
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

template<class Type>
void PriorityQueue<Type>::display() const
{
    Node<Type>* current = top;
    while(current)
    {
        std::cout<<current->value<<"\t";
        current = current->next;
    }
    std::cout<<std::endl;

}

template<class Type>
void PriorityQueue<Type>::enqueue(const Type &newElement, int priority)
{
    Node<Type>* node = new Node<Type>(newElement, priority);
    if(!top)
    {
        top = node;
    }
    else if(node->priority >= top->priority)
    {
        node->next=top;
        top->previous=node;
        top=node;
    }
    else
    {
        Node<Type>* current = top;
        while(node->priority < current->priority)
        {
            current=current->next;
        }

        node->next = current;
        current->previous->next = node;
        node->previous = current->previous;
        current->previous = node;
    }

}

template<class Type>
Type PriorityQueue<Type>::dequeue()
{
    if(top)
    {
        Node<Type>* toDequeue = top;
        Type value = toDequeue->value;
        top=top->next;
        delete toDequeue;
        return value;
    }
    else throw std::out_of_range("Queue is empty, nothing left to dequeue");
}
