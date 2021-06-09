#include "stringvector.h"

/*
############  Rule of Three  ############
If you explicitly define (or delete) a copy constructor, copy assignment,
or destructor, you should define (or delete) all three.
*/


StringVector function(StringVector vec0){         // Copy constructor
    /* TODO
    StringVector vec00{"Ito", "En", "Green"};      // Normal(fill) constructor
    */
    StringVector vec1;                            // Default constructor
    std::cout << "vec1 : " << vec1 << std::endl;
    StringVector vec2(4, "fill");                 // fill constructor
    std::cout << "vec2 : " << vec2 << std::endl;
    //StringVector vec3();                          // this is a function...(what?)
    StringVector vec4(vec2);                      // Copy constructor
    std::cout << "vec4 : " << vec4 << std::endl;
    StringVector vec5{};                          // Default constructor
    std::cout << "vec5 : " << vec5 << std::endl;
    StringVector vec6(vec0 + vec4);               // Copy constructor
    std::cout << "vec6 : " << vec6 << std::endl;
    StringVector vec7 = vec4;                     // Copy constructor
    std::cout << "vec7 : " << vec7 << std::endl;
    vec7 = vec2;                                  // |_ we're not assigning...making new vec7
    return vec7;
}

int main(){
    size_t logical = 4;
    std::string arr[] = {"test","tes","te","t"};
    StringVector vec0(logical, "test");
    StringVector st = function(vec0);
    std::cout << vec0 << std::endl;
    std::cout << st << std::endl;
    return 0;
}