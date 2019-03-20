#include "stack.hpp"
#include <stack>
#include <algorithm>


int main()
{
    /* MY STACK */

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
        /*
        std::cout<<"popping: "<<stack.pop()<<std::endl;
        std::cout<<"after popping: ";
        stack.display();*/
    }
    catch(std::out_of_range const& ex)
    {
        std::cerr<<"out_of_range: "<<ex.what()<<std::endl;
    }

    /* STL STACK */

    std::stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout<<"STL: \n";
    std::cout<<stack.top()<<"\t";
    stack.pop();

    std::cout<<stack.top()<<"\t";
    stack.pop();

    std::cout<<stack.top()<<std::endl;
    stack.pop();




    return 0;
}
