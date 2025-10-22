
#include <iostream>
#include <string>
using namespace std;

struct Customer {
    string name;
    int roomNumber;
    int days;
    float foodBill;
    bool isBooked;
};

struct FoodItem {
    string name;
    float price;
};

int main() {
    const int TOTAL_ROOMS = 5;
    Customer hotel[TOTAL_ROOMS];

   
    for (int i = 0; i < TOTAL_ROOMS; i++) {
        hotel[i].isBooked = false;
        hotel[i].foodBill = 0;
    }

    
    const int MENU_SIZE = 5;
    FoodItem menu[MENU_SIZE] = {
        {"Pizza", 250},
        {"Burger", 150},
        {"Pasta", 200},
        {"Tea/Coffee", 50},
        {"Thali", 300}
    };

    int choice;
    while (true) {
        cout << "\n===== HOTEL MANAGEMENT SYSTEM =====\n";
        cout << "1. Receptionist - Book Room\n";
        cout << "2. Receptionist - Check Customer Details\n";
        cout << "3. Room Service - Food Order\n";
        cout << "4. Room Service - Cleaning Request\n";
        cout << "5. Generate Bill\n";
        cout << "6. Show All Rooms Status\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7) {
            cout << "Thank you for using Hotel Management System!\n";
            break;
        }

        switch (choice) {
            case 1: {  
                int room;
                cout << "Enter room number (1-" << TOTAL_ROOMS << "): ";
                cin >> room;
                room--;

                if (room < 0 || room >= TOTAL_ROOMS) {
                    cout << "Invalid room number!\n";
                } else if (hotel[room].isBooked) {
                    cout << "Room already booked!\n";
                } else {
                    cout << "Enter customer name: ";
                    cin.ignore();
                    getline(cin, hotel[room].name);
                    cout << "Enter number of days: ";
                    cin >> hotel[room].days;
                    hotel[room].roomNumber = room + 1;
                    hotel[room].isBooked = true;
                    cout << "Room booked successfully by Receptionist!\n";
                }
                break;
            }
            case 2: {   
                int room;
                cout << "Enter room number to check: ";
                cin >> room;
                room--;

                if (room < 0 || room >= TOTAL_ROOMS || !hotel[room].isBooked) {
                    cout << "No customer in this room!\n";
                } else {
                    cout << "\n===== CUSTOMER DETAILS =====\n";
                    cout << "Name: " << hotel[room].name << endl;
                    cout << "Room Number: " << hotel[room].roomNumber << endl;
                    cout << "Stay (days): " << hotel[room].days << endl;
                    cout << "Food Bill: Rs." << hotel[room].foodBill << endl;
                }
                break;
            }
            case 3: {   
                int room;
                cout << "Enter room number for food order: ";
                cin >> room;
                room--;

                if (room < 0 || room >= TOTAL_ROOMS || !hotel[room].isBooked) {
                    cout << "Invalid room or not booked!\n";
                } else {
                    cout << "\n===== FOOD MENU =====\n";
                    for (int i = 0; i < MENU_SIZE; i++) {
                        cout << i + 1 << ". " << menu[i].name << " - Rs." << menu[i].price << endl;
                    }

                    int item, qty;
                    cout << "Enter food item number: ";
                    cin >> item;
                    cout << "Enter quantity: ";
                    cin >> qty;

                    if (item < 1 || item > MENU_SIZE) {
                        cout << "Invalid food choice!\n";
                    } else {
                        hotel[room].foodBill += menu[item - 1].price * qty;
                        cout << "Room Service: " << qty << " " << menu[item - 1].name << " added to bill.\n";
                    }
                }
                break;
            }
            case 4: {   
                int room;
                cout << "Enter room number requesting cleaning: ";
                cin >> room;
                room--;

                if (room < 0 || room >= TOTAL_ROOMS || !hotel[room].isBooked) {
                    cout << "Invalid room!\n";
                } else {
                    cout << "Room Service: Cleaning scheduled for Room " << room + 1 << ".\n";
                }
                break;
            }
            case 5: {   
                int room;
                cout << "Enter room number for bill: ";
                cin >> room;
                room--;

                if (room < 0 || room >= TOTAL_ROOMS || !hotel[room].isBooked) {
                    cout << "Invalid room!\n";
                } else {
                    float roomCost = hotel[room].days * 1000;
                    float totalBill = roomCost + hotel[room].foodBill;
                    cout << "\n===== FINAL BILL =====\n";
                    cout << "Customer: " << hotel[room].name << endl;
                    cout << "Room Charges: Rs." << roomCost << endl;
                    cout << "Food Charges: Rs." << hotel[room].foodBill << endl;
                    cout << "Total Bill: Rs." << totalBill << endl;
                }
                break;
            }
            case 6: {   
                cout << "\nRoom Status:\n";
                for (int i = 0; i < TOTAL_ROOMS; i++) {
                    if (hotel[i].isBooked)
                        cout << "Room " << i + 1 << ": Booked by " << hotel[i].name << endl;
                    else
                        cout << "Room " << i + 1 << ": Empty\n";
                }
                break;
            }
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
