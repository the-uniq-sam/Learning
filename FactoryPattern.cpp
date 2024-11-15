#include <bits/stdc++.h>
using namespace std;

class Vehicle{
public:
    virtual void print() = 0;
};

class Bike : public Vehicle{
public:
    void print() override {
        cout << "bike" << endl;
    }
};

class Car : public Vehicle{
public:
    void print() override {
        cout << "car" << endl;
    }

};

class VehicleFactory{
public:
    virtual Vehicle* createVehicle() = 0;
};

class BikeFactory : public VehicleFactory{
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }
};

class CarFactory : public VehicleFactory{
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
};


int main(){
    VehicleFactory *bikefactory = new BikeFactory();
    VehicleFactory *carfactory = new CarFactory();

    Vehicle *bike = bikefactory->createVehicle();
    Vehicle *car = carfactory->createVehicle();

    bike->print();
    car->print();

    delete bikefactory;
    delete carfactory;
    delete bike;
    delete car;

    return 0;
}