size_t StringVector::size() const{
    return logicalSize;
}

bool StringVector::empty() const{
    return (bool)logicalSize;
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

std::string& StringVector::operator[](size_t index){
    return *(begin() + index);
}

const std::string& StringVector::operator[](size_t index) const{
    return *(begin() + index);
}

std::string& StringVector::at(size_t index){
    return const_cast<std::string&>(static_cast<const StringVector*>(this)->at(index));
}

const std::string& StringVector::at(size_t index) const{
    if (index >= size()){
        throw std::out_of_range("Out of bounds access of vector");
    }
    return *(begin() + index);
}

void StringVector::grow(){
    std::string* new_elems = new std::string[2*allocatedSize];
    std::copy(begin(),end(),new_elems);
    delete[] elems;
    allocatedSize *= 2;
}

std::ostream& operator<<(std::ostream& os, const StringVector& vec){
    os << "{";
    for (auto i = vec.begin(); i != vec.end(); i++){
        os << *i << " ";
    }
    os << "}";
    return os;
}