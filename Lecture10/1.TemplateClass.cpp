#include <iostream>
#include <vector>

#include "vector.h"
/*
So, #include "vector.h" is the same as
==================================
#include <vector>

template <typename T>
class vector{
    public:
        std::vector<T> val{1,2,3,4,5};
        int at(int i);
};

#include "vector.cpp"
==================================
and remember : templates don’t emit any code until instantiated
*/

int main(){
    vector<int> vec;
    std::cout << vec.at(1) << std::endl;
}