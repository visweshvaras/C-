// DIY 5.3: Unique Order ID Factory
// Lab Manual Page 19: Use a static member so every new Order object automatically receives the next ID (1001, 1002, ...) in its constructor.
#include <iostream>
#include <string>

using namespace std;

class Order {
private:
    static int nextId;
    int orderId;
    string item;
    double price;

public:
    Order(const string &itemName, double itemPrice) 
        : orderId(nextId++), item(itemName), price(itemPrice) {}

    int getOrderId() const { return orderId; }
    string getItem() const { return item; }
    double getPrice() const { return price; }

    void display() const {
        cout << "Order ID: #" << orderId << " | Item: " << item 
             << " | Price: Rs. " << price << endl;
    }

    static int getNextAvailableId() {
        return nextId;
    }
};

// Initialize static member to 1001
int Order::nextId = 1001;

int main() {
    cout << "=== DIY 5.3: Auto-Incrementing Unique Order ID Factory ===" << endl;
    cout << "Starting Next ID: " << Order::getNextAvailableId() << endl << endl;

    Order o1("FPGA Development Board", 12500.0);
    Order o2("Digital Oscilloscope", 34000.0);
    Order o3("Logic Analyzer Cable", 850.0);
    Order o4("ARM Cortex-M4 Kit", 4500.0);

    o1.display();
    o2.display();
    o3.display();
    o4.display();

    cout << "\nNext Available Order ID in Factory: " << Order::getNextAvailableId() << endl;

    return 0;
}
