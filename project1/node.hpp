#pragma once

template<class Type>
class Node
{
public:
    Node* next;
    Node* previous;
    Type value;
    ~Node();
};

template<class Type>
Node<Type>::~Node()
{
    delete next;
    delete previous;
}
