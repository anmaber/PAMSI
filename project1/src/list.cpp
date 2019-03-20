#include "list.hpp"
#include <list>
#include <memory>
#include <algorithm>
#include <iterator>


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

        for(auto it = list.cbegin(); it!=list.cend(); ++it)
            std::cout<<*it<<"  ";


        std::cout<<"\n\nCHECKS IF [] OPERATOR WORKS \n";
        std::cout<<"list[3] = 0;"<<std::endl;
        list[3] = 0;
        for(auto it = list.cbegin(); it!=list.cend(); ++it)
            std::cout<<*it<<"  ";

        std::cout<<"\nlist[1] = "<<list[1]<<std::endl;

        std::cout<<"\n\nCHECKS IF REMOVE METHOD WORKS \n";
        list.remove(2);
        for(auto it = list.cbegin(); it!=list.cend(); ++it)
            std::cout<<*it<<"  ";


        std::cout<<"\n\nCHECKS IF ITERATOR WORKS (TO EACH ELEMENT OF COLLECTION SHOULD BE ADDED 2) \n";
        for(auto it =list.begin() ; it != list.end(); ++it)
            *it+=2;


        for(auto it = list.cbegin(); it!=list.cend(); ++it)
            std::cout<<*it<<"  ";

    }
    catch(std::out_of_range const& ex)
    {
        std::cerr<<"out_of_range: "<<ex.what()<<std::endl;
    }

    /****** STL *****/

    std::list<int> list;
    list.push_back(4);
    list.push_back(3);
    list.push_front(1);
    list.push_front(2);
    auto it = list.begin();
    std::advance(it,2);
    list.insert(it,9);

    std::cout<<"\n\nCHECKS HOW INSERT METHODS IN STL WORK \n \n";
    std::cout<<"output should be: 2 1 9 4 3 \n";
    std::cout<<"real output: ";

    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<"\n\nCHECKS HOW ITERATOR WORKS (TO EACH ELEMENT OF COLLECTION SHOULD BE ADDED 2) \n";

    for(auto it =list.begin() ; it != list.end(); ++it)
        *it+=2;

    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout<<"\n\nCHECKS HOE REMOVE METHOD WORKS \n";
    list.remove(4);
    std::copy(list.begin(), list.end(), std::ostream_iterator<int>(std::cout, " "));


    return 0;
}
