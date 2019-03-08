#pragma once

#include "node.hpp"
#include <iostream>

template<class Type>
class List
{


public:

    Node<Type>* head;
    Node<Type>* tail;

    List();
    ~List();
    void push_back(const Type& newElement);
    void push_front(const Type& newElement);
};

template<class Type>
List<Type>::List()
     :head(nullptr),
      tail(nullptr)
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
}

