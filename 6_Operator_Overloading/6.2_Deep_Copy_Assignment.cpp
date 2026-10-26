// Experiment 6, Program 6.2: Operator Overloading
// Manual topic: Arithmetic, comparison, stream, assignment, increment and subscript operator overloading.
// Warning / common pitfall: Return the correct type for chaining. Self-assignment must be safe, and invalid subscripts must not silently redirect writes.
// Real-world use case: Operators make domain objects such as complex values, counters and register arrays readable and natural to use.
// DIY extensions from the manual:
//   1. Add more Complex operators.
//   2. Test copy assignment and self-assignment.
//   3. Improve SafeArr error handling.
// ------------------------------------------------------------

#include <iostream>
#include <cstring>
using namespace std;

class Text {
    char *buf;
public:
    Text(const char *s = "") { buf = new char[strlen(s)+1]; strcpy(buf, s); }
    Text(const Text &o)      { buf = new char[strlen(o.buf)+1]; strcpy(buf, o.buf); }
    Text& operator=(const Text &o) {             // deep-copy assignment
        if (this != &o) {                        // guard against self-assignment
            delete[] buf;                        // free old memory
            buf = new char[strlen(o.buf)+1];
            strcpy(buf, o.buf);
        }
        return *this;                            // enables a = b = c
    }
    ~Text() { delete[] buf; }
    void show() const { cout << buf << endl; }
};

int main() {
    Text a("alpha"), b("beta");
    b = a;                           // operator= runs -> deep copy
    a.show(); b.show();
    return 0;
}
