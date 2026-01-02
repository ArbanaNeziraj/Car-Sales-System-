#include <iostream>
#include <string>
using namespace std;

class CarSalesSystem {
private:
    struct Car {
        string model;
        string carClass;
        string category;
        int year;
        double basePrice;
    };

public:
    void runSystem();
    int selectCar();
    double applyDiscount(double price, string category);
    double applyExtras(double price);
    double applyVAT(double price);
    void paymentMethod(double price);
};

void CarSalesSystem::runSystem() {
    int choice;

    while (true) {
        cout << "\n===== CAR SALES SYSTEM =====\n";
        cout << "1. Buy a Car\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice == 1) {
            int index = selectCar();
            double price = 0;

            price = applyDiscount(price, "");
            price = applyExtras(price);
            price = applyVAT(price);

            paymentMethod(price);
        } else {
            cout << "Invalid option.\n";
        }
    }
}

int main() {
    CarSalesSystem system;
    system.runSystem();
    return 0;
}
// ==== DISCOUNT ====
double CarSalesSystem::applyDiscount(double price, string category) {
    double discount;
    int maxDiscount = (category == "Family") ? 25 : 10;

    cout << category << " discount (0-" << maxDiscount << "%): ";
    do {
        cin >> discount;
    } while (discount < 0 || discount > maxDiscount);

    price -= price * discount / 100;
    cout << "Price after discount: " << price << " EUR\n";
    return price;
}

// ==== EXTRAS ====
double CarSalesSystem::applyExtras(double price) {
    int color, gear;

    cout << "\nColor Options:\n";
    cout << "1. Standard (0 EUR)\n";
    cout << "2. Special (+500 EUR)\n";
    cout << "Choice: ";
    cin >> color;

    if (color == 2) price += 500;

    cout << "\nGear Options:\n";
    cout << "1. Manual (-800 EUR)\n";
    cout << "2. Automatic (+1200 EUR)\n";
    cout << "Choice: ";
    cin >> gear;

    if (gear == 1) price -= 800;
    else if (gear == 2) price += 1200;

    cout << "Price after extras: " << price << " EUR\n";
    return price;
}


