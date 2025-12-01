#include <iostream>

using namespace std;

class Example {
public:
    Example(double real, double imag) : real_(real), imag_(imag) {}

    // Overloaded + operator (member function)
    Example operator+(const Example& other) const {
        return Example(real_ + other.real_, imag_ + other.imag_);
    }

    Example operator+(const double& val) const {
        return Example(real_ + val, imag_);
    }

    // Function to print a Example number
    void print() const {
        std::cout << real_;
        if (imag_ >= 0) {
            std::cout << " + " << imag_ << "i";
        } else {
            std::cout << " - " << -imag_ << "i";
        }
        std::cout << std::endl;
    }

private:
    double real_;
    double imag_;
};

// Function template with a trailing return type
template <typename T, typename U>
auto addExampleThings(T a, U b) -> decltype(a + b) {
    return a + b; 
}

//can i print output of decltype
template <typename T, typename U>
void printDecltype(T a, U b){
    cout << typeid(decltype(a+b)).name() << endl;
}


int main() {
    Example c1(2.5, 3.1);
    Example c2(1.7, -2.8);

    // Use the overloaded + operator
    Example c3 = c1 + c2; 

    // Use the function template with trailing return type
    auto c4 = addExampleThings(c1, c2);

    std::cout << "c1: ";
    c1.print();
    std::cout << "c2: ";
    c2.print();
    std::cout << "c3 (c1 + c2): ";
    c3.print();
    std::cout << "c4 (addExampleThings(c1, c2)): ";
    c4.print();

    cout << typeid(decltype(1.0)).name() << endl;
    return 0;
}
