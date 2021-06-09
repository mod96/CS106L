#define kInitialSize 10
#include <string>
#include <iostream>

class StringVector{
public:
    StringVector();
    StringVector(size_t n, const std::string &val);
    StringVector(const StringVector& other);
    StringVector(const std::string[]);  // TODO
    ~StringVector();
    StringVector& operator=(const StringVector &other);

    size_t size() const;
    bool empty() const;

    std::string* begin();
    const std::string* begin() const;
    std::string* end();
    const std::string* end() const;

    std::string& operator[](size_t index);
    const std::string& operator[](size_t index) const;
    std::string& at(size_t index);
    const std::string& at(size_t index) const;

    std::string* insert(std::string* pos, const std::string& elem);
    void push_back(const std::string& elem);

    StringVector& operator+=(const StringVector& other);
    StringVector& operator+=(const std::string& rhs);

    StringVector operator+(const StringVector& other) const;

    //friend StringVector operator+(const StringVector& lhs, const StringVector& rhs);
    //friend StringVector operator+(const StringVector& lhs, const std::string& rhs);

private:
    void grow();
    std::string* elems;
    size_t logicalSize;
    size_t allocatedSize;
};

#include "stringvector.cpp"
#include "stringvector_basics.cpp"