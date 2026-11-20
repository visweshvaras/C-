// DIY 11.3: Word Frequency Counter using unordered_map
// Lab Manual Page 37: Read words from input and use an unordered_map<string,int> to print each word with its count; then print the most frequent word.
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cout << "=== DIY 11.3: Word Frequency Counter via unordered_map ===" << endl;

    string sampleText = "cpp is fast and cpp is powerful and modern cpp is expressive";
    cout << "Input text:\n\"" << sampleText << "\"\n" << endl;

    stringstream ss(sampleText);
    string word;
    unordered_map<string, int> freq;

    while (ss >> word) {
        freq[word]++;
    }

    cout << "Word Frequency Breakdown:" << endl;
    string mostFrequentWord;
    int maxCount = 0;

    for (const auto &entry : freq) {
        cout << "  " << entry.first << " : " << entry.second << endl;
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostFrequentWord = entry.first;
        }
    }

    cout << "\nMost Frequent Word: \"" << mostFrequentWord 
         << "\" (occurred " << maxCount << " times)" << endl;

    return 0;
}
