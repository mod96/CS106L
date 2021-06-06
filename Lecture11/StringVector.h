#include <string>
#include <vector>

class StringVector{
    public:
        StringVector& operator+=(const std::string elt);
        void push_back(const std::string elt);
        std::vector<std::string>& get_vec();
    private:
        std::vector<std::string> vec;
};

#include "StringVector.cpp"