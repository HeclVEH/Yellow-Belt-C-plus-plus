#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
	Animal(const string& type) : type_(type) {}

	void Eat(const string& fruit) {
		cout << type_ << " eats " << fruit << endl;
	}

	virtual void Sound() const {
		cout << type_ << " is silent" << endl;
	}
private:
	const string type_;
};

class Cat : public Animal {
public:
	Cat() : Animal("cat") {}

	void Sound() const override {
		cout << "Meow!" << endl;
	}
};

class Dog : public Animal {
public:
	Dog() : Animal("dog") {}

	void Sound() const override {
		cout << "Whaf!" << endl;
	}
};

class Parrot : public Animal {
public:
	Parrot(const string& name) : Animal("parrot"), name_(name) {}

	void Sound() const override {
		cout << name_ << " is good!" << endl;
	}
private:
	const string name_;
};

class Horse : public Animal {
public:
	Horse() : Animal("horse") {}
};

void MakeSound(const Animal& a) {
	a.Sound();
}

int main() {
	/*shared_ptr<Animal> a;

	a = make_shared<Cat>();
	a -> Sound();*/
	
	vector<shared_ptr<Animal>> animals = {
		make_shared<Cat>(),
		make_shared<Dog>(),
		make_shared<Parrot>("Kesha"),
	};
	
	for (const auto& a : animals) {
		MakeSound(*a);
	}	

	return 0;
}