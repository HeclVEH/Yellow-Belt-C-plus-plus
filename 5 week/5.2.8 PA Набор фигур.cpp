#include <iostream>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>
#include <math.h>

using namespace std;

class Figure {
public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
};

class Rect : public Figure {
public:
    Rect(string& name, double& width, double& height) : name_(name), width_(width), height_(height) {}
    string Name() override {
        return name_;
    }
    double Perimeter() override {
        return 2 * width_ + 2 * height_;
    }
    double Area() override {
        return width_ * height_;
    }
private:
    double width_, height_;
    string name_;
};

class Triangle : public Figure {
public:
    Triangle(string& name, double& a, double& b, double& c) : name_(name), a_(a), b_(b), c_(c) {}
    string Name() override {
        return name_;
    }
    double Perimeter() override {
        return a_ + b_ + c_;
    }
    double Area() override {
        double p = (a_ + b_ + c_) / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }
private:
    double a_, b_, c_;
    string name_;
};

class Circle : public Figure {
public:
    Circle(string& name, double r) : name_(name), r_(r) {}
    string Name() override {
        return name_;
    }
    double Perimeter() override {
        return 2 * 3.14 * r_;
    }
    double Area() override {
        return 3.14 * r_ * r_;
    }
private:
    double r_;
    string name_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
    string name;
    is >> name;
    if (name == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(name, width, height);
    }
    else if (name == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(name, a, b, c);
    }
    else if (name == "CIRCLE") {
        double r;
        is >> r;
        return make_shared<Circle>(name, r);
    }
    throw std::invalid_argument("invalid figure name was specified");
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        }
        else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                    << current_figure->Name() << " "
                    << current_figure->Perimeter() << " "
                    << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}