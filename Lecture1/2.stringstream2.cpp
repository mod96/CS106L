#include <sstream>
#include <iostream>

using namespace std;

int main(){
    ostringstream oss("Ito En Green Tea");
    oss << 16.9;
    fpos<_Mbstatet> pos = oss.tellp() + streamoff(3);
    /*
    fpos = position : index 4 + 3 (add an offset = streamoff)
    */
    oss.seekp(pos);
    oss << "Black";
    cout << oss.str() << endl;

    return 0;
}