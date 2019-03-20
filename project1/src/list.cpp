#include "list.hpp"

int main()
{
    /********  MY LIST **********/
    try{
        List<int> list;

        std::cout<<"CHECKS IF INSERT METHODS, CONST ITERATOR WORKS \n \n";
        list.push_back(4);
        list.push_back(3);
        list.push_front(1);
        list.push_front(2);
        list.insert(9,2);
        std::cout<<"output should be: 2 1 9 4 3 \n";
        std::cout<<"real output: ";

        for(List<int>::ConstIterator it = list.cbegin(); it!=list.cend(); ++it)
        {
            std::cout<<*it<<"  ";
        }

        std::cout<<"\n\nCHECKS IF [] OPERATOR WORKS \n";
        std::cout<<"list[3] = 0;"<<std::endl;
        list[3] = 0;
        for(List<int>::ConstIterator it = list.cbegin(); it!=list.cend(); ++it)
        {
            std::cout<<*it<<"  ";
        }
        std::cout<<"\nlist[1] = "<<list[1]<<std::endl;

        std::cout<<"\n\nCHECKS IF REMOVE METHOD WORKS \n";
        list.remove(2);
        for(List<int>::ConstIterator it = list.cbegin(); it!=list.cend(); ++it)
        {
            std::cout<<*it<<"  ";
        }

        std::cout<<"\n\nCHECKS IF ITERATOR WORKS (TO EACH ELEMENT OF COLLECTION SHOULD BE ADDED 2) \n";
        for(List<int>::Iterator it =list.begin() ; it != list.end(); ++it)
        {
            *it+=2;
        }

        for(List<int>::ConstIterator it = list.cbegin(); it!=list.cend(); ++it)
        {
            std::cout<<*it<<"  ";
        }
    }
    catch(std::out_of_range const& ex)
    {
        std::cerr<<"out_of_range: "<<ex.what()<<std::endl;
    }

    /****** STL *****/



    return 0;
}
