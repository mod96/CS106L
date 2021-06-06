Fraction::Fraction(){
    num = 1;
    denom = 1;
}

Fraction::Fraction(int num, int denom){
    this->num = num;
    this->denom = denom;
    reduce();
}

int Fraction::getNum(){
    return num;
}

int Fraction::getDenom(){
    return denom;
}

void Fraction::add(const Fraction &other){
    int new_num = num * other.denom + other.num * denom;
    int new_denom = denom * other.denom;

    num = new_num;
    denom = new_denom;

    reduce();
}

void Fraction::mult(const Fraction& other){
    num *= other.num;
    denom *= other.denom;

    reduce();
}

void Fraction::reduce(){
    int frac_gcd = gcd(num, denom);
    num /= frac_gcd;
    denom /= frac_gcd;
}

int Fraction::gcd(int u, int v){
    if (v != 0){
        return gcd(v, u%v);
    } else return u;
}

std::ostream& operator<<(std::ostream &os, const Fraction &f){
    os << f.num << "/" << f.denom;
    return os;
}

Fraction Fraction::operator+(const Fraction &other){
    int new_num = num*other.denom + other.num*denom;
    int new_denom = denom*other.denom;
    int temp = gcd(new_num, new_denom);
    new_num = new_num/temp;
    new_denom = new_denom/temp;
    Fraction res{new_num, new_denom};
    return res;
}