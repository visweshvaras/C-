// DIY 10.1: Number Stats from File
// Lab Manual Page 34: Read an unknown count of integers from nums.txt and print their count, sum, min and max.
#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

void ensureFileExists(const string &filename) {
    ifstream check(filename);
    if (!check.good()) {
        ofstream create(filename);
        create << "45 12 89 23 7 94 65 33 18 50\n";
        create.close();
        cout << "Created sample file '" << filename << "' with numbers.\n";
    }
}

int main() {
    cout << "=== DIY 10.1: File Number Statistics ===" << endl;
    const string filename = "nums.txt";
    ensureFileExists(filename);

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    int count = 0;
    long long sum = 0;
    int minVal = numeric_limits<int>::max();
    int maxVal = numeric_limits<int>::min();

    int val;
    while (inFile >> val) {
        count++;
        sum += val;
        if (val < minVal) minVal = val;
        if (val > maxVal) maxVal = val;
    }
    inFile.close();

    if (count == 0) {
        cout << "File is empty, no numbers found." << endl;
    } else {
        cout << "File Statistics for '" << filename << "':" << endl;
        cout << "  Count   : " << count << endl;
        cout << "  Sum     : " << sum << endl;
        cout << "  Min     : " << minVal << endl;
        cout << "  Max     : " << maxVal << endl;
        cout << "  Average : " << (static_cast<double>(sum) / count) << endl;
    }

    return 0;
}
