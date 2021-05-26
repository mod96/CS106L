#include <iostream>
#include <sstream>

using namespace std;

/*
cin : buffered (automatically adds \n)
|_ There are 3 reason why >> with cin is a nightmare.
1. cin reads the entire line into the buffer but gives you whitespace-seperated tokens.
2. Trash in the buffer will make cin not prompt the user for input at the right time.
3. When cin fails, all future cin operations fail too.
*/

int main(){
    cout << "What is your name? ";
    string name;
    cin >> name;

    cout << "What is your age? ";
    int age;
    cin >> age;

    cout << "Where are you from? ";
    string home;
    cin >> home;

    cout << "Hello " << name << "(age " << age << " from " << home << ")" << endl;

    return 0;
}

/*
If we type in "Avery Wang", it goes wrong.
if we change 'int age' -> 'string age', age becomes "Wang"
*/