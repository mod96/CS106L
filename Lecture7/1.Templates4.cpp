#include <iostream>
#include <vector>
using namespace std;

/*  THIS DOESN'T WORK. BECAUSE IF WE WANT TO USE TEMPALTE FOR PREDICATE, IT MUST BE "UNARY DREDICATE"
// To do this, we need to use "LAMBDA FUNCTION" or, before c++11, "FUNCTORS"
template <typename T>
bool is_less_than(T val1, T val2){
    return true;
}*/
// THIS WOKRS BECAUSE IT DIDN'T USED PREDICATE
bool is_less_than(int val, int val2){
    return val < val2;
}

template <typename Iter, typename T, typename P> // P for predicate
int countOccurences(Iter begin, Iter end, T val, P predicate){
    int count = 0;
    for (auto iter = begin; iter != end; iter++){
        if (predicate(*iter, val)) count++;
    }
    return count;
}

int main(){
    vector<int> vec = {1,2,3,4,5,5,6,7,8}; int val = 5;
    auto count = countOccurences(vec.begin(), vec.end(), val, is_less_than);
    cout << "values less than val in vec : " << count << endl;
    
    return 0;
}