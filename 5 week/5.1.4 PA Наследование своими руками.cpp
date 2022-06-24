#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& name)
        : Name(name) 
    {}
    const string Name;
};


class Dog : public Animal {
public:
    Dog(const string& d) : Animal(d) {
    }    
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

//int main() {
//    Dog d("Barbos"); 
//    d.Bark();
//    return 0;
//}