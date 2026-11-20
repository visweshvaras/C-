# C++ Concepts, Experiments & DIY Solutions

> A hands-on C++ learning journey from fundamentals to modern programming techniques, including all **39 Core Experiments** and all **39 DIY – Test Your Understanding** solved programs with compiled executables.

---

## 📚 Complete Learning Map & DIY Index

| Section | Topic | Core Programs | DIY Tasks (Solved & Executable) |
| :---: | :--- | :--- | :--- |
| **1** | **From C to C++** | • Namespaces & I/O References<br>• Palindrome & Frequencies<br>• Substring & Comparison | **1.1** Vowel & Consonant Counter<br>**1.2** Word Anagram Tester<br>**1.3** Sentence Word Reverser |
| **2** | **Functions, Overloading & Inline** | • Overloading & Inline Demo<br>• Default Arguments<br>• Reference vs Pointer Output | **2.1** Overloaded Volume (Cube, Cuboid, Cylinder)<br>**2.2** Default-Argument Power Function<br>**2.3** Inline Overloaded `minVal` |
| **3** | **Classes, Objects & Encapsulation** | • BankAccount Encapsulation<br>• Array of Hardware Registers<br>• Object Chaining & `this` Pointer | **3.1** Rectangle with Validation & Metrics<br>**3.2** Array of Independent Counters<br>**3.3** Complex Number Class & Display |
| **4** | **Constructors, Destructors & Dynamic Memory** | • Construction/Destruction Order<br>• Deep Copying & Ownership<br>• Constructor Overloading | **4.1** Dynamic Matrix with Deep Copy & RAII<br>**4.2** Dynamic Integer Stack with Destructor<br>**4.3** Lifetime Logger & Memory Tracing |
| **5** | **Static Members & Friend Functions** | • Static Live Object Counter<br>• Friend Function Access<br>• Friend Class Integration | **5.1** Static Object Counter (Created vs Alive)<br>**5.2** Friend Function `laterOf(Time, Time)`<br>**5.3** Auto-Increment Unique Order ID Factory |
| **6** | **Operator Overloading** | • Arithmetic, Comparison & Stream<br>• Deep Copy Assignment (`operator=`)<br>• Unary & Subscript (`operator[]`) | **6.1** Money Class (+ and - with Carry/Borrow)<br>**6.2** Fraction I/O (`<<`, `>>`) with Auto-GCD<br>**6.3** Safe Array with Bounds Checking (`[]`) |
| **7** | **Inheritance** | • Multilevel Inheritance<br>• Virtual Base & Diamond Resolution<br>• Hierarchical Specialization | **7.1** Employee Hierarchy (Manager & Engineer)<br>**7.2** Multilevel Shapes Constructor Call Order<br>**7.3** Resolving Diamond via Virtual Inheritance |
| **8** | **Polymorphism & Virtual Functions** | • Abstract Base & Pure Virtual<br>• Early vs Late Binding<br>• Virtual Destructors & Safe Casting | **8.1** Abstract Account & Polymorphic Interest<br>**8.2** Polymorphic Logger (Console / File Switching)<br>**8.3** Virtual Destructor Resource Leak Prevention |
| **9** | **Exception Handling** | • Custom Exception Classes<br>• Stack Unwinding & RAII Cleanup<br>• Exception Inheritance Hierarchy | **9.1** Bank Account Safe Withdrawal Exception<br>**9.2** Stack Overflow & Underflow Exceptions<br>**9.3** Exception Catch Order & Slicing Prevention |
| **10** | **File Input & Output** | • Structured Binary/Text Records<br>• Append-Only Log Processing<br>• CSV Parsing via `stringstream` | **10.1** Number Statistics (Count, Sum, Min, Max)<br>**10.2** Line-Numbered File Duplication<br>**10.3** Student Records Parser & Topper Finder |
| **11** | **Templates & STL Containers** | • Function & Class Templates<br>• Vectors, Lists & Maps<br>• Multi-Type Generic Pair | **11.1** Generic Utilities (`swapVals`, `findMax`)<br>**11.2** Generic Queue Template (`Queue<T>`)<br>**11.3** Word Frequency Counter via `unordered_map` |
| **12** | **STL Algorithms & Lambdas** | • Sort, Count & Accumulate<br>• Top-K Leaderboard via Priority Queue<br>• Binary Search & Permutations | **12.1** Pair Sorting with Custom Lambda<br>**12.2** Top-3 Elements using Min-Heap<br>**12.3** Custom `accumulate` (Product & Evens Sum) |
| **13** | **Smart Pointers, Design Patterns & Threads** | • Smart Pointer Factory Pattern<br>• Thread-Safe Singleton Logger<br>• Multithreading & Mutex Synchronization | **13.1** Raw Pointers to Smart Pointers (`unique_ptr`)<br>**13.2** Shape Factory v2 with Dynamic Selection<br>**13.3** Race Condition vs Mutex Synchronization |

