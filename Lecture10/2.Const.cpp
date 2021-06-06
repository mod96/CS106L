#include <vector>
#include <iostream>
using std::vector; using std::cout;
using std::endl;

void print_size(const vector<int>& vec) {
    cout << vec.size() << endl;
}

int main(){
    vector<int> a{1,2,3};
    print_size(a);

    return 0;
}

/*
//constant pointer to a non-constant int
int *const p;

//non-constant pointer to a constant int
const int *p;
int const *p;

//constant pointer to a constant int
const int *const p;
int const *const p;
*/
