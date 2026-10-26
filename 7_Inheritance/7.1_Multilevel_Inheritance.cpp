// Experiment 7, Program 7.1: Inheritance
// Manual topic: Multilevel inheritance, virtual inheritance for the diamond problem and hierarchical inheritance.
// Warning / common pitfall: Base classes used polymorphically need virtual destructors and virtual functions. Virtual inheritance shares one common base subobject.
// Real-world use case: Inheritance models reusable device and stream abstractions in verification environments.
// DIY extensions from the manual:
//   1. Extend the Device hierarchy.
//   2. Demonstrate the diamond problem.
//   3. Add derived account behaviors.
// ------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

class Device {                        // base
    string id;
public:
    Device(string i) : id(i) { cout << "Device " << id << " ctor\n"; }
    ~Device()                { cout << "Device dtor\n"; }
    void info() const        { cout << "ID=" << id; }
};

class Sensor : public Device {        // Sensor IS-A Device
    string type;
public:
    Sensor(string i, string t) : Device(i), type(t) { cout << "Sensor ctor\n"; }
    void info() const { Device::info(); cout << " type=" << type; }
};

class TempSensor : public Sensor {    // TempSensor IS-A Sensor IS-A Device
    double celsius;
public:
    TempSensor(string i, double c) : Sensor(i, "TEMP"), celsius(c) { cout << "TempSensor ctor\n"; }
    void show() const { info(); cout << " val=" << celsius << "\n"; }
};

int main() {
    TempSensor t("U1", 36.5);         // ctors run base -> derived
    t.show();
    return 0;                         // dtors run derived -> base
}
