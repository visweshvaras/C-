// Experiment 10, Program 10.1: File Input / Output
// Manual topic: Writing and reading records, appending logs and parsing CSV-like lines with stringstream.
// Warning / common pitfall: Check every stream after opening. ios::out truncates files; use ios::app for logs. Validate parsed fields before using them.
// Real-world use case: File streams load test vectors and record pass/fail results in simulations.
// DIY extensions from the manual:
//   1. Compute number statistics from a file.
//   2. Create a line-numbered copy.
//   3. Load records into Student objects and find the topper.
// ------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ofstream out("students.txt");
    if (!out) {
        std::cerr << "cannot open for write\n";
        return 1;
    }

    out << "Asha 91\n"
        << "Ravi 78\n"
        << "Meera 88\n";

    std::ifstream in("students.txt");
    if (!in) {
        std::cerr << "cannot open for read\n";
        return 1;
    }

    std::string name;
    int marks;
    int total = 0;
    int count = 0;

    while (in >> name >> marks) {
        std::cout << name << " scored " << marks << '\n';
        total += marks;
        ++count;
    }

    if (count != 0) {
        std::cout << "Average = " << static_cast<double>(total) / count << '\n';
    }
}
