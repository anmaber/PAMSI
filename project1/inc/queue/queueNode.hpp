#pragma once

template<class Type>
class QueueNode{

public:
    QueueNode(const Type& v);
    QueueNode<Type>* next;
    Type value;

};

template<class Type>
QueueNode<Type>::QueueNode(const Type& v)
    : next(nullptr),
      value(v)
{}
