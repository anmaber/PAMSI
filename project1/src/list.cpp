#include "list.hpp"

int main()
{
    List<int> list;
    list.push_back(4);
    list.push_front(1);
    list.push_back(3);

    List<int>::Iterator it,it2;

    it=list.begin();
    it2=list.end();
   std::cout<<"1: "<<*it<<std::endl;
   ++it;
   std::cout<<"4: "<<*it<<std::endl;
   ++it;
   std::cout<<"3: "<<*it<<std::endl;



   for(List<int>::Iterator it =list.begin();it!=list.end();++it)
   {
       *it+=2;
   }
   for(List<int>::ConstIterator it =list.cbegin();it!=list.cend();++it)
   {
       std::cout<<*it<<"\t";
   }



    //*it=49;
    //std::cout<<"pod iteratorem:"<<*it<<std::endl;

    //it++;
    //std::cout<<"pod iteratorem:"<<*it<<std::endl;
    //*it=7;
//std::cout<<"pod iteratorem:"<<*it<<std::endl;
    //list.display();
    //list.push_back(3);
    //list.insert(9,4);
    //list.display();
    //list[1]=9;
    //list[3]=1;
   // list.display();
    //fix segmentation fault when use [] more then once

    //std::cout<<list[2];

    return 0;
}
