#include <iostream>
using namespace std;

class employee {
public:
    virtual float calculateSalary() = 0;
};

class fulltime : public employee {
private:
    float salary;

public:
    fulltime(float salary) {
        this->salary = salary;
    }

    float calculateSalary() {
        return this->salary;
    }
};

class parttime : public employee {
private:
    float hoursWorked;
    float hourlyRate;

public:
    parttime(float hoursWorked, float hourlyRate) {
        this->hoursWorked = hoursWorked;
        this->hourlyRate = hourlyRate;
    }

    float calculateSalary() {
        return this->hoursWorked * this->hourlyRate;
    }
};

int main() {
    fulltime f(12000);
    parttime p(5, 321);

    cout << "Full Time Employee Salary: ";
    cout << f.calculateSalary();
    cout << "\nPart Time Employee Salary:";
    cout << p.calculateSalary();

    return 0;
}