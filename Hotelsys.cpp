#include <iostream>
#include <string>
using namespace std;

class Room {
    public:
        int roomNo;
        bool occupied;
        string guestName;

        Room() {
            roomNo = 0;
            occupied = false;
            guestName = "";
        }

        Room(int no) {
            roomNo = no;
            occupied = false;
            guestName = "";
        }

        void bookRoom(string name) {
            if (occupied) {
                cout << "Room " << roomNo << " is already occupied by " << guestName << endl;
            } else {
                occupied = true;
                guestName = name;
                cout << "Room " << roomNo << " is booked by " << guestName << endl;
            }
        }

        void checkout() {
            if (occupied) {
                occupied = false;
                guestName = "";
                cout << "Room " << roomNo << " is now available" << endl;
            } else {
                cout << "Room " << roomNo << " is not occupied" << endl;
            }
        }
};

class Hotel {
    private:
        Room rooms[10];

    public:
        Hotel() {
            for (int i = 0; i < 10; i++) {
                rooms[i] = Room(i+1);
            }
        }

        void bookRoom(int roomNo, string guestName) {
            rooms[roomNo-1].bookRoom(guestName);
        }

        void checkout(int roomNo) {
            rooms[roomNo-1].checkout();
        }

        void printStatus() {
            cout << "Hotel status:" << endl;
            for (int i = 0; i < 10; i++) {
                if (rooms[i].occupied) {
                    cout << "Room " << rooms[i].roomNo << " is occupied by " << rooms[i].guestName << endl;
                } else {
                    cout << "Room " << rooms[i].roomNo << " is available" << endl;
                }
            }
        }
};

int main() {
    Hotel hotel;

    while (true) {
        cout << "1. Book room" << endl;
        cout << "2. Checkout" << endl;
        cout << "3. Print status" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter room number: ";
                int roomNo;
                cin >> roomNo;

                cout << "Enter guest name: ";
                string guestName;
                cin >> guestName;

                hotel.bookRoom(roomNo, guestName);
                break;
            }
            case 2: {
                cout << "Enter room number: ";
                int roomNo;
                cin >> roomNo;

                hotel.checkout(roomNo);
                break;
            }
            case 3: {
                hotel.printStatus();
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                cout << "Invalid choice" << endl;
            }
        }
    }

    return 0;
}
