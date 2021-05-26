#include <iostream>
#include <sstream>

using namespace std;

int main(){
    cout << "What is your name? ";
    string name;
    getline(cin, name); // this consumes /n

    cout << "What is your age? ";
    int age;
    cin >> age;  // this does not consumes /n so we need ignore()
    cin.ignore();

    cout << "Where are you from? ";
    string home;
    getline(cin, home);

    cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;

    return 0;
}

// So we solved the problem for string!