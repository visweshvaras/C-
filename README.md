# C++ Concepts and Experiments

> A structured collection of small C++ programs for learning core language features, object-oriented programming, the STL, file handling, and modern C++ techniques.

## What is included?

The examples are organized into numbered topic folders:

| Section | Topics |
| --- | --- |
| 1 | C to C++: namespaces, I/O, references, and strings |
| 2 | Functions, overloading, default arguments, and pointers |
| 3 | Classes, objects, encapsulation, arrays, and `this` |
| 4 | Constructors, destructors, dynamic memory, and deep copying |
| 5 | Static members and friend functions/classes |
| 6 | Operator overloading |
| 7 | Inheritance, including multilevel, virtual, and hierarchical inheritance |
| 8 | Polymorphism, abstract classes, binding, and virtual destructors |
| 9 | Exception handling, stack unwinding, and RAII |
| 10 | File I/O, records, append-only logs, and CSV parsing |
| 11 | Function/class templates and STL containers |
| 12 | Algorithms, lambdas, priority queues, bounds, and permutations |
| 13 | Smart pointers, design patterns, and multithreading |

There are 39 focused `.cpp` examples. Each file is intentionally small and self-contained so that one concept can be compiled, run, and modified independently.

## Requirements

- A C++17-compatible compiler
- Windows, Linux, or macOS

## Build and run an example

From the repository root, compile a source file with:

```bash
g++ -std=c++17 "10 File Input Output/10.2_Append_Log_Count_Lines.cpp" -o example
```

Run it:

```bash
./example
```

On Windows PowerShell, run the generated executable with:

```powershell
.\example.exe
```

Some file-I/O examples create data files such as `students.txt`, `marks.csv`, or `run.log` in the current working directory. Run them from the relevant topic folder if you want those files beside the source:

```powershell
Set-Location "10 File Input Output"
g++ -std=c++17 10.2_Append_Log_Count_Lines.cpp -o example.exe
.\example.exe
```

The multithreading example may require the compiler's standard thread support. With GCC on some platforms, add `-pthread`.

## Learning approach

1. Start with the numbered sections in order.
2. Read the comments at the top of each program.
3. Compile and run one example at a time.
4. Change the inputs or extend the examples using the suggested exercises.

This repository is intended for practice, experimentation, and revision—not as a single production application.

