#include "stack.hpp"

//handle exceptions

int main()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.display();
    stack.pop();
    stack.display();
    stack.pop();
    stack.display();

    return 0;
}
