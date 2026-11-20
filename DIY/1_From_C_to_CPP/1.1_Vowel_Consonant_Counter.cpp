// DIY 1.1: Vowel & Consonant Counter
// Lab Manual Page 7: Read a sentence with getline(cin, s) and print how many vowels and consonants it contains.
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void countVowelsAndConsonants(const string &s, int &vowels, int &consonants, int &others) {
    vowels = 0;
    consonants = 0;
    others = 0;
    for (char c : s) {
        if (isalpha(static_cast<unsigned char>(c))) {
            char lower = tolower(static_cast<unsigned char>(c));
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        } else {
            others++;
        }
    }
}

int main() {
    cout << "=== DIY 1.1: Vowel & Consonant Counter ===" << endl;
    cout << "Enter a sentence: ";
    string sentence;
    if (!getline(cin, sentence) || sentence.empty()) {
        sentence = "Object Oriented Programming in C++ Lab ECE121";
        cout << sentence << " (using sample sentence)" << endl;
    }

    int vowels = 0, consonants = 0, others = 0;
    countVowelsAndConsonants(sentence, vowels, consonants, others);

    cout << "\nAnalysis Results:" << endl;
    cout << "Sentence   : \"" << sentence << "\"" << endl;
    cout << "Total chars: " << sentence.length() << endl;
    cout << "Vowels     : " << vowels << endl;
    cout << "Consonants : " << consonants << endl;
    cout << "Other chars: " << others << " (spaces, digits, punctuation)" << endl;

    return 0;
}
