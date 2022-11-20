#include "stringvector_re.h"

// default constructor
StringVector::StringVector()
// initialization list
 : logicalSize(0), allocatedSize(kInitialSize) {  // ":" makes them "const"
    elems = new std::string[allocatedSize];
    std::cout << "Hello from Default Constructor" << std::endl;
}

// fill constructor
StringVector::StringVector(size_t n, const std::string &val)
 : logicalSize(n), allocatedSize(2*n) {
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), val);
    std::cout << "Hello from Fill Constructor" << std::endl;
}

// copy constructor
StringVector::StringVector(const StringVector& other)
 : logicalSize(other.logicalSize), allocatedSize(other.allocatedSize){
     if (this != &other){
         elems = new std::string[allocatedSize];
         std::copy(other.begin(), other.end(), begin());
     }
     std::cout << "Hello from Copy Constructor" << std::endl;
 }

 StringVector::StringVector(StringVector&& other)
  : elems(std::move(other.elems)), logicalSize(std::move(other.logicalSize)),
    allocatedSize(std::move(other.allocatedSize)){
    std::cout << "Hello from the move consturctor!" << std::endl;
    other.elems = nullptr;
 }

//copy assignment
StringVector& StringVector::operator=(const StringVector &other){
    if (this != &other){
        delete[] elems;
        allocatedSize = other.allocatedSize;
        logicalSize = other.logicalSize;
        elems = new std::string[allocatedSize];
        std::copy(other.begin(),other.end(),begin());
    }
    std::cout << "Hello from Copy Assignment" << std::endl;
    return *this;
}

// destructor
StringVector::~StringVector(){
     delete[] elems;
     std::cout << "Destructor" << std::endl;
}






size_t StringVector::size() const{
    return logicalSize;
}

std::string* StringVector::begin(){
    return elems;
}

const std::string* StringVector::begin() const{
    return elems;
}

std::string* StringVector::end(){
    return elems + size();
}

const std::string* StringVector::end() const{
    return elems + size();
}

std::ostream& operator<<(std::ostream& os, const StringVector& vec){
    os << "{";
    for (auto i = vec.begin(); i != vec.end(); i++){
        os << *i << " ";
    }
    os << "}";
    return os;
}