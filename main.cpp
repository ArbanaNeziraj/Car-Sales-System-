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
// ==== CAR DATA ====
CarSalesSystem::Car cars[4] = {
    {"Toyota Corolla", "Economy", "Family", 2021, 20000},
    {"VW Golf", "Standard", "Family", 2022, 23500},
    {"BMW 320d", "Luxury", "Sport", 2023, 35000},
    {"Audi A4", "Luxury", "Sport", 2022, 38000}
};

// ==== SELECT CAR ====
int CarSalesSystem::selectCar() {
    int choice;

    cout << "\nAvailable Cars:\n";
    for (int i = 0; i < 4; i++) {
        cout << i + 1 << ". " << cars[i].model
             << " (" << cars[i].category << ", "
             << cars[i].year << ") - "
             << cars[i].basePrice << " EUR\n";
    }

    do {
        cout << "Select car (1-4): ";
        cin >> choice;
    } while (choice < 1 || choice > 4);

    return choice - 1;
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

// ==== VAT ====
double CarSalesSystem::applyVAT(double price) {
    price += price * 0.18;
    cout << "VAT (18%) applied.\n";
    return price;
}

// ==== PAYMENT ====
void CarSalesSystem::paymentMethod(double price) {
    int method;

    cout << "\nPayment Method:\n";
    cout << "1. Cash\n";
    cout << "2. Bank (Monthly)\n";
    cout << "Choice: ";
    cin >> method;

    if (method == 2) {
        int months;
        cout << "Enter months (12 / 24 / 36): ";
        cin >> months;

        price += price * 0.05;
        cout << "Final Price (with interest): " << price << " EUR\n";
        cout << "Monthly Payment: " << price / months << " EUR\n";
    } else {
        cout << "Final Price (Cash): " << price << " EUR\n";
    }
}
