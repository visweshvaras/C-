// DIY 5.2: Friend Time Comparison
// Lab Manual Page 19: Write a Time class (hh:mm) and a friend function laterOf(Time, Time) returning the later of two times.
#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        // Normalize time
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
        hours %= 24;
    }

    int toMinutes() const {
        return hours * 60 + minutes;
    }

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":" 
             << setw(2) << minutes;
    }

    // Friend function declaration
    friend Time laterOf(const Time &t1, const Time &t2);
};

// Friend function definition: accesses private members directly
Time laterOf(const Time &t1, const Time &t2) {
    if (t1.toMinutes() >= t2.toMinutes()) {
        return t1;
    } else {
        return t2;
    }
}

int main() {
    cout << "=== DIY 5.2: Friend Function laterOf() for Time Class ===" << endl;

    Time t1(14, 30); // 2:30 PM
    Time t2(9, 45);  // 9:45 AM
    Time t3(18, 15); // 6:15 PM

    cout << "Time 1: "; t1.display(); cout << endl;
    cout << "Time 2: "; t2.display(); cout << endl;
    cout << "Time 3: "; t3.display(); cout << endl;

    Time later1 = laterOf(t1, t2);
    cout << "\nlaterOf(Time 1, Time 2) = "; later1.display(); cout << endl;

    Time later2 = laterOf(t1, t3);
    cout << "laterOf(Time 1, Time 3) = "; later2.display(); cout << endl;

    return 0;
}
