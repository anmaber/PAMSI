#include "list.hpp"

int main()
{
    List<int> list;
    list.push_back(4);

    list.display();
    list.push_front(1);

    List<int>::Iterator it;
    List<int>::ConstIterator cit;
    it=list.begin();
    cit=it;
    //*it=49;
    std::cout<<"pod iteratorem:"<<*it<<std::endl;

    it++;
    std::cout<<"pod iteratorem:"<<*it<<std::endl;
    //*it=7;
std::cout<<"pod iteratorem:"<<*it<<std::endl;
    list.display();
    list.push_back(3);
    //list.insert(9,4);
    list.display();
    //list[1]=9;
    //list[3]=1;
   // list.display();
    //fix segmentation fault when use [] more then once

    std::cout<<list[2];

    return 0;
}
