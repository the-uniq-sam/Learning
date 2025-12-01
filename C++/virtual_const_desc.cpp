#include <bits/stdc++.h>
using namespace std;

class Base {
public:
    virtual const int& getVal() const {
        return val;
    }

protected:
    int val;
};

class Derived : public Base {
public:
    Derived(int val) : val(val) {}

    virtual const int& getVal() const override {
        cout << "calling from derived ";
        return val;
    }

private:
    int val;
};

int main() {
    Derived d(10);
    Base& b = d;

    cout << b.getVal() << endl; // Output: calling from derived 10

    return 0;
}