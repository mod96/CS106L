/*
There are over 60 operators and can overload about 40(+4) operators.
Operators contains:
+ - * += == != << >> && , [] () <- ->

for example,
==============================================
vector<string> v{"Hello", "World"};
cout << v[0];
v[1] += "!";
==============================================
is the same as:
==============================================
vector<string> v{"Hello", "World"};
cout.operator<<(v.operator[](0));
v.operator[](1).operator+=("!");
==============================================
is the same as:
==============================================
vector<string> v{"Hello", "World"};
operator<<(ccout, v.operator[](0));
v.operator[](1).operator+=("!");
==============================================
*/
#include "StringVector.h"
#include <iostream>


int main(){
    StringVector vec;

    (vec += "Ito-En") += "16.9";

    vec.push_back("Hello");
    vec.push_back("World");

    auto temp = vec.get_vec();
    for (const std::string &s : temp){
        std::cout << s << std::endl;
    }

    StringVector vec1, vec2, vec3;
    vec1 += "Hello";
    vec2 += "World";
    vec3 = vec1 + vec2;

    temp = vec3.get_vec();
    for (const std::string &s : temp){
        std::cout << s << std::endl;
    }


    return 0;
}