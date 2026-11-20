// DIY 12.1: Sort Pairs with Lambda Comparator
// Lab Manual Page 40: Given a vector<pair<string,int>>, sort by the integer (second) field ascending, then print.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cout << "=== DIY 12.1: Sorting vector<pair<string,int>> by Second Field ===" << endl;

    vector<pair<string, int>> records = {
        {"Router_Port", 4},
        {"Switch_Buffer", 64},
        {"CPU_Cores", 16},
        {"ALU_Units", 8},
        {"Cache_KB", 512}
    };

    cout << "Before Sorting:" << endl;
    for (const auto &p : records) {
        cout << "  " << p.first << " -> " << p.second << endl;
    }

    // Sort by integer (second) field ascending using lambda
    sort(records.begin(), records.end(), [](const pair<string, int> &a, const pair<string, int> &b) {
        return a.second < b.second;
    });

    cout << "\nAfter Sorting by integer (second) field ascending:" << endl;
    for (const auto &p : records) {
        cout << "  " << p.first << " -> " << p.second << endl;
    }

    return 0;
}
