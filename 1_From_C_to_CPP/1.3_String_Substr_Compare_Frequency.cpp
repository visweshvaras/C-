// Experiment 1, Program 1.3: From C to C++: The Transition
// Manual topic: References, pointers, type-safe I/O, std::string, palindrome checks and frequency counting.
// Warning / common pitfall: Keep references initialized; use string::npos for failed searches. Cast characters to unsigned char before cctype functions, and handle empty strings before using size()-1.
// Real-world use case: These patterns are the C++ foundation for testbench transactions and safe text processing.
// DIY extensions from the manual:
//   1. Write a generic swap using references and pointers.
//   2. Read integers from a file and calculate basic statistics.
//   3. Count word frequencies with an unordered_map.
// ------------------------------------------------------------

#include <cctype>
#include <iostream>
#include <string>

int main() {
    const std::string s = "Verification";
    std::cout << "First 4: " << s.substr(0, 4) << '\n';
    std::cout << "From 4: " << s.substr(4) << '\n';

    const int comparison = s.compare("verify");
    std::cout << "Compare vs 'verify': "
              << (comparison < 0 ? "<" : comparison > 0 ? ">" : "=") << '\n';

    int frequency[26] = {};
    for (char ch : s) {
        const unsigned char value = static_cast<unsigned char>(ch);
        if (std::isalpha(value)) {
            ++frequency[std::tolower(value) - 'a'];
        }
    }

    std::cout << "Letter count: ";
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] != 0) {
            std::cout << static_cast<char>('a' + i) << '!' << frequency[i] << ' ';
        }
    }
    std::cout << '\n';
}
