#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Person {
 public:
  Person(const string& name, const string& jobName)
      : Name(name), JobName(jobName) {}

  virtual void Walk(const string& dst) const {
    cout << JobName << ": " << Name << " walks to: " << dst << endl;
  }

  string Introduce() const { return JobName + ": " + Name; }

 public:
  const string Name;
  const string JobName;
};

class Student : public Person {
 public:
  Student(string name, string favouriteSong)
      : Person(name, "Student"), FavouriteSong(favouriteSong) {}

  void Learn() { cout << Introduce() << " learns" << endl; }

  void Walk(const string& dst) const override {
    Person::Walk(dst);
    SingSong();
  }

  void SingSong() const {
    cout << Introduce() << " sings a song: " << FavouriteSong << endl;
  }

 public:
  const string FavouriteSong;
};

class Teacher : public Person {
 public:
  Teacher(string name, string subject)
      : Person(name, "Teacher"), Subject(subject) {}

  void Teach() { cout << Introduce() << " teaches: " << Subject << endl; }

 public:
  const string Subject;
};

class Policeman : public Person {
 public:
  Policeman(string name) : Person(name, "Policeman") {}

  void Check(const Person& p) const {
    cout << Introduce() << " checks " << p.JobName << ". " << p.JobName
         << "'s name is: " << p.Name << endl;
  }
};

void VisitPlaces(Person& person, const vector<string>& places) {
  for (auto place : places) {
    person.Walk(place);
  }
}

int main() {
  auto t = Teacher("Jim", "Math");
  auto s = Student("Ann", "We will rock you");
  auto p = Policeman("Bob");

  VisitPlaces(t, {"Moscow", "London"});
  p.Check(s);
  VisitPlaces(s, {"Moscow", "London"});
  return 0;
}
