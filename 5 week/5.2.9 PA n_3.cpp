#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(string name) : Name(name) {}
    const string& GetName() const { return Name; }
    const string GetFullName() const { return Role() + ": " + GetName(); }
    virtual void Walk(const string& destination) const {
        cout << GetFullName() << " walks to: " << destination << endl;
    }
    virtual string Role() const = 0;

protected:
    string Name;
};

class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong) : Person(name) {
        FavouriteSong = favouriteSong;
    }

    string Role() const override { return "Student"; }

    void Learn() const {
        cout << GetFullName() << " learns" << endl;
    }

    void SingSong() const {
        cout << GetFullName() << " sings a song: " << FavouriteSong << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        SingSong();
    }

public:
    string FavouriteSong;
};


class Teacher : public Person {
public:

    Teacher(const string& name, const string& subject) : Person(name) {
        Subject = subject;
    }

    string Role() const override { return "Teacher"; }

    void Teach() const {
        cout << GetFullName() << " teaches: " << Subject << endl;
    }

public:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(const string& name) : Person(name) {
    }

    string Role() const override { return "Policeman"; }

    void Check(const Person& p) const {
        cout << GetFullName() << " checks " << p.Role() << ". " << p.Role() << "'s name is: " << p.GetName() << endl;
    }

};


void VisitPlaces(const Person& person, const vector<string>& places) {
    for (const auto& p : places) {
        person.Walk(p);
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