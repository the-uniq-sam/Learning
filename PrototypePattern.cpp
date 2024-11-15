#include <bits/stdc++.h>
using namespace std;

class AbstractPrototypeInterface{
public:
    virtual AbstractPrototypeInterface* clone() const = 0;
};

class Product : public AbstractPrototypeInterface{
    int property_val;
    string property;
 public:   
    Product(int property_val, string property): property_val(property_val), property(property){}

    void setval(int val){
        property_val = val;
    }

    void printval(){
        cout << property_val << endl;
    }

    Product* clone() const override {
        return new Product(*this);
    }

};

int main(){
    Product *mainProduct = new Product(5, "transparency");
    Product *clonedProduct = mainProduct->clone();

    mainProduct->setval(50);
    mainProduct->printval();
    clonedProduct->printval();

    delete mainProduct;
    delete clonedProduct;

    return 0;
}