#include <iostream>
#include <string>

using namespace std;

class MenuItem {
private:
    string foodName;
    double foodPrice;

public:
    MenuItem() : foodName(""), foodPrice(0.0) {}  
    MenuItem(string name, double price) : foodName(name), foodPrice(price) {}

    string getName() { return foodName; }
    double getPrice() { return foodPrice; }

    void displayItem() {
        cout << foodName << " - $" << foodPrice << endl;
    }
};

class Menu {
private:
    MenuItem* items;
    int itemCount;
    int capacity;

public:
    Menu(int cap = 10) : itemCount(0), capacity(cap) {
        items = new MenuItem[capacity];
    }

    ~Menu() { delete[] items; }

    void addItem(string name, double price) {
        if (itemCount < capacity) {
            items[itemCount] = MenuItem(name, price);
            itemCount++;
        } else {
            cout << "Menu is full, cannot add more items.\n";
        }
    }

    void displayMenu() {
        cout << "\n----- MENU -----\n";
        for (int i = 0; i < itemCount; i++) {
            cout << i + 1 << ". ";
            items[i].displayItem();
        }
        cout << "----------------\n";
    }

    MenuItem getItem(int index) {
        if (index >= 0 && index < itemCount) {
            return items[index];
        } else {
            cout << "Invalid item selection.\n";
            return MenuItem();
        }
    }

    int getItemCount() { return itemCount; }
};

class Payment {
private:
    double amount;
    string paymentMethod;

public:
    Payment() : amount(0.0), paymentMethod("Unpaid") {}
    Payment(double amt, string method) : amount(amt), paymentMethod(method) {}

    void displayPayment() {
        cout << "Total Amount: $" << amount << "\nPayment Method: " << paymentMethod << endl;
    }
};

class Order {
private:
    MenuItem* orderedItems;
    int itemCount;
    double totalPrice;
    Payment payment;
    int capacity;

public:
    Order(int cap = 10) : itemCount(0), totalPrice(0.0), capacity(cap) {
        orderedItems = new MenuItem[capacity];
    }

    ~Order() { delete[] orderedItems; }

    void addItem(MenuItem item) {
        if (itemCount < capacity) {
            orderedItems[itemCount] = item;
            totalPrice += item.getPrice();
            itemCount++;
        } else {
            cout << "Cannot add more items to the order.\n";
        }
    }

    void finalizePayment(string method) {
        payment = Payment(totalPrice, method);
    }

    void displayOrder() {
        cout << "\n----- ORDER DETAILS -----\n";
        for (int i = 0; i < itemCount; i++) {
            orderedItems[i].displayItem();
        }
        cout << "--------------------------\n";
        payment.displayPayment();
    }
};

class RestaurantOrderingSystem {
private:
    Menu menu;

public:
    RestaurantOrderingSystem() : menu(10) {}

    void initializeMenu() {
        menu.addItem("Burger", 5.99);
        menu.addItem("Pizza", 8.99);
        menu.addItem("Pasta", 7.49);
        menu.addItem("Salad", 4.99);
        menu.addItem("Soda", 1.99);
    }

    void takeOrder() {
        Order order;
        int choice;
        char more;

        menu.displayMenu();

        do {
            cout << "Enter item number to order: ";
            cin >> choice;

            if (choice > 0 && choice <= menu.getItemCount()) {
                order.addItem(menu.getItem(choice - 1));
            } else {
                cout << "Invalid choice, try again.\n";
            }

            cout << "Do you want to order more? (y/n): ";
            cin >> more;

        } while (more == 'y' || more == 'Y');

        string method;
        cout << "Enter payment method (Cash/Card): ";
        cin >> method;
        order.finalizePayment(method);

        order.displayOrder();
    }

    void run() {
        initializeMenu();
        takeOrder();
    }
};

int main() {
    RestaurantOrderingSystem system;
    system.run();
    return 0;
}
