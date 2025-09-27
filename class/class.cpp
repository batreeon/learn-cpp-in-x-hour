#include <iostream>
using namespace std;

class Car {
    string brand;
    string model;
    int price;

    public:
        Car(string b, string m, int p) {
            brand = b;
            model = m;
            price = p;
        }

        void Price(){
            cout << price << endl;
        }
};



int main() {
    Car c("bmw", "x5", 3);
    // cout << c.brand << endl;
    c.Price();
    return 0;
}