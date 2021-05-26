#include <iostream>
#include <sstream>

using namespace std;

int getInteger(const string& prompt = "Enter an integer : ", 
                const string& reprompt = "Illegal numeric format. Try again.\n");
int main(){
    cout << "What is your name? ";
    string name;
    getline(cin, name); // this consumes /n

    cout << "What is your age? ";
    int age;
    age = getInteger();

    cout << "Where are you from? ";
    string home;
    getline(cin, home);

    cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;

    return 0;
}

int getInteger(const string& prompt, const string& reprompt){
    while(true){
        cout << prompt;
        string line;
        if (!getline(cin, line)) throw domain_error("getInteger function error : line must be provided");

        stringstream iss(line);
        int val; char remain;
        if ((iss >> val) && !(iss >> remain)) return val;
        cout << reprompt << endl;
    }
}
