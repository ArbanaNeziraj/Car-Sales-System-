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
