// DIY 8.2: Polymorphic Logger Runtime Switching
// Lab Manual Page 28: Abstract Logger with write(string); derive ConsoleLogger and FileLogger; switch at run time.
#include <iostream>
#include <fstream>
#include <string>
#include <memory>

using namespace std;

class Logger {
public:
    virtual void write(const string &msg) = 0;
    virtual ~Logger() = default;
};

class ConsoleLogger : public Logger {
public:
    void write(const string &msg) override {
        cout << "[CONSOLE LOG] " << msg << endl;
    }
};

class FileLogger : public Logger {
private:
    string filename;

public:
    FileLogger(const string &fname) : filename(fname) {}

    void write(const string &msg) override {
        ofstream ofs(filename, ios::app);
        if (ofs) {
            ofs << "[FILE LOG] " << msg << "\n";
            cout << "[FileLogger wrote to " << filename << "]: " << msg << endl;
        } else {
            cerr << "Failed to open " << filename << endl;
        }
    }
};

void runDiagnostic(Logger &logger, const string &task) {
    logger.write("Diagnostic starting for task: " + task);
    logger.write("Execution completed successfully.");
}

int main() {
    cout << "=== DIY 8.2: Polymorphic Logger with Runtime Switching ===" << endl;

    ConsoleLogger console;
    FileLogger file("app_events.log");

    cout << "\n-- Case 1: Logging to Console --" << endl;
    runDiagnostic(console, "Self-Test Subsystem");

    cout << "\n-- Case 2: Logging to File --" << endl;
    runDiagnostic(file, "Memory Integrity Checker");

    return 0;
}
