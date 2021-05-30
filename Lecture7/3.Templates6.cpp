#include <iostream>
#include <vector>
using namespace std;

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
    int num_times_called = 0;
    auto func = [val, &num_times_called](auto v){  // Actually...."std::bind" can do this too.
        num_times_called++;
        return v < val;
    };
    auto count = countOccurences(vec.begin(), vec.end(), func);
    cout << "values less than val in vec : " << count << endl;
    cout << "numbers LAMBDA FUNCTION called : " << num_times_called << endl;
    return 0;
}

/*
So..after C++17, "LAMBDA FUNCTION" works and is really effective. 
***ONLY POSSIBLE TYPE IS AUTO.***

---ANATOMY OF A LAMBDA FUNCTION---
auto func = [capture-clause](parameters){
    //body
};

---EXAMPLES---
//capture all vy value, except teas is by reference
auto func1 = [=, &teas](parameters) -> return_type{
    ...
};

//capture all vy value, except banned is by value
auto func2 = [&, banned](parameters) -> return_type{
    ...
};

---FORMS---
[x](arguments) // captures x from surrounding scope by value
[&x](arguments) // captures x from surrounding scope by reference
[x, y](arguments) // captures x, y by value
[&](arguments) // captures everything by reference
[&, x](arguments) // captures everything except x by reference
[=](arguments) // captures everything by copy
*/