// DIY 4.1: Dynamic Matrix with Deep Copy & RAII
// Lab Manual Page 16: A Matrix class that allocates an m x n grid with new, provides a deep copy constructor, and frees it in the destructor.
#include <iostream>

using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    int **data;

    void allocateMemory() {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols]();
        }
    }

    void freeMemory() {
        if (data) {
            for (int i = 0; i < rows; ++i) {
                delete[] data[i];
            }
            delete[] data;
            data = nullptr;
        }
    }

public:
    Matrix(int r, int c) : rows(r), cols(c), data(nullptr) {
        allocateMemory();
        cout << "[Matrix] Constructor: Allocated " << rows << "x" << cols << " grid\n";
    }

    // Deep Copy Constructor
    Matrix(const Matrix &other) : rows(other.rows), cols(other.cols), data(nullptr) {
        allocateMemory();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
        cout << "[Matrix] Deep Copy Constructor called\n";
    }

    // Deep Copy Assignment Operator
    Matrix& operator=(const Matrix &other) {
        if (this != &other) {
            freeMemory();
            rows = other.rows;
            cols = other.cols;
            allocateMemory();
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    data[i][j] = other.data[i][j];
                }
            }
            cout << "[Matrix] Deep Copy Assignment Operator called\n";
        }
        return *this;
    }

    ~Matrix() {
        cout << "[Matrix] Destructor: Deallocating " << rows << "x" << cols << " grid\n";
        freeMemory();
    }

    void set(int r, int c, int val) {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            data[r][c] = val;
        }
    }

    int get(int r, int c) const {
        if (r >= 0 && r < rows && c >= 0 && c < cols) {
            return data[r][c];
        }
        return 0;
    }

    void display(const string &name = "Matrix") const {
        cout << name << " (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; ++i) {
            cout << "  ";
            for (int j = 0; j < cols; ++j) {
                cout << data[i][j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main() {
    cout << "=== DIY 4.1: Dynamic Matrix with Deep Copy ===" << endl;

    Matrix m1(2, 3);
    m1.set(0, 0, 10); m1.set(0, 1, 20); m1.set(0, 2, 30);
    m1.set(1, 0, 40); m1.set(1, 1, 50); m1.set(1, 2, 60);
    m1.display("m1 (Original)");

    cout << "\nCreating m2 via Deep Copy Constructor:" << endl;
    Matrix m2 = m1;
    m2.display("m2 (Copy)");

    cout << "\nModifying m2 to prove independence (deep copy check):" << endl;
    m2.set(0, 0, 999);
    m1.display("m1 (Original after m2 modification)");
    m2.display("m2 (Modified)");

    return 0;
}
