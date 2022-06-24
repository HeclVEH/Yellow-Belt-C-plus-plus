#include <iostream>

using namespace std;

struct Fruit {
	int health = 0;
	string type = "fruit";
};

struct Apple : public Fruit {
	Apple() {
		health = 10;
		type = "apple";
	}
};

struct PineApple : public Fruit {
	PineApple() {
		health = 15;
		type = "pineapple";
	}
};

struct Orange : public Fruit {
	Orange() {
		health = 5;
		type = "orange";
	}
};

class Animal {
public:
	Animal(const string& t = "animal") 
	: type(t) {		
	}
	void Eat(const Fruit& f) {
		cout << type << " eats " << f.type << ". " << f.health << "hp. " << endl;
	}
	const string type = "animal";
};

class Cat : public Animal {
public:
	Cat() : Animal("cat") {		
	}
	void Meow() const {
		cout << "meow! " << endl;
	}
};

class Dog : public Animal {
public:
	Dog() {
		//type = "Dog";
	}
};

void DoMeal(Animal& a, Fruit& f) {
	a.Eat(f);
}

int main() {
	Cat c;
	c.Meow();
	Apple a;
	Orange o;
	Dog d;
	DoMeal(d, a);
	DoMeal(d, a);
	DoMeal(d, a);
	DoMeal(d, a);
	return 0;
}