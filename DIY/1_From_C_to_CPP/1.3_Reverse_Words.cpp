// DIY 1.3: Reverse the Words
// Lab Manual Page 7: Read a sentence like "hello world cpp" and print "cpp world hello" (reverse word order, not characters).
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string reverseWords(const string &sentence) {
    stringstream ss(sentence);
    string word;
    vector<string> words;

    while (ss >> word) {
        words.push_back(word);
    }

    if (words.empty()) return "";

    string result;
    for (int i = static_cast<int>(words.size()) - 1; i >= 0; --i) {
        result += words[i];
        if (i > 0) result += " ";
    }
    return result;
}

int main() {
    cout << "=== DIY 1.3: Reverse Words in a Sentence ===" << endl;
    cout << "Enter sentence: ";
    string line;
    if (!getline(cin, line) || line.empty()) {
        line = "hello world cpp";
        cout << line << " (using sample input)" << endl;
    }

    string reversed = reverseWords(line);
    cout << "Original: \"" << line << "\"" << endl;
    cout << "Reversed: \"" << reversed << "\"" << endl;

    return 0;
}
