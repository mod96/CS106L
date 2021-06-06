class Fraction{
public:
    Fraction();
    Fraction(int num, int denom);

    void add(const Fraction& f);
    void mult(const Fraction& f);
    int getNum();
    int getDenom();
    Fraction operator+(const Fraction &f);

private:
    int num;
    int denom;
    void reduce();
    int gcd(int u, int v);

    friend std::ostream& operator<<(std::ostream &os, const Fraction &f);
};

#include "fraction.cpp"