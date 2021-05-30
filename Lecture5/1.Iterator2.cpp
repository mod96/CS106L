#include <iostream>
#include <set>
using namespace std;


int numOccurrences (set<int>& cont, int elt){  // If we use template function, we only need to write this once for use of any types
    int count = 0;
    set<int>::iterator iter;
    for(iter = cont.begin(); iter != cont.end(); ++iter){
        if (*iter == elt){
            ++count;
        }
        //cout << *iter << " ";
    }
    return count;
}

int main(){
    set<int> s = {7,6,5,4,3,4,3,4}; // obviously it must be 1
    int count;
    count = numOccurrences(s, 3);
    cout << count << endl;
    return 0;
}