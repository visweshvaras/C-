// DIY 5.1: Static Object Counter
// Lab Manual Page 19: Add a static member to your Week-3 Counter class that reports how many Counter objects have ever been created and how many are currently alive.
#include <iostream>

using namespace std;

class Counter {
private:
    int count;
    static int totalCreated;
    static int currentlyAlive;

public:
    Counter(int init = 0) : count(init) {
        totalCreated++;
        currentlyAlive++;
        cout << "  [Counter Constructed] Active: " << currentlyAlive 
             << ", Lifetime Total: " << totalCreated << endl;
    }

    Counter(const Counter &other) : count(other.count) {
        totalCreated++;
        currentlyAlive++;
        cout << "  [Counter Copy-Constructed] Active: " << currentlyAlive 
             << ", Lifetime Total: " << totalCreated << endl;
    }

    ~Counter() {
        currentlyAlive--;
        cout << "  [Counter Destructed] Active: " << currentlyAlive 
             << ", Lifetime Total: " << totalCreated << endl;
    }

    void increment() { count++; }
    int get() const { return count; }

    static int getTotalCreated() { return totalCreated; }
    static int getCurrentlyAlive() { return currentlyAlive; }
};

int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    cout << "=== DIY 5.1: Object Lifetime Tracking via Static Members ===" << endl;
    cout << "Initial: Created = " << Counter::getTotalCreated() 
         << ", Alive = " << Counter::getCurrentlyAlive() << endl;

    Counter c1;
    Counter c2;

    cout << "\nEntering inner scope:\n";
    {
        Counter c3;
        Counter c4 = c3;
        cout << "Inside scope: Created = " << Counter::getTotalCreated() 
             << ", Alive = " << Counter::getCurrentlyAlive() << endl;
    }
    cout << "Left inner scope.\n";

    cout << "\nOutside scope: Created = " << Counter::getTotalCreated() 
         << ", Alive = " << Counter::getCurrentlyAlive() << endl;

    return 0;
}
