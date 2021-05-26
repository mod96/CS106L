/*
Iterators make every containers iterable in cpp

container.begin() returns iterator type

iterator is like pointer. we need to dereference it to print the value

but, this goes wrong
list<int> L(10);
auto iter = L.begin() + 3;
|_this works for vector, ...
|_https://www.geeksforgeeks.org/output-iterators-cpp/
*/
#include <iostream>
#include <set>

int main(){
    // set is ordered
    std::set<int> container;
    for (int i=10; i>0; i--){
        container.insert(i);
    }

    // Method 1
    std::set<int>::iterator itr = container.begin();
    while (itr != container.end()){
        std::cout << *itr << ' ';
        ++itr;
    }
    std::cout << std::endl;

    // Method 2
    std::set<int>::iterator itr2;
    for (itr2 = container.begin(); itr2 != container.end(); ++itr2){
        std::cout << *itr2 << ' ';
    }
    std::cout << std::endl;

}