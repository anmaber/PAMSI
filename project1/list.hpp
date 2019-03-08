#pragma once

#include "node.hpp"
#include <iostream>

template<class Type>
class List
{

    Node<Type>* head;
    Node<Type>* tail;
    int size;

public:

    List();
    ~List();
    void display() const;
    void push_back(const Type& newElement);
    void push_front(const Type& newElement);
    Node<Type>* find(const Type& element) const;
    void remove(const Type& element);
};

template<class Type>
List<Type>::List()
     :head(nullptr),
      tail(nullptr),
      size(0)
{}

template<class Type>
List<Type>::~List()
{
    while(head)
    {
        Node<Type>* next = head->next;
        delete head;
        head = next;
    }
}

template<class Type>
void List<Type>::display() const
{
    Node<Type>* current = head;

    while(current)
    {
        std::cout<<current->value<<"\t";
        current=current->next;
    }
    std::cout<<std::endl;
}

template<class Type>
void List<Type>::push_back(const Type &newElement)
{
    Node<Type>* node = new Node<Type>(newElement);

    if(!head)
    {
        head=node;
        tail=node;
    }
    else
    {
        tail->next = node;
        node->previous = tail;
        tail = node;
    }
    size++;
}

template<class Type>
void List<Type>::push_front(const Type &newElement)
{
    Node<Type>* node = new Node<Type>(newElement);

    if(!head)
    {
        head=node;
        tail=node;
    }
    else
    {
        head->previous=node;
        node->next=head;
        head=node;
    }
    size++;
}

template<class Type>
Node<Type>* List<Type>::find(const Type &element) const
{
    Node<Type>* current = head;
    while(current->value != element)
    {
        current=current->next;
        if(current == tail && current->value != element) return nullptr;
    }
    return current;
}

template<class Type>
void List<Type>::remove(const Type &element)
{
    Node<Type>* toRemove = find(element);
    if(toRemove)
    {
       if(toRemove == head)
       {
           head->next->previous = nullptr;
           head=head->next;
           delete toRemove;
       }
       else if(toRemove == tail)
       {
           tail->previous->next=nullptr;
           tail=tail->previous;
           delete toRemove;
       }
       else
       {
           toRemove->previous->next=toRemove->next;
           toRemove->next->previous=toRemove->previous;
           delete toRemove;
       }
    }
}

