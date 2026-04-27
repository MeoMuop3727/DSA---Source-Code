#include <bits/stdc++.h>
using namespace std;

class Employee {
    private:
        int salary; // Salary is privated, so that we cannot access
                    // We only access it by get function in public
                    // And if you want to change it, use set function in public
    public:
        Employee(int _salary) : salary(_salary) {}

        // Get salary
        int get_salary() { return salary; }

        // Set salary
        void set_salary(int new_salary) { salary = new_salary; }
};

int main() {
    Employee employee(100);

    cout << employee.get_salary() << "\n";
    employee.set_salary(50);
    cout << employee.get_salary() << "\n";

    return 0;
}