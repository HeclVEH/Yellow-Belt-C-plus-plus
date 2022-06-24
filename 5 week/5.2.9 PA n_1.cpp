//#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace std;

class Human {
public:
    Human(const string& name, const string& occupation) : name_(name), occupation_(occupation) {}

    virtual void Walk(const string& destination) const = 0;

    string GetName() const {
        return name_;
    }

    string GetOccupation() const {
        return occupation_;
    }

    string Log() const {
        return this->GetOccupation() + ": " + this->GetName();
    }
protected:
    const string name_;
    const string occupation_;
};

class Student : public Human {
public:
    Student(const string& name, const string& favouriteSong) : Human(name, "Student"), favouriteSong_(favouriteSong) {}

    void SingSong() const {
        cout << this->Log() << " sings a song: " << favouriteSong_ << endl;
    }

    void Walk(const string& destination) const override {
        cout << this->Log() << " walks to: " << destination << endl;
        this->SingSong();
    }

private:
    const string favouriteSong_;
};

class Teacher : public Human {
public:
    Teacher(const string& name, const string& subject) : Human(name, "Teacher"), Subject(subject) {}

    void Walk(const string& destination) const override {
        cout << this->Log() << " walks to: " << destination << endl;
    }

    void Teach() const {
        cout << this->Log() << " teaches: " << Subject << endl;
    }

private:
    const string Subject;
};

class Policeman : public Human {
public:
    Policeman(const string& name) : Human(name, "Policeman") {}

    void Check(const Human& t) const {
        cout << this->Log() << " checks " << t.GetOccupation()
            << ". " << t.GetOccupation() << "'s name is: " << t.GetName() << endl;
    }

    void Walk(const string& destination) const {
        cout << this->Log() << " walks to: " << destination << endl;
    }
};

void VisitPlaces(const Human& h, const vector<string>& places) {
    for (const auto& p : places) {
        h.Walk(p);
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