#include <iostream>
using namespace std;

int main() {
    string food = "rice";
    string &meal = food;

    cout << food << endl;
    cout << meal << endl;
    cout << &food << endl;
    cout << &meal << endl;

    food = "pizza";
    cout << food << endl;
    cout << meal << endl;
    
    return 0;
}