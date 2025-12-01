#include <bits/stdc++.h>
using namespace std;

class Product{
    string name; // mandatory
    int roll; //optional
    int age; //optional
    int height; //optional

public:
    void setName(const string& name){
        this->name = name;
    }
    void setRoll(int roll){
        this->roll = roll;
    }
    void setAge(int age){
        this->age = age;
    }
    void setHeight(int height){
        this->height = height;
    }

    void print(){
        cout << name << " " << roll << " " << age << " " << height << endl;
    }

};

class Builder{
public:
    virtual Builder* buildName(const string& name) = 0;
    virtual Builder* buildRoll(int roll) = 0;
    virtual Builder* buildAge(int age) = 0;
    virtual Builder* buildHeight(int height) = 0;
    virtual Product* BuildProduct() = 0; 
};

class ConcreteBuilder : public Builder{
    Product* product;
public:
    ConcreteBuilder(){
        product = new Product();
    }
    ConcreteBuilder* buildName(const string& name){
        product->setName(name);
        return this;
    }
    ConcreteBuilder* buildRoll(int roll){
        product->setRoll(roll);
        return this;
    }
    ConcreteBuilder* buildAge(int age){
        product->setAge(age);
        return this;
    }
    ConcreteBuilder* buildHeight(int height){
        product->setHeight(height);
        return this;
    }
    Product* BuildProduct(){
        return product;
    }

    ~ConcreteBuilder(){
        if(product != nullptr)
            delete product;
    }
};

class Director{
public:
    Product* getProduct(Builder &builder) {
        return builder.buildName("Sam")->buildAge(20)->buildHeight(170)->buildRoll(21)->BuildProduct();
    }
};

int main(){

    ConcreteBuilder ourbuilder;
    Director ourdirector;

    Product *ourproduct = ourdirector.getProduct(ourbuilder);
    ourproduct->print();

    return 0;
}