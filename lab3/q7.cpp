#include <iostream>
#include <string>
using namespace std;

class StationaryShop {
private:
    string items[100];  
    double prices[100]; 
    int itemCount = 0;  

public:
    void addItem(const string& item, double price) {
        if (itemCount < 100) {
            items[itemCount] = item;
            prices[itemCount] = price;
            itemCount++;
            cout << "Item '" << item << "' added with price " << price << "\n";
        } else {
            cout << "Shop is full, cannot add more items.\n";
        }
    }

    void fetchItems() {
        if (itemCount == 0) {
            cout << "No items available.\n";
            return;
        }
        cout << "Items available:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << "\n";
        }
    }

    void editPrice(const string& item, double newPrice) {
        bool found = false;
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == item) {
                prices[i] = newPrice;
                cout << "Price of '" << item << "' updated to " << newPrice << "\n";
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Item not found.\n";
        }
    }

    void viewItems() {
        if (itemCount == 0) {
            cout << "No items in the shop.\n";
            return;
        }
        cout << "Items and their prices:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << ": " << prices[i] << "\n";
        }
    }

    void generateReceipt(string purchases[], int quantities[], int purchaseCount) {
        cout << "\n--- Receipt ---\n";
        double total = 0;
        for (int i = 0; i < purchaseCount; i++) {
            bool found = false;
            for (int j = 0; j < itemCount; j++) {
                if (items[j] == purchases[i]) {
                    double price = prices[j] * quantities[i];
                    total += price;
                    cout << purchases[i] << " x" << quantities[i] << ": " << price << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << purchases[i] << " not found in shop.\n";
            }
        }
        cout << "Total: " << total << "\n";
        cout << "----------------\n";
    }
};

int main() {
    StationaryShop shop;
    int choice;
    while (true) {
        cout << "\n1. Add Item\n";
        cout << "2. Fetch List of Items\n";
        cout << "3. Edit Price\n";
        cout << "4. View Items and Prices\n";
        cout << "5. Generate Receipt\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string item;
            double price;
            cout << "Enter item name: ";
            cin.ignore(); // To clear the input buffer
            getline(cin, item);  // Allows multi-word input
            cout << "Enter item price: ";
            cin >> price;
            shop.addItem(item, price);
        } else if (choice == 2) {
            shop.fetchItems();
        } else if (choice == 3) {
            string item;
            double newPrice;
            cout << "Enter item name to update price: ";
            cin.ignore(); // To clear the input buffer
            getline(cin, item);  // Allows multi-word input
            cout << "Enter new price: ";
            cin >> newPrice;
            shop.editPrice(item, newPrice);
        } else if (choice == 4) {
            shop.viewItems();
        } else if (choice == 5) {
            string purchases[100];  
            int quantities[100];     
            int purchaseCount = 0;
            string item;
            int quantity;
            while (true) {
                cout << "Enter purchased item (or 'done' to finish): ";
                cin.ignore(); 
                getline(cin, item); 
                if (item == "done") break;
                
                bool alreadyAdded = false;
                for (int i = 0; i < purchaseCount; i++) {
                    if (purchases[i] == item) {
                        cout << "Item already in the list, updating quantity.\n";
                        cout << "Enter quantity to add: ";
                        cin >> quantity;
                        quantities[i] += quantity;  
                        alreadyAdded = true;
                        break;
                    }
                }

                if (!alreadyAdded) {
                    purchases[purchaseCount] = item;
                    cout << "Enter quantity: ";
                    cin >> quantity;
                    quantities[purchaseCount] = quantity;
                    purchaseCount++;
                }
            }
            shop.generateReceipt(purchases, quantities, purchaseCount);
        } else if (choice == 6) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
