// Experiment 10, Program 10.2: File Input / Output
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
#include <stdexcept>
#include <string>

void appendLog(const std::string& file, const std::string& entry) {
    std::ofstream log(file, std::ios::app);
    if (!log) {
        throw std::runtime_error("log open failed: " + file);
    }
    log << entry << '\n';
}

int main() {
    try {
        appendLog("run.log", "TEST started");
        appendLog("run.log", "TEST passed");

        std::ifstream in("run.log");
        if (!in) {
            throw std::runtime_error("cannot read run.log");
        }

        std::string line;
        int lines = 0;
        while (std::getline(in, line)) {
            ++lines;
        }

        std::cout << "run.log now has " << lines << " line(s)\n";
    } catch (const std::exception& e) {
        std::cerr << "I/O error: " << e.what() << '\n';
        return 1;
    }
}
