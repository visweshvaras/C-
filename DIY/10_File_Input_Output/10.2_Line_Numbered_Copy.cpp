// DIY 10.2: Line-Numbered File Copy
// Lab Manual Page 34: Read in.txt and write out.txt with each line prefixed by its line number.
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ensureInputExists(const string &infile) {
    ifstream check(infile);
    if (!check.good()) {
        ofstream create(infile);
        create << "Object-Oriented Programming in C++\n";
        create << "ECE121 Lab Manual Exercises\n";
        create << "File Input and Output Operations\n";
        create << "Stream Manipulation and Formatting\n";
        create.close();
        cout << "Created sample '" << infile << "'.\n";
    }
}

int main() {
    cout << "=== DIY 10.2: Line-Numbered Copy ===" << endl;
    const string infile = "in.txt";
    const string outfile = "out.txt";

    ensureInputExists(infile);

    ifstream src(infile);
    ofstream dst(outfile);

    if (!src || !dst) {
        cerr << "Error opening input or output file." << endl;
        return 1;
    }

    string line;
    int lineNumber = 1;
    while (getline(src, line)) {
        dst << lineNumber << ": " << line << "\n";
        lineNumber++;
    }

    src.close();
    dst.close();

    cout << "Successfully copied " << (lineNumber - 1) << " lines from '" 
         << infile << "' to '" << outfile << "'.\n";

    cout << "\nContents of '" << outfile << "':" << endl;
    ifstream verify(outfile);
    while (getline(verify, line)) {
        cout << "  " << line << endl;
    }

    return 0;
}
