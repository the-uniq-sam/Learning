#include <bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    virtual void printtype() = 0; 
    virtual void printbrand() = 0;
};

class Bike : public Vehicle{
public:
    void printtype() override {
        cout << "bike" << endl;
    }
};

class Car : public Vehicle{
public:
    void printtype() override {
        cout << "car" << endl;
    }
};

class MarutiBike : public Bike{
public:
    void printbrand() override {
        cout << "maruti" << endl;
    }
};

class MarutiCar : public Car{
public:
    void printbrand() override {
        cout << "maruti" << endl;
    }
};


class VehicleFactory{
public:
    virtual Vehicle* createBike() = 0;
    virtual Vehicle* createCar() = 0;
};

class MarutiFactory : public VehicleFactory{
    Vehicle* createBike() override {
        return new MarutiBike();
    }
    Vehicle* createCar() override {
        return new MarutiCar();
    }
};



int main(){
    VehicleFactory *marutifactory = new MarutiFactory();
    Vehicle *bike = marutifactory->createBike();
    Vehicle *car = marutifactory->createCar();

    bike->printtype();
    bike->printbrand();
    car->printtype();
    car->printbrand();

    delete marutifactory;
    delete bike;
    delete car;


    return 0;
}