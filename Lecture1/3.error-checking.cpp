#include <sstream>
#include <iostream>

using namespace std;

int stringToInteger(const string& str){
    istringstream iss(str);
    int result;
    iss >> result;  // this must succeed
    if (iss.fail()) throw domain_error("domain error");
    cout << "result : " << result << endl;

    char remain;
    iss >> remain;  // this must fail
    if (!iss.fail()) throw domain_error("domain error");
    cout << "remain : "<< remain << endl;
    return result;
}

int stringToInteger2(const string& str){
    istringstream iss(str);
    int result; char remain;
    if (!(iss >> result) || (iss >> remain)){
        throw domain_error("domain error");
        }
    cout << "2 / " << result << " " << remain << endl;

    return result;
}

int main(void){
    string test = "16";
    cout << "test : " << test << endl;
    stringToInteger(test);
    stringToInteger2(test);
    return 0;
}