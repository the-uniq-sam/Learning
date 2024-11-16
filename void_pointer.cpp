#include <iostream>
#include <functional>


// Example 1: Using a void* to pass arbitrary data to a callback

void myCallback(void* userData) {
    int* data = static_cast<int*>(userData); // Cast back to the original type
    if (data) {
        std::cout << "User data: " << *data << std::endl;
    }
}

void doSomething(void (*callback)(void*), void* userData) {
    // ... perform some operation ...

    // Call the callback function
    callback(userData);
}


// Example 2: More type-safe approach using std::function and a lambda

void doSomethingSafe(std::function<void(int*)> callback, int* userData) {
    // ...

    callback(userData);
}




int main() {
    int data = 42;


    std::cout << "Example 1:\n";
    doSomething(myCallback, &data); // Pass the address of 'data'


    std::cout << "\nExample 2:\n";
    doSomethingSafe([](int* data) { // Lambda captures data by pointer
        std::cout << "User data (lambda): " << *data << std::endl; 
    }, &data);


     std::cout << "\nExample 3: Flexible Lambda captures\n";

     int otherData = 10;

     auto flexibleCallback = [&](void *userData) {
        int* intData = static_cast<int*>(userData);
        if(intData){
            std::cout << "From flexible callback with pointer " << *intData + otherData << std::endl;
        }


     };

     doSomethingSafe(flexibleCallback, &data);



    return 0;
}

