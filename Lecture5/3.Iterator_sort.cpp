#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

const int elemToFind = 5;

void printVec(const vector<int> &v){
    for (auto elem : v){
        cout << elem << " ";
    }
    cout << endl;
}

int main(){
    //sorting
    vector<int> vec{3,1,4,1,5,9,2,6,5,3};
    cout << "Before sort" << endl;
    printVec(vec);
    sort(vec.begin(), vec.end());
    cout << "After sort" << endl;
    printVec(vec);

    //finding
    cout << "Finding element " << elemToFind << " ..." << endl;
    auto it = find(vec.begin(), vec.end(), elemToFind);
    if (it == vec.end()) cout << "Not found";
    else cout << "Found element " << *it << endl;

    //
    set<int> mySet{1, 3, 57, 137};
    set<int>::iterator iter = mySet.lower_bound(2); // find larger than 2
    set<int>::iterator end = mySet.upper_bound(57); // find lesser than or equals to 57
    while (iter != end){
        cout << *iter << endl;
        ++iter;
    }
    return 0;
}