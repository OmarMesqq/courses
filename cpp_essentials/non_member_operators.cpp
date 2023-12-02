#include <format> 
#include <iostream>
#include <string> 


// Member vs non member operators:

// Implementation
class Rational {
    int numerator {0};
    int denominator {1};
public:
    // default constructor
    Rational(int n = 0, int d = 1): numerator(n), denominator(d) {}
    // copy constructor
    Rational(const Rational& rhs): numerator(rhs.numerator), denominator(rhs.denominator) {}
    ~Rational(); 

    int getNumerator() const {return numerator;}
    int getDenominator() const {return denominator;}

    Rational reduce() const;

    std::string str() const;
    std::string raw_str() const;

    Rational& operator = (const Rational&);
};

int gcd(int n, int d) {
    if (n / d == 0) return n;
    return gcd( n % d, d);
}

// Interface
Rational::~Rational() {
    // std::cout << "Destructor called!\n";
}


Rational Rational::reduce() const {
  Rational reducedRational;
    int _gcd = gcd(numerator, denominator);
    reducedRational.numerator = numerator / _gcd;
    reducedRational.denominator = denominator / _gcd;

    return reducedRational;
};

std::string Rational::str() const {
    return std::format("{}/{}", numerator, denominator);
}

// One argument: right hand side of = operator
// It is a reference (an alias to the actual object)
// Inside the function we get its address with &
// The left hand side of the assignment is the object on which the operator is called
Rational& Rational::operator = (const Rational& rhs) {
    if (this != &rhs) {
        this->numerator = rhs.numerator; 
        this->denominator = rhs.denominator;
    }
    return *this;
};

Rational operator + (const Rational& lhs, const Rational& rhs)  {
    return Rational(
        lhs.getNumerator() * rhs.getDenominator() + rhs.getNumerator() * lhs.getDenominator(),
        lhs.getDenominator() * rhs.getDenominator()
    );
};

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.getNumerator() * rhs.getDenominator() - rhs.getNumerator() * lhs.getDenominator(),
        lhs.getDenominator() * rhs.getDenominator()
    );
}


Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.getNumerator() * rhs.getNumerator(),
        lhs.getDenominator() * rhs.getDenominator()
    );
};

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return Rational(
        lhs.getNumerator() * rhs.getDenominator(),
        lhs.getDenominator() * rhs.getNumerator()
    );
};



int main() {
    Rational a {4,3}; 
    // std::cout << std::format("20 - {} = {}", a.str(), (20 - a).str()) <<  std::endl;

    Rational b {1,2}; 
    Rational c {3,7}; 

    std::cout << std::format("{} + {} = {}", b.str(), c.str(), (b + c).str()) <<  std::endl;
    std::cout << std::format("{} - {} = {}", b.str(), c.str(), (b - c).str()) <<  std::endl;
    std::cout << std::format("{} * {} = {}", b.str(), c.str(), (b * c).str()) <<  std::endl;
    std::cout << std::format("{} / {} = {}", b.str(), c.str(), (b / c).str()) <<  std::endl;

    return 0;
}