#pragma once

template<class Type>
class PriorityQueueNode{

public:
    PriorityQueueNode(const Type& v, int p);
    PriorityQueueNode<Type>* next;
    PriorityQueueNode<Type>* previous;
    int priority;
    Type value;

};

template<class Type>
PriorityQueueNode<Type>::PriorityQueueNode(const Type& v, int p)
    : next(nullptr),
      previous(nullptr),
      priority(p),
      value(v)
{}
