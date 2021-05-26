#include <vector>
#include <string>
#include <iostream>

void printVec(const std::vector<std::string>& v);

int main(){
    std::vector<std::string> names;
    names.push_back("Anna");
    names.push_back("Avery");
    printVec(names);

    std::cout << names.at(2) << std::endl;
    return 0;
}

/*
vector<int> v; create an empty vector
vector<int> v(n); create a vector with n copies of zero = vector<int> v(n, 0);
v.push_back(k); Add k to the end of the vector
v.clear(); Clear vector
v.empty; check if the vector is empty
v.at(n) vs v[at]  <- this related to memory?
*/

void printVec(const std::vector<std::string>& v){
    std::cout << "{";
    for(auto elem:v) {
        std::cout << elem << " ";
    }
    std::cout << "}" << std::endl;
}