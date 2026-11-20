// DIY 3.2: Counter Array
// Lab Manual Page 13: A Counter class with increment(), reset() and get(); create an array of 3 counters and exercise them.
#include <iostream>

using namespace std;

class Counter {
private:
    int count;

public:
    Counter(int init = 0) : count(init) {}

    void increment() {
        count++;
    }

    void reset() {
        count = 0;
    }

    int get() const {
        return count;
    }
};

int main() {
    cout << "=== DIY 3.2: Array of Counter Objects ===" << endl;

    const int SIZE = 3;
    Counter counters[SIZE];

    cout << "Initial values:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << "Counter[" << i << "] = " << counters[i].get() << endl;
    }

    cout << "\nExercising counters with increments:" << endl;
    for (int i = 0; i < 5; ++i) counters[0].increment(); // +5
    for (int i = 0; i < 12; ++i) counters[1].increment(); // +12
    for (int i = 0; i < 7; ++i) counters[2].increment(); // +7

    for (int i = 0; i < SIZE; ++i) {
        cout << "Counter[" << i << "] after increments = " << counters[i].get() << endl;
    }

    cout << "\nResetting Counter[1]:" << endl;
    counters[1].reset();
    for (int i = 0; i < SIZE; ++i) {
        cout << "Counter[" << i << "] = " << counters[i].get() << endl;
    }

    return 0;
}
