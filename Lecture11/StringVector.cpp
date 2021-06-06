void StringVector::push_back(const std::string elt){
    vec.push_back(elt);
}

StringVector& StringVector::operator+=(const std::string elt){
    push_back(elt);
    return *this;
}

std::vector<std::string>& StringVector::get_vec(){
    return vec;
}


//note that this is not the member function of StringVector
StringVector operator+(StringVector& vec1, StringVector& vec2){
    StringVector result = vec1;
    auto temp = vec2.get_vec();
    for (const std::string &elt : temp){
        result.push_back(elt);
    }
    return result;
}