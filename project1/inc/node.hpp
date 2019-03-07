#pragma once

template<class Type>
class Node
{
public:
    Node* next;
    Node* previous;
    Type value;
};
