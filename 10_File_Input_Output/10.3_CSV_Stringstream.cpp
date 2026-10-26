// Experiment 10, Program 10.3: File Input / Output
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
#include <sstream>
#include <string>

int main() {
    std::ofstream out("marks.csv");
    if (!out) {
        std::cerr << "open failed for writing\n";
        return 1;
    }

    out << "Asha,91\nRavi,78\nMeera,88\n";
    out.close();

    std::ifstream in("marks.csv");
    if (!in) {
        std::cerr << "open failed\n";
        return 1;
    }

    std::string line;
    while (std::getline(in, line)) {
        std::stringstream ss(line);
        std::string name;
        std::string marks;

        if (std::getline(ss, name, ',') && std::getline(ss, marks, ',')) {
            std::cout << name << " => " << marks << '\n';
        }
    }
}
