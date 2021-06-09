#define kInitialSize 10
#include <string>
#include <iostream>

class StringVector{
public:
    StringVector();
    StringVector(size_t n, const std::string &val);
    StringVector(const StringVector& other);
    ~StringVector();
    StringVector& operator=(const StringVector &other);

    size_t size() const;

    std::string* begin();
    const std::string* begin() const;
    std::string* end();
    const std::string* end() const;

private:
    void grow();
    std::string* elems;
    size_t logicalSize;
    size_t allocatedSize;
};

#include "stringvector.cpp"