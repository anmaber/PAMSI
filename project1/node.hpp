#pragma once

template<class Type>
class Node
{
public:
    Node(const Type v);
    Node* next;
    Node* previous;
    Type value;

    ~Node();
};

template<class Type>
Node<Type>::Node(const Type v)
     :next(nullptr),
      previous(nullptr),
      value(v)
{}

template<class Type>
Node<Type>::~Node()
{}
