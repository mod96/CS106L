#include <iostream>
#include <sstream>
using namespace std;

template <typename T>
T get_Type(){
    while (true){
        cout << "Enter a " << typeid(T).name() << " : ";
        string line; T res; char extra;
        if (!getline(cin, line)) throw domain_error("Unable to get line from cin.");
        istringstream iss(line);
        if (iss >> res && !(iss >> extra)) return res;
        cout << "Invalid format." << endl;
    }
}

int main(){
    int val1 = get_Type<int>();
    double val2 = get_Type<double>();
    cout << "val1 is : " << val1 << endl;
    cout << "val2 is : " <<  val2 << endl;

    return 0;
}