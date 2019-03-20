#include "stack.hpp"

int main()
{
    try{
        Stack<int> stack;
        stack.push(1);
        stack.push(2);
        stack.push(3);
        std::cout<<"stack: ";
        stack.display();
        std::cout<<"popping: "<<stack.pop()<<std::endl;
        std::cout<<"after popping: ";
        stack.display();
        std::cout<<"popping: "<<stack.pop()<<std::endl;
        std::cout<<"after popping: ";
        stack.display();
        std::cout<<"popping: "<<stack.pop()<<std::endl;
        std::cout<<"after popping: ";
        stack.display();
        std::cout<<"popping: "<<stack.pop()<<std::endl;
        std::cout<<"after popping: ";
        stack.display();
    }
    catch(std::out_of_range const& ex)
    {
        std::cerr<<"out_of_range: "<<ex.what()<<std::endl;
    }

    return 0;
}
