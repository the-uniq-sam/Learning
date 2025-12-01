/*
The Five Members

Let's break down the five members the Rule of Five addresses:

Destructor (~MyClass())
Cleans up resources when an object of your class goes out of scope or is explicitly deleted.
Essential if your class allocates memory using new or new[].


Copy Constructor (MyClass(const MyClass& other))
Creates a new object as a copy of an existing object.
Crucial for performing a deep copy when resource ownership is involved (e.g., allocating new memory and copying the contents).

Copy Assignment Operator (MyClass& operator=(const MyClass& other))
Assigns the value of one existing object to another existing object.
Similar to the copy constructor, it needs to handle deep copying to avoid resource conflicts.

Move Constructor (MyClass(MyClass&& other))
Creates a new object by transferring resources from an expiring object (an rvalue reference, denoted by &&).
Optimizes resource handling by "stealing" resources instead of making copies.

Move Assignment Operator (MyClass& operator=(MyClass&& other))
Similar to the move constructor, it transfers resources from an expiring object to an existing object.
Also optimizes resource management in assignment operations.
*/

#include <bits/stdc++.h>
using namespace std;

class Myclass{

    int val;

public:
    //constructor
    Myclass(int value) : val(value){
        cout << "constructor called " << val << endl;
    }

    //Copy Constructor
    Myclass(const Myclass& other){
        cout << "copy constructor called " << other.val << endl;
        val = other.val;
    }

    //Move constructor
    Myclass(Myclass&& other){
        cout << "move constructor called " << other.val << endl;
        val = other.val;
        other.val = 0;
    }

    //copy assignment operator
    Myclass& operator=(const Myclass& other){
        cout << "copy assignment operator called " << other.val << endl;
        val = other.val;
        return *this;
    }

    //move assignment operator
    Myclass& operator=(Myclass&& other) noexcept {
        cout << "move assignment operator called " << other.val << endl;
        val = other.val;
        other.val = 0;
        return *this;
    }

    ~Myclass(){
        cout << "destructor called " << val << endl;
    }

};

int main(){

    vector<Myclass> v;

    for(int i = 0; i<4; i++){
        v.push_back(i);
        cout << "in for loop " << i << endl;
        //cout << v.capacity() << endl;
    }

    return 0;
}