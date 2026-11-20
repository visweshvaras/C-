// DIY 7.3: Resolving Diamond Problem with Virtual Inheritance
// Lab Manual Page 25: Person -> Student, Person -> Employee, then TA (teaching assistant) inheriting both; use a virtual base so Person appears once.
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person(const string &n = "Unknown", int a = 0) : name(n), age(a) {
        cout << "[Person Constructor] " << name << " (" << age << " yrs) initialized.\n";
    }

    void showPerson() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

class Student : virtual public Person {
protected:
    string studentId;

public:
    Student(const string &n, int a, const string &sid) 
        : Person(n, a), studentId(sid) {
        cout << "[Student Constructor] Student ID: " << studentId << endl;
    }
};

class Employee : virtual public Person {
protected:
    string employeeId;

public:
    Employee(const string &n, int a, const string &eid) 
        : Person(n, a), employeeId(eid) {
        cout << "[Employee Constructor] Employee ID: " << employeeId << endl;
    }
};

class TA : public Student, public Employee {
private:
    string courseAssigned;

public:
    // With virtual inheritance, most derived class calls virtual base constructor directly
    TA(const string &n, int a, const string &sid, const string &eid, const string &course)
        : Person(n, a), Student(n, a, sid), Employee(n, a, eid), courseAssigned(course) {
        cout << "[TA Constructor] Assigned Course: " << courseAssigned << endl;
    }

    void display() const {
        showPerson(); // Unambiguous call because Person appears only once!
        cout << " | Student ID: " << studentId 
             << " | Emp ID: " << employeeId 
             << " | Course: " << courseAssigned << endl;
    }
};

int main() {
    cout << "=== DIY 7.3: Resolving Diamond Problem via Virtual Inheritance ===" << endl;
    
    TA teachingAssistant("David Warner", 24, "STU202409", "EMP501", "ECE121 - C++ Lab");

    cout << "\nTeaching Assistant Profile:" << endl;
    teachingAssistant.display();

    return 0;
}
