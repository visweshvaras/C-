// DIY 1.2: Anagram Test
// Lab Manual Page 7: Read two words and decide whether one is an anagram of the other (hint: count character frequencies, or sort both).
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

string cleanString(const string &s) {
    string cleaned;
    for (char c : s) {
        if (isalpha(static_cast<unsigned char>(c))) {
            cleaned.push_back(tolower(static_cast<unsigned char>(c)));
        }
    }
    return cleaned;
}

bool isAnagramBySorting(string s1, string s2) {
    s1 = cleanString(s1);
    s2 = cleanString(s2);
    if (s1.length() != s2.length()) return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
}

bool isAnagramByFrequency(const string &s1, const string &s2) {
    string c1 = cleanString(s1);
    string c2 = cleanString(s2);
    if (c1.length() != c2.length()) return false;

    vector<int> freq(26, 0);
    for (char c : c1) freq[c - 'a']++;
    for (char c : c2) freq[c - 'a']--;

    for (int count : freq) {
        if (count != 0) return false;
    }
    return true;
}

int main() {
    cout << "=== DIY 1.2: Anagram Test ===" << endl;
    string word1, word2;
    cout << "Enter first word: ";
    if (!(cin >> word1)) word1 = "listen";
    cout << word1 << endl;

    cout << "Enter second word: ";
    if (!(cin >> word2)) word2 = "silent";
    cout << word2 << endl;

    bool anagramSort = isAnagramBySorting(word1, word2);
    bool anagramFreq = isAnagramByFrequency(word1, word2);

    cout << "\nResults:" << endl;
    cout << "Word 1: " << word1 << endl;
    cout << "Word 2: " << word2 << endl;
    if (anagramSort && anagramFreq) {
        cout << "Verdict: The words ARE anagrams of each other." << endl;
    } else {
        cout << "Verdict: The words are NOT anagrams of each other." << endl;
    }

    return 0;
}
