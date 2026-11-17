// Question 9: Demonstrate covariant return types using Employee and Report classes.
#include <iostream>
using namespace std;

class Report {
public:
    virtual void display() const {
        cout << "General report" << endl;
    }
    virtual ~Report() = default;
};

class FullTimeReport : public Report {
public:
    void display() const override {
        cout << "Full-time employee report" << endl;
    }
};

class ContractReport : public Report {
public:
    void display() const override {
        cout << "Contract employee report" << endl;
    }
};

class Employee {
public:
    virtual Report* generateReport() {
        return new Report();
    }
    virtual ~Employee() = default;
};

class FullTimeEmployee : public Employee {
public:
    FullTimeReport* generateReport() override {
        return new FullTimeReport();
    }
};

class ContractEmployee : public Employee {
public:
    ContractReport* generateReport() override {
        return new ContractReport();
    }
};

int main() {
    FullTimeEmployee fullTime;
    ContractEmployee contract;

    Report* report1 = fullTime.generateReport();
    Report* report2 = contract.generateReport();

    report1->display();
    report2->display();

    delete report1;
    delete report2;
    return 0;
}
