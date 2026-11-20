// DIY 7.1: Employee Inheritance Hierarchy
// Lab Manual Page 25: Base Employee (name, id); derive Manager (adds team size) and Engineer (adds skill); print details of each.
#include <iostream>
#include <string>

using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string &n, int i) : name(n), id(i) {}

    void display() const {
        cout << "ID: " << id << " | Name: " << name;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(const string &n, int i, int ts) 
        : Employee(n, i), teamSize(ts) {}

    void display() const {
        Employee::display();
        cout << " | Role: Manager | Team Size: " << teamSize << " members" << endl;
    }
};

class Engineer : public Employee {
private:
    string skill;

public:
    Engineer(const string &n, int i, const string &sk) 
        : Employee(n, i), skill(sk) {}

    void display() const {
        Employee::display();
        cout << " | Role: Engineer | Skill: " << skill << endl;
    }
};

int main() {
    cout << "=== DIY 7.1: Hierarchical Inheritance - Employee, Manager, Engineer ===" << endl;

    Manager m("Alice Johnson", 101, 8);
    Engineer e1("Bob Smith", 102, "SystemVerilog / UVM");
    Engineer e2("Carol Davis", 103, "C++ Embedded Firmware");

    cout << "\nStaff Directory:" << endl;
    m.display();
    e1.display();
    e2.display();

    return 0;
}
