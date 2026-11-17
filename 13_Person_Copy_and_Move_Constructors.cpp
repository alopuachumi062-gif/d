// Question 13: Implement parameterized, copy and move constructors for Person.
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string personName, int personAge)
        : name(std::move(personName)), age(personAge) {
        cout << "Parameterized constructor called" << endl;
    }

    Person(const Person& other) : name(other.name), age(other.age) {
        cout << "Copy constructor called" << endl;
    }

    Person(Person&& other) noexcept
        : name(std::move(other.name)), age(other.age) {
        cout << "Move constructor called" << endl;
        other.age = 0;
    }

    void display() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    Person person1("Aman", 20);
    Person person2(person1);
    Person person3(std::move(person1));

    cout << "Copied object: ";
    person2.display();

    cout << "Moved object: ";
    person3.display();

    return 0;
}
