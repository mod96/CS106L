#include <iostream>
#include <vector>

using std::vector; 
using std::cout; using std::endl;

//this works for header and usually use this like that.
namespace Lecture{
void print_vec(const vector<int> & v){
    for (auto elt:v){
        cout << elt << endl;
    }
}
}

int main(){
    vector<int> v{1,2,3,4,5,6,7};
    Lecture::print_vec(v);
    /*
    WHY? : So that the compiler knows which class you're defining a function for!
    */
}