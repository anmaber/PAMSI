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
        std::cout<<"ok";

    }
    else
    {
        std::cout<<"\t not ok";

        tail->next = node;
        node->previous = tail;
        tail = node;
    }

}
