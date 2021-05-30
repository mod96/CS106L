#include <string>
#include <cassert>
#include <iostream>
using namespace std;

struct RetVal 
{
    int a;
    string b;
};

RetVal doSomething()
{
    //do something useful
    return {10, "Value"};
}

int main()
{
    auto [x, y] = doSomething();
    assert(x == 10);
    assert(y == "Value");
    cout << x << y << endl;
    
    return 0;
}