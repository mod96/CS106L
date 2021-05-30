#include <iostream>
#include <vector>
#include <set>
using namespace std;

template <typename C, typename T>
int countOccurences(C &container, T val){   // NOT C<T> &container
    int count = 0;
    for (auto iter = container.begin(); iter != container.end(); ++iter){
        if (*iter == val) ++count;
    }
    return count;
}
/*  THE MOST GENERIC FORM IS TO USE "ITERATOR"
template <typename InputIt, typename DataType>
int countOccurences(InputIt begin, InputIt end, Datatype val){
    int count = 0;
    for (auto iter = begin; iter != end; ++iter){
        if (*iter == val) ++count;
    }
    return count;
}
*/

int main(){
    vector<int> vec = {1,2,3,4,5,5,6,7,8}; int val = 5;
    auto count = countOccurences(vec, val);
    cout << "val in vec : " << count << endl;
    
    set<int> s = {1,2,3,4,5,5,6,7,8}; int val2 = 5;
    auto count2 = countOccurences(s, val2);
    cout << "val2 in set : " << count2 << endl;
    
    return 0;
}