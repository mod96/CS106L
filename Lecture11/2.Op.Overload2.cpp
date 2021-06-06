// example for "friend"
#include <iostream>
#include "fraction.h"

int main(){
    Fraction me{7, 16};
    Fraction you{1,2};
    Fraction res = me + you;
    std::cout << res << std::endl;

    return 0;
}

/*
****member vs non-member****
1. Some operators must be implemented as members ([], (), ->, =) due to C++semantics.
2. Some must be implemented as non-members(eg. <<) if you are writing class for rhs, nor lhs.
3. If unary operator(eg. ++), implement as member.
4. If binary operator and treats both operands equally(eg. both unchanged) implement as non-member(maybe friend) eg. + <
5. If binary operator and not both equally (changes lhs), implement as member (allows easy access to lhs private members). eg. +=

POLA : Principle of Least Astonishment
*/