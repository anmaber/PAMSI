#pragma once

#include "node.hpp"
#include <iostream>
#include <stdexcept>
#include <type_traits>

template<class Type>
class List
{

    Node<Type>* head;
    Node<Type>* tail;
    int size;

public:

    template<bool isConst>
    class MyIterator;

    using Iterator = MyIterator<false>;
    using ConstIterator = MyIterator<true>;

    List();
    ~List();
    void insert(const Type& newElement, int index);
    void push_back(const Type& newElement);
    void push_front(const Type& newElement);
    Node<Type>* find(const Type& element) const;
    void remove(const Type& element);
    Type& operator [] (int index);

    Iterator begin();
    Iterator end();
    ConstIterator cbegin() const;
    ConstIterator cend() const;


    template<bool isConst = false>
    struct MyIterator
    {

        Node<Type>* current;
        /*
        using iterator_category = std::forward_iterator_tag;
        using value_type = Type;
        using difference_type = std::ptrdiff_t;
        */
        using reference = typename std::conditional_t< isConst, Type const &, Type & >;
        // using pointer = typename std::conditional_t< isConst, Type const *, Type * >;
        MyIterator() :
            current (nullptr) {}

        MyIterator(Node<Type>* node):
            current(node) {}

        MyIterator& operator = (const MyIterator& i) = default;


        template<bool wasConst, class = std::enable_if_t<isConst && !wasConst>>
        MyIterator& operator = (const MyIterator<wasConst>& rhs)
        {
            current = rhs.current;
            return *this;
        }


        MyIterator& operator ++()
        {
            if (current) current = current->next;
            return *this;
        }

        MyIterator operator ++(int)
        {
            MyIterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator != ( MyIterator const & _other ) const
        {
            return current != _other.current;
        }

        bool operator == ( MyIterator const & _other ) const
        {
            return !( *this != _other );
        }

        template< bool _isConst = isConst >
        std::enable_if_t< _isConst, reference >
        operator*() const
        {
            return current->value;
        }

        template< bool _isConst = isConst >
        std::enable_if_t< !_isConst, reference >
        operator*()
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
void List<Type>::insert(const Type &newElement, int index)
{
    if(index > size || index < 0) throw std::out_of_range("You want to get access to element that is out of range");
    else if(index == 0) push_front(newElement);
    else if(index == size) push_back(newElement);
    else
    {
        Node<Type>* node = new Node<Type>(newElement);
        Node<Type>* current = head;
        for(int i=0; i<index-1; ++i)
            current=current->next;

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
    if(index >= size || index < 0) throw std::out_of_range("You want to get access to element that is out of range");
    else
    {
        Node<Type>* current = head;
        for(int i = 0; i < index; ++i)
            current=current->next;

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

template<class Type>
typename List<Type>::ConstIterator List<Type>::cbegin() const
{
    return ConstIterator(head);
}

template<class Type>
typename List<Type>::ConstIterator List<Type>::cend() const
{
    return ConstIterator(tail->next);
}
