#include <bits/stdc++.h>
using namespace std;

class String{
public:
    String(): res(NULL), len(0){
        cout << "default constructor called" << endl;
    }

    String(const char* s) {
        cout << "parameterized constructor called" << endl;
        len = strlen(s);
        res = new char[len + 1];
        strcpy(res, s);
    } 

    String(const String& s) {
        cout << "copy constructor called" << endl;
        len = s.len;
        res = new char[len + 1];
        strcpy(res, s.res);
    }

    String(String&& other) noexcept { // Move constructor
        cout << "Move constructor called" << endl;
        res = other.res;
        len = other.len;
    
        // Reset the source object (important!)
        other.res = nullptr; 
        other.len = 0;
    }
    

    String& operator=(const String& s) {
        cout << "copy assignment operator= called" << endl;
        if(this != &s){
            len = s.len;
            if(res != NULL)
                delete[] res;
            res = new char[len + 1];
            strcpy(res, s.res);
        }
        return *this;
    }

    int length() {
        return len;
    }

    friend ostream& operator<<(ostream& out, const String& s);
    friend istream& operator>>(istream& in, String& s);


private:
    char* res;
    unsigned int len;

};

ostream& operator<<(ostream& out, const String& s) {
    out << s.res;
    return out;
}

istream& operator>>(istream& in, String& s) {
    char temp[100]; // Temporary buffer (adjust size as needed)
    in >> temp;

    delete[] s.res; // Free existing memory
    s.len = strlen(temp);
    s.res = new char[s.len + 1];
    strcpy(s.res, temp);
    return in;
}

int main(){

    String str1; //default constructor
    String str2 = "hello"; //parameterised constructor
    String str3 = str2; //copy constructor
    str3 = str2; //copy assignment operator
    int len = str2.length();
    cin >> str1;  // overloading cin
    cout << str1; //overloadig cout

    return 0;
}
