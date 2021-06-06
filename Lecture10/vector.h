#include <vector>

template <typename T>
class vector{
    public:
        std::vector<T> val{1,2,3,4,5};
        int at(int i) const;
};

#include "vector.cpp"
/*
#include "vector.cpp" is the same as
==================================
template <typename T>
int vector<T>::at(int i){
    return vector<T>::val[i];
}
==================================
which resolves the reference of the public function "at".
*/