#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
    Person(const string& name, const string& prof)
        : name_(name), prof_(prof) {}

    string Name() const {
        return name_;
    }

    string Prof() const {
        return prof_;
    }

    virtual void Walk(const string& destination) const {
        cout << prof_ << ": " << name_ << " walks to: " << destination << endl;
    }
private:
    const string name_, prof_;
};

class Student : public Person {
public:
    Student(const string& name, const string& favouriteSong)
        : Person(name, "Student"), FavouriteSong_(favouriteSong) {}

    void Learn() const {
        cout << "Student: " << Name() << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        cout << "Student: " << Name() << " walks to: " << destination << endl;
        SingSong();
    }

    void SingSong() const {
        cout << "Student: " << Name() << " sings a song: " << FavouriteSong_ << endl;
    }
private:
    const string FavouriteSong_;
};


class Teacher : public Person {
public:
    Teacher(const string& name, const string& subject)
        : Person(name, "Teacher"), Subject_(subject) {}

    void Teach() const {
        cout << "Teacher: " << Name() << " teaches: " << Subject_ << endl;
    }   

private:   
    const string Subject_;
};


class Policeman : public Person {
public:
    Policeman(const string& name) 
        : Person(name, "Policeman") {}        

    void Check(Person& p) const {
        cout << "Policeman: " << Name() << " checks " << p.Prof() << ". " << p.Prof() << "'s name is: " << p.Name() << endl;
    }   
};

void VisitPlaces(const Person& pers, const vector<string>& places) {
    for (const auto& p : places) {
        pers.Walk(p);
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