---

## 📁 Repository Layout

```text
C-/
├── 1_From_C_to_CPP/                              # Core Lab Week 1
├── 2_Functions_Overloading_Default_Inline/       # Core Lab Week 2
├── ...
├── 13_Smart_Pointers_Design_Patterns_Threads/    # Core Lab Week 13
│
├── DIY/                                          # All 39 DIY Exercises & Executables
│   ├── 1_From_C_to_CPP/
│   │   ├── 1.1_Vowel_Consonant_Counter.cpp
│   │   ├── 1.1_Vowel_Consonant_Counter           # Compiled Executable
│   │   ├── 1.2_Anagram_Test.cpp
│   │   ├── 1.2_Anagram_Test                      # Compiled Executable
│   │   ├── 1.3_Reverse_Words.cpp
│   │   └── 1.3_Reverse_Words                     # Compiled Executable
│   ├── ...
│   ├── 13_Smart_Pointers_Design_Patterns_Threads/
│   │   ├── 13.1_Raw_To_Smart_Pointer.cpp
│   │   ├── 13.1_Raw_To_Smart_Pointer             # Compiled Executable
│   │   ├── 13.2_Shape_Factory_V2.cpp
│   │   ├── 13.2_Shape_Factory_V2                 # Compiled Executable
│   │   ├── 13.3_Race_Condition_Lock.cpp
│   │   └── 13.3_Race_Condition_Lock              # Compiled Executable
│   └── run_all_diy.sh                            # Test Runner Script for all 39 DIYs
│
└── run_all_diy.sh                                # Root Runner Script
```

---

## ⚡ How to Run

### Run All 39 DIY Programs in One Step
```bash
bash run_all_diy.sh
```

### Compile & Run Any Specific DIY Program
Navigate to the corresponding folder and run:
```bash
# Example: Week 6 DIY 1 (Money Arithmetic)
cd DIY/6_Operator_Overloading
g++ -std=c++17 6.1_Money_Arithmetic.cpp -o 6.1_Money_Arithmetic
./6.1_Money_Arithmetic
```

### Concurrency Programs
Programs using threads (e.g., `DIY/13_Smart_Pointers_Design_Patterns_Threads/13.3_Race_Condition_Lock.cpp`) compile with `-pthread`:
```bash
cd DIY/13_Smart_Pointers_Design_Patterns_Threads
g++ -std=c++17 13.3_Race_Condition_Lock.cpp -o 13.3_Race_Condition_Lock -pthread
./13.3_Race_Condition_Lock
```

---

## ⚙️ Compilation & Environment Notes
- **Standard:** Tested and compiled with standard C++17 (`g++ -std=c++17`).
- **Dependencies:** Standard C++ library, POSIX threads (`-pthread`).
- **Clean RAII:** Zero memory leaks, verified with address sanitation and proper destructors.
