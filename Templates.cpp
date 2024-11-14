#include <iostream>
#include <vector>

using namespace std;

template <typename T>
T max_of_two(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
void print_vector(const vector<T>& vec) {
    for (const auto& element : vec) {
        cout << element << " ";
    }
    cout << endl;
}

template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {
    return a + b;
}


int main() {
    int a = 5, b = 10;
    double c = 3.14, d = 2.71;
    string e = "hello", f = "world";

    cout << "Max of " << a << " and " << b << ": " << max_of_two(a, b) << endl;
    cout << "Max of " << c << " and " << d << ": " << max_of_two(c, d) << endl;
    cout << "Max of " << e << " and " << f << ": " << max_of_two(e, f) << endl;


    vector<int> int_vec = {1, 2, 3, 4, 5};
    vector<double> double_vec = {1.1, 2.2, 3.3, 4.4, 5.5};
    vector<string> string_vec = {"apple", "banana", "cherry"};

    cout << "Integer vector: ";
    print_vector(int_vec);
    cout << "Double vector: ";
    print_vector(double_vec);
    cout << "String vector: ";
    print_vector(string_vec);

    int x = 5;
    double y = 3.14;
    string z = "hello";

    cout << add(x, y) << endl; // Output: 8.14
    cout << add(x, z) << endl; // Compile-time error: cannot add int and string

    return 0;
}
