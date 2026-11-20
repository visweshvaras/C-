// DIY 10.3: Student Records and Topper Finder
// Lab Manual Page 34: Store name marks pairs in a file, read them back into an array of Student objects, and print the topper.
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    string name;
    double marks;

    Student(const string &n = "", double m = 0.0) : name(n), marks(m) {}

    void display() const {
        cout << "  " << name << " - " << marks << " marks\n";
    }
};

void createSampleRecords(const string &filename) {
    ofstream ofs(filename);
    ofs << "Aarav 92.5\n";
    ofs << "Diya 98.0\n";
    ofs << "Rohan 88.5\n";
    ofs << "Priya 95.0\n";
    ofs << "Vikram 91.0\n";
    ofs.close();
}

int main() {
    cout << "=== DIY 10.3: Student Records & Topper Finder ===" << endl;
    const string filename = "student_records.txt";
    createSampleRecords(filename);

    ifstream ifs(filename);
    if (!ifs) {
        cerr << "Error reading " << filename << endl;
        return 1;
    }

    vector<Student> students;
    string name;
    double marks;
    while (ifs >> name >> marks) {
        students.emplace_back(name, marks);
    }
    ifs.close();

    cout << "Loaded " << students.size() << " student records from '" << filename << "':\n";
    const Student* topper = nullptr;
    for (const auto &s : students) {
        s.display();
        if (topper == nullptr || s.marks > topper->marks) {
            topper = &s;
        }
    }

    if (topper) {
        cout << "\n🏆 Academic Topper:" << endl;
        cout << "  Name : " << topper->name << endl;
        cout << "  Marks: " << topper->marks << "/100" << endl;
    }

    return 0;
}
