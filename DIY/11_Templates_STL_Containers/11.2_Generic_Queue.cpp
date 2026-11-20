// DIY 11.2: Generic Queue Class Template
// Lab Manual Page 37: Implement a class template Queue<T> with enqueue/dequeue/front; test with string.
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Queue {
private:
    vector<T> elements;

public:
    void enqueue(const T &item) {
        elements.push_back(item);
    }

    T dequeue() {
        if (isEmpty()) {
            throw out_of_range("Queue Underflow: Cannot dequeue from empty queue");
        }
        T frontItem = elements.front();
        elements.erase(elements.begin());
        return frontItem;
    }

    const T& front() const {
        if (isEmpty()) {
            throw out_of_range("Queue is empty: no front element");
        }
        return elements.front();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

int main() {
    cout << "=== DIY 11.2: Class Template Queue<T> Testing with String ===" << endl;

    Queue<string> taskQueue;
    taskQueue.enqueue("Packet_Header_Verification");
    taskQueue.enqueue("CRC_Checksum_Check");
    taskQueue.enqueue("Payload_Decryption");

    cout << "Queue size: " << taskQueue.size() << endl;
    cout << "Front element: " << taskQueue.front() << endl;

    cout << "\nProcessing queue items in FIFO order:" << endl;
    while (!taskQueue.isEmpty()) {
        cout << "  Dequeued: " << taskQueue.dequeue() << endl;
    }

    try {
        taskQueue.dequeue(); // Underflow test
    } catch (const exception &e) {
        cout << "Exception Caught: " << e.what() << endl;
    }

    return 0;
}
