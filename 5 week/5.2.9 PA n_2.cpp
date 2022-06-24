#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	Person(const string& name, const string& role) : name_(name), role_(role) {}

	virtual void Walk(const string& destination) const {
		cout << Info() << " walks to: " << destination << endl;
	}

	string Name() const {
		return name_;
	}
	string Role() const {
		return role_;
	}

	string Info() const {
		return  role_ + ": " + name_;
	}

protected:
	const string name_{ "" };
private:
	const string role_{ "" };
};

class Student : public Person {
public:
	Student(const string& name, const string& favouriteSong) : Person(name, "Student"), favouriteSong_(favouriteSong) {}

	void Walk(const string& destination) const override {
		cout << Info() << " walks to: " << destination << endl;
		SingSong();
	}

	void Learn() const {
		cout << "Student: " << name_ << " learns" << endl;
	}

	void SingSong() const {
		cout << "Student: " << name_ << " sings a song: " << favouriteSong_ << endl;
	}

private:
	const string favouriteSong_{ "" };
};


class Teacher : public Person {
public:
	Teacher(const string& name, const string& subject) : Person(name, "Teacher"), subject_(subject) {}

	void Teach() const {
		cout << "Teacher: " << name_ << " teaches: " << subject_ << endl;
	}

private:
	const string subject_{ "" };
};


class Policeman : public Person {
public:
	Policeman(const string& name) : Person(name,"Policeman") {}

	void Check(const Person& p) const {
		cout << "Policeman: " << name_ << " checks " << p.Role() << ". " << p.Role()<< "'s name is: " << p.Name() << endl;
	}
};

void VisitPlaces(const Person& p, const vector<string>& places) {
	for (auto pl : places) {
		p.Walk(pl);
	}
}

int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
