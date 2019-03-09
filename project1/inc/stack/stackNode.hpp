#pragma once

template <class Type>
class StackNode
{

public:
    StackNode(const Type & v);
    StackNode* next;
    Type value;
};

template<class Type>
StackNode<Type>::StackNode(const Type& v)
    : next(nullptr),
      value(v)
{}
