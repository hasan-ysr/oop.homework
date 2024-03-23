#include <iostream>
#include <string>

using namespace std;

class inventory {
private:
    string name;
    double cost;
    int stock;

public:
    inventory(string n, double c, int s) {
        name = n;
        cost = c;
        stock = s;
    }

    string getname() {
        return name;
    }

    double getCost() {
        return cost;
    }

    int getstock() {
        return stock;
    }

    void setstock(int oh) {
        stock = oh;
    }
};


class CashRegister {
private:
    inventory item;
    int Amount;

public:
    CashRegister(inventory i, int q) : item(i) {
        Amount = q;
    }

    double calculateSubtotal() {
        double unitPrice = item.getCost() * 1.30;
        return unitPrice * Amount;
    }

    double calculatetax(double subtotal) {
        return subtotal * 0.06;
    }

    void displayPurchase() {
        double subtotal = calculateSubtotal();
        double tax = calculatetax(subtotal);
        double total = subtotal + tax;

        cout << "\nDetails:" << endl;
        cout << "-----------------" << endl;
        cout << "Item Name: " << item.getname() << endl;
        cout << "Amount: " << Amount << endl;
        cout << "Purchase Subtotal: $" << subtotal << endl;
        cout << "Sales Tax (6%): $" << tax << endl;
        cout << "Total: $" << total << endl;

        int updatedstock = item.getstock() - Amount;
        item.setstock(updatedstock);
    }
};

int main() {
    inventory apple("apple", 1.25, 100);
    inventory orange("orange", 2.75, 55);
    inventory banana("banana", 5.69, 90);
    inventory watermelon("watermelon", 0.75, 1100);

    cout << "Available Items:" << endl;
    cout << "1. apple - 1.25$" << endl;
    cout << "2. orange - 2.75$" << endl;
    cout << "3. banana - 5.69$" << endl;
    cout << "4. watermelon - 0.75$" << endl;

    int choice, Amount;

    cout << "\nEnter product number:";
    cin >> choice;

    if (choice < 1 || choice > 4) {
        cout << "Invalid choice." << endl;
        return 1;
    }

    cout << "Enter how many you'll buy (kg) : ";
    cin >> Amount;

    if (Amount < 0) {
        cout << "Kg cannot be negative." << endl;
        return 1;
    }

    CashRegister* register1;
    switch (choice) {
        case 1:
            register1 = new CashRegister(apple, Amount);
            break;
        case 2:
            register1 = new CashRegister(orange, Amount);
            break;
        case 3:
            register1 = new CashRegister(banana, Amount);
            break;
        case 4:
            register1 = new CashRegister(watermelon, Amount);
            break;
        default:
            cout << "Invalid choice." << endl;
            return 1;
    }

    register1->displayPurchase();

    delete register1;

    return 0;
}
