#include <iostream>
using namespace std;
/*
HOW TEMPLATE WORKS:
1.find every line that used templatized function
2.infer datatypes of them for all
3.generate proper functions for every of them
*/

template <typename T>  // when running, actual functions generate
pair<T, T> my_minmax(T a, T b){
    if (a<b) return {a, b};
    else return {b, a};
}

template <typename K>
void printminmax(K min, K max){
    cout << "Min : " << min << endl;
    cout << "Max : " << max << endl;
    cout << endl;
}

int main(){
    auto L = my_minmax(3, -2);  
    // C++17 unpack seems doesn't work in VS. But "cl /std:c++17 lecture6/1.Templates1.cpp" works.
    printminmax(L.first, L.second);

    auto [min2, max2] = my_minmax<double>(8.3, 7.4);
    printminmax<double>(min2, max2);
    
    auto [min3, max3] = my_minmax<std::string>("yes", "no");
    printminmax<std::string>(min3, max3);
    
    return 0;
}