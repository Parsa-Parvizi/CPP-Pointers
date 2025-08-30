#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ---------------------
// Abstract Class (Abstraction)
// ---------------------
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void showInfo() = 0; // pure virtual function (abstract class)
    virtual ~Person() {} // virtual destructor
};

// ---------------------
// Inheritance
// ---------------------
class Employee : public Person {
protected:
    double salary;
public:
    Employee(string n, int a, double s) : Person(n, a), salary(s) {}
    
    void showInfo() override {
        cout << "Employee: " << name << " | Age: " << age << " | Salary: " << salary << endl;
    }

    // Getter & Setter (Encapsulation)
    double getSalary() const { return salary; }
    void setSalary(double s) { salary = s; }
};

// ---------------------
// Further Inheritance + Polymorphism
// ---------------------
class Manager : public Employee {
    string department;
public:
    Manager(string n, int a, double s, string d) 
        : Employee(n, a, s), department(d) {}

    void showInfo() override {
        cout << "Manager: " << name 
             << " | Age: " << age 
             << " | Salary: " << salary 
             << " | Department: " << department << endl;
    }
};

// ---------------------
// Composition
// ---------------------
class Company {
    string companyName;
    vector<Person*> staff; // store employees and managers polymorphically
public:
    Company(string name) : companyName(name) {}

    void addEmployee(Person* e) {
        staff.push_back(e);
    }

    void showAllEmployees() {
        cout << "\n--- Employees of " << companyName << " ---\n";
        for (auto e : staff) {
            e->showInfo(); // Polymorphism in action
        }
    }

    // Destructor to clean up dynamically allocated employees if needed
    // (Not needed here since objects are created on stack in main)
};

// ---------------------
// Operator Overloading
// ---------------------
class Point {
    int x, y;
public:
    Point(int a = 0, int b = 0) : x(a), y(b) {}
    
    // Overload + operator to add two Points
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    void print() const {
        cout << "(" << x << ", " << y << ")\n";
    }
};

// ---------------------
// Main Program
// ---------------------
int main() {
    // Create objects
    Employee e1("Ali", 28, 4000);
    Manager m1("Sara", 35, 8000, "IT");

    // Display information
    e1.showInfo();
    m1.showInfo();

    // Work with Composition
    Company c("TechCorp");
    c.addEmployee(&e1);
    c.addEmployee(&m1);
    c.showAllEmployees();

    // Work with Operator Overloading
    Point p1(2, 3), p2(4, 5);
    Point p3 = p1 + p2; // use operator+
    cout << "\nPoint sum: ";
    p3.print();

    // Additional demonstration: Polymorphic behavior with pointers
    Person* p = &m1;  // base class pointer to derived object
    cout << "\nPolymorphic call through base pointer:\n";
    p->showInfo();

    // Demonstrate encapsulation by modifying salary via setter
    cout << "\nUpdating salary for employee Ali...\n";
    e1.setSalary(4500);
    e1.showInfo();

    return 0;
}
