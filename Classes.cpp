#include <bits/stdc++.h>
using namespace std;

class baseclass{
public:
    void printbase() {
        cout << "print base" << endl;
    }
    
    baseclass& operator=(const baseclass& b){
        cout << "copy assignment operator= called" << endl;
        return *this;
    }

    baseclass& operator+(const baseclass& b){
        cout << "copy assignment operator+ called" << endl;
        return *this;
    }
};

class baseclass2{
public:
    void printbase() {
        cout << "print base2" << endl;
    }
};

class derived : public baseclass, public baseclass2{
public:
    void printbase() {
        cout << "print derived" << endl;
    }
};

int main(){

    baseclass bcs1, bcs2;
    bcs1 = bcs1 + bcs2;

    // baseclass *node = new derived();
    // node->printbase();
    // baseclass2 *node2 = new derived();
    // node2->printbase();
    // derived *node3 = new derived();
    // node3->baseclass::printbase();
    // node3->baseclass2::printbase();
    // node3->printbase();

    return 0;
}