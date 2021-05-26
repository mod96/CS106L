#include <sstream>
#include <iostream>
using namespace std;
/*
When should i use a sstream?
1. Processing strings
    |_ Simplify "/./a/b/.." to "/a"
2. Formatting input/output
    |_ uppercase, hex, and other stream manipulators
3. Parsing different types
    |_stringTointeger() from previous lecctures
*/
int main(){
    ostringstream oss("What the hell");
    /*
    does not matter how this initially allocates memory
    it just takes string and turns into some kind of stream (or class)
    */
    cout << oss.str() << endl;  // when using stream, need .str() to print
    oss << 16.9 << " Ounce ";
    cout << oss.str() << endl;

    ostringstream oss2("What the hell", stringstream::ate);
    oss2 << 16.9 << " Ounce";
    cout << oss2.str() << endl;

    istringstream iss(oss.str());
    /*
    use this for parsing string
    split by space
    */
    double amount;
    string unit;
    iss >> amount >> unit;
    cout << amount << unit << iss.str() << endl;

    return 0;
}