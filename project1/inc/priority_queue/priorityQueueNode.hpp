#pragma once

template<class Type>
class PriorityQueueNode{

public:
    PriorityQueueNode(const Type& v);
    PriorityQueueNode<Type>* next;
    int priority;
    Type value;

};

template<class Type>
PriorityQueueNode<Type>::PriorityQueueNode(const Type& v)
    : next(nullptr),
      priority(0),
      value(v)
{}
