#include <bits/stdc++.h>
using namespace std;

class People {
    protected:
        int age;
        string name;
    public:
        People() : age(0), name("") {} // Default constructor
        People(int _age, string _name)
            : age(_age), name(_name) {}
        int get_age() { return age; }
        string get_name() { return name; }
};

class Employee : public People {
    protected:
        int salary;
    public:
        Employee() : salary(0) {} // Default constructor
        Employee(int _salary) 
            : salary(_salary) {} // Use default constructor of class People
        Employee(int _age, string _name, int _salary) 
            : People(_age, _name), salary(_salary) {}

        int get_salary() { return salary; }
};

int main() {
    Employee John(40, "John", 100);

    cout << John.get_age() << "\n";
    cout << John.get_name() << "\n";
    cout << John.get_salary() << "\n";

    return 0;
}

