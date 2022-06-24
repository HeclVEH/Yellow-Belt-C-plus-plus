#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        }
        catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        }
        catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

int greatestcommondivisor(int a, int b) {
   if (b == 0) {
       return a;
   }
   else {
       return greatestcommondivisor(b, a % b);
   }
}

class rational {
public:
   rational() {  // дробь по умолчанию ч 0/1
       numerator = 0;
       denominator = 1;
   }
   rational(int new_numerator, int new_denominator) {
       const int gcd = greatestcommondivisor(new_numerator, new_denominator);
       // сократим дробь, разделив числитель и знаменатель на их ќќƒ
       numerator = new_numerator / gcd;
       denominator = new_denominator / gcd;
       // знаменатель должен быть положительным
       if (denominator < 0) {
           denominator = -denominator;
           numerator = -numerator;
       }
   }
   int numerator() const {
       return numerator;
   }
   int denominator() const {
       return denominator;
   }

private:
   int numerator;
   int denominator;
};

// поскольку дроби сокращены, достаточно сравнить числители и знаменатели
bool operator == (const rational& lhs, const rational& rhs) {
   return lhs.numerator() == rhs.numerator() &&
       lhs.denominator() == rhs.denominator();
}

// используем обычную формулу сложени¤ дробей, основанную на приведении слагаемых к общему знаменателю
rational operator + (const rational& lhs, const rational& rhs) {
   return {
       lhs.numerator() * rhs.denominator() + rhs.numerator() * lhs.denominator(),
       lhs.denominator() * rhs.denominator()
   };
}

// вычитание реализуем аналогично сложению
// дублировани¤ кода можно было избежать, определив дл¤ класса rational операцию унарного минуса: тогда разность lhs и rhs можно было бы вычислить           как lhs + (-rhs)
rational operator - (const rational& lhs, const rational& rhs) {
   return {
       lhs.numerator() * rhs.denominator() - rhs.numerator() * lhs.denominator(),
       lhs.denominator() * rhs.denominator()
   };
}

rational operator * (const rational& lhs, const rational& rhs) {
   return {
       lhs.numerator() * rhs.numerator(),
       lhs.denominator() * rhs.denominator()
   };
}

// деление равносильно умножению на обратную (ђперевєрнутуюї) дробь
rational operator / (const rational& lhs, const rational& rhs) {
   return lhs * rational(rhs.denominator(), rhs.numerator());
}

istream& operator >> (istream& is, rational& r) {
   int n, d;
   char c;

   if (is) {
       is >> n >> c >> d;
       if (is && c == '/') {
           r = rational(n, d);
       }
   }

   return is;
}

ostream& operator << (ostream& os, const rational& r) {
   return os << r.numerator() << '/' << r.denominator();
}

// чтобы сравнить lhs с rhs, сравним их разность с нулєм, что равносильно сравнению с нулєм числител¤
bool operator < (const rational& lhs, const rational& rhs) {
   return (lhs - rhs).numerator() < 0;
}

void Test() {
    {
        const Rational r(3, 10);
        AssertEqual(r.Numerator(), 3, "3,10");
        AssertEqual(r.Denominator(), 10, "3,10");
    }
    {
        const Rational r(8, 12);
        AssertEqual(r.Numerator(), 2, "8,12");
        AssertEqual(r.Denominator(), 3, "8,12");
    }
    {
        const Rational r(-4, 6);
        AssertEqual(r.Numerator(), -2, "-4,6");
        AssertEqual(r.Denominator(), 3, "-4,6");
    }
    {
        const Rational r(4, -6);
        AssertEqual(r.Numerator(), -2, "4,-6");
        AssertEqual(r.Denominator(), 3, "4,-6");
    }
    {
        const Rational r(0, 15);
        AssertEqual(r.Numerator(), 0, "0,15");
        AssertEqual(r.Denominator(), 1, "0,15");
    }
    {
        const Rational defaultConstructed;
        AssertEqual(defaultConstructed.Numerator(), 0, "default");
        AssertEqual(defaultConstructed.Denominator(), 1, "default");
    }
    {
        const Rational r(-2, -3);
        AssertEqual(r.Numerator(), 2, "-2,-3");
        AssertEqual(r.Denominator(), 3, "-2,-3");
    }
}

int main() {
    TestRunner runner;
    runner.RunTest(Test, "Test");
    // добавьте сюда свои тесты
    return 0;
}
