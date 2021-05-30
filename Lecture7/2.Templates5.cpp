#include <iostream>
#include <vector>
using namespace std;

// Pre-C++11 solution for Templates3.cpp : functors
class is_less_than{
    private:
        int val;
    public:
        is_less_than(int val) : val(val) {};  // What is this?...
        bool operator() (int v1) {
            return v1 < val;
        }
};

template <typename Iter, typename P> // P for predicate
int countOccurences(Iter begin, Iter end, P predicate){
    int count = 0;
    for (auto iter = begin; iter != end; iter++){
        if (predicate(*iter)) count++;
    }
    return count;
}

int main(){
    vector<int> vec = {1,2,3,4,5,5,6,7,8}; int val = 5;
    is_less_than func(val);
    auto count = countOccurences(vec.begin(), vec.end(), func);
    cout << "values less than val in vec : " << count << endl;
    
    return 0;
}