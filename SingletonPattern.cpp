#include <bits/stdc++.h>
using namespace std;

class SingletonClass{
private:
    // static SingletonClass *instance;
    static mutex mtx;
    SingletonClass(){}
    SingletonClass(const SingletonClass& other) = delete;
    SingletonClass& operator=(const SingletonClass& other) = delete;

public:
    static SingletonClass* getInstance(){
        // mtx.lock();
        // if(instance == nullptr){
        //     instance = new SingletonClass();
        //     cout << "instance created" << endl;
        // }
        // mtx.unlock();
        // return instance;
        static SingletonClass instance;
        cout << "instance created " << &instance << endl;
        return &instance;
    }
};

// SingletonClass* SingletonClass::instance = nullptr;
mutex SingletonClass::mtx;


int main(){
    thread t1(SingletonClass::getInstance);
    thread t2(SingletonClass::getInstance);

    SingletonClass* myfirstinstance = SingletonClass::getInstance();
    // SingletonClass mysecondinstance = *myfirstinstance; //it won't work now as copy constructor is disabled
    // cout << &mysecondinstance << endl;

    t1.join();
    t2.join();


    return 0;

}