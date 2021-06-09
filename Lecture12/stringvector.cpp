// default constructor
StringVector::StringVector()
// initialization list
 : logicalSize(0), allocatedSize(kInitialSize) {  // ":" makes them "const"
    elems = new std::string[allocatedSize];
}

// fill constructor
StringVector::StringVector(size_t n, const std::string &val)
 : logicalSize(n), allocatedSize(2*n) {
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), val);
}

// copy constructor
StringVector::StringVector(const StringVector& other)
 : logicalSize(other.logicalSize), allocatedSize(other.allocatedSize){
     if (this != &other){
         elems = new std::string[allocatedSize];
         std::copy(other.begin(), other.end(), begin());
     }
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
     return *this;
 }


// destructor
StringVector::~StringVector(){
     delete[] elems;
}

std::string* StringVector::insert(std::string* pos, const std::string& elem){
    size_t index = static_cast<size_t>(pos-begin());
    if (size() == allocatedSize){
        grow();
    }
    pos = begin()+index;
    std::copy_backward(pos, end(), end()+1);
    *pos = elem;
    logicalSize++;
    return pos;
}

void StringVector::push_back(const std::string& elem){
    insert(end(),elem);
}

StringVector& StringVector::operator+=(const StringVector& other){
    for (auto it = other.begin(); it != other.end(); it++){
        push_back(*it);
    }
    return *this;
}

StringVector& StringVector::operator+=(const std::string& rhs){
    push_back(rhs);
    return *this;
}

StringVector StringVector::operator+(const StringVector& other) const {
    StringVector result = *this;
    for (const std::string& s : other){
        result += s;
    }
    return result;
}
/*
StringVector operator+(const StringVector& lhs, const StringVector& rhs){
    StringVector result = lhs;
    for (const std::string& s : rhs){
        result += s;
    }
    return result;
}*/

StringVector operator+(const StringVector& lhs, const std::string& rhs){
    StringVector result = lhs;
    result.push_back(rhs);
    return result;
}
