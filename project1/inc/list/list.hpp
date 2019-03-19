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

    class Iterator;
    List();
    ~List();
    void display() const;
    void insert(const Type& newElement, int index);
    void push_back(const Type& newElement);
    void push_front(const Type& newElement);
    Node<Type>* find(const Type& element) const;
    void remove(const Type& element);
    Type& operator [] (int index);
    Iterator begin();
    Iterator end();

    class Iterator
    {

        Node<Type>* current;

    public:
        Iterator() :
            current (nullptr) {}

        Iterator(Node<Type>* node):
            current(node) {}

        Iterator& operator=(Node<Type>* node)
        {
            this->current = node;
            return *this;
        }

        Iterator& operator++()
        {
            if (current) current = current->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        int operator*()
        {
            return current->value;
        }

    };
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
void List<Type>::insert(const Type &newElement, int index)
{
    if(index > size) std::cerr<<"out of range \n";
    else if(index == 0) push_front(newElement);
    else if(index == size) push_back(newElement);
    else
    {
        Node<Type>* node = new Node<Type>(newElement);
        Node<Type>* current = head;
        for(int i=0; i<index-1; ++i)
        {
            current=current->next;
        }

        current->next->previous = node;
        node->next = current->next;
        current->next = node;
        node->previous = current;

    }
    size++;
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
            head = head->next;
            delete toRemove;
        }
        else if(toRemove == tail)
        {
            tail->previous->next = nullptr;
            tail = tail->previous;
            delete toRemove;
        }
        else
        {
            toRemove->previous->next = toRemove->next;
            toRemove->next->previous = toRemove->previous;
            delete toRemove;
        }
        size--;
    }
}

template<class Type>
Type& List<Type>::operator [](int index)
{
    if(index >= size || index < 0) std::cerr<<"out of range \n";
    else
    {
        Node<Type>* current = head;
        for(int i = 0; i < index; ++i)
        {
            current=current->next;
        }
        return current->value;
    }



}

template<class Type>
typename List<Type>::Iterator List<Type>::begin()
{
    return Iterator(head);
}

template<class Type>
typename List<Type>::Iterator List<Type>::end()
{
    return Iterator(tail->next);
}



