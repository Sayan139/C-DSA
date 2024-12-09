#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room {
public:
    int roomNumber;
    string type;
    bool isBooked;

    Room(int number, string t, bool booked = false) 
        : roomNumber(number), type(t), isBooked(booked) {}

    void displayRoomDetails() {
        cout << "Room Number: " << roomNumber
             << " | Type: " << type
             << " | Status: " << (isBooked ? "Booked" : "Available") << endl;
    }
};

class Guest {
public:
    string name;
    int roomNumber;

    Guest(string guestName, int roomNum) 
        : name(guestName), roomNumber(roomNum) {}

    void displayGuestDetails() {
        cout << "Guest Name: " << name
             << " | Room Number: " << roomNumber << endl;
    }
};

class HotelManagementSystem {
private:
    vector<Room> rooms;
    vector<Guest> guests;

public:
    HotelManagementSystem() {
        rooms.push_back(Room(101, "Single"));
        rooms.push_back(Room(102, "Double"));
        rooms.push_back(Room(103, "Suite"));
    }

    void displayRooms() {
        for (auto& room : rooms) {
            room.displayRoomDetails();
        }
    }

    void bookRoom(string guestName, int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber) {
                if (room.isBooked) {
                    cout << "Room " << roomNumber << " is already booked.\n";
                    return;
                }
                room.isBooked = true;
                guests.push_back(Guest(guestName, roomNumber));
                cout << "Room " << roomNumber << " successfully booked for " << guestName << ".\n";
                return;
            }
        }
        cout << "Room " << roomNumber << " not found.\n";
    }

    void displayGuests() {
        if (guests.empty()) {
            cout << "No guests currently checked in.\n";
            return;
        }
        for (auto& guest : guests) {
            guest.displayGuestDetails();
        }
    }

    void checkoutGuest(int roomNumber) {
        for (auto& room : rooms) {
            if (room.roomNumber == roomNumber && room.isBooked) {
                room.isBooked = false;
                for (auto it = guests.begin(); it != guests.end(); ++it) {
                    if (it->roomNumber == roomNumber) {
                        guests.erase(it);
                        cout << "Guest checked out from room " << roomNumber << ".\n";
                        return;
                    }
                }
            }
        }
        cout << "Room " << roomNumber << " is not currently booked.\n";
    }
};

int main() {
    HotelManagementSystem hms;
    int choice, roomNumber;
    string guestName;

    while (true) {
        cout << "\nHotel Management System Menu\n";
        cout << "1. Display Rooms\n";
        cout << "2. Book Room\n";
        cout << "3. Display Guests\n";
        cout << "4. Checkout Guest\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hms.displayRooms();
            break;
        case 2:
            cout << "Enter Guest Name: ";
            cin >> guestName;
            cout << "Enter Room Number: ";
            cin >> roomNumber;
            hms.bookRoom(guestName, roomNumber);
            break;
        case 3:
            hms.displayGuests();
            break;
        case 4:
            cout << "Enter Room Number to checkout: ";
            cin >> roomNumber;
            hms.checkoutGuest(roomNumber);
            break;
        case 5:
            cout << "Exiting system.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
