#include "stringvector.h"
#include <iostream>

using namespace std;

StringVector readNames(size_t size);

int main(){
    StringVector name1 = readNames(54);
    StringVector name2;
    name2 = readNames(43);
}

StringVector readNames(size_t size){
    StringVector names(size, "Ito");
    return names;
}