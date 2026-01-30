#ifndef HOSTEL_H
#define HOSTEL_H

#include <string>
#include <vector>

struct Room {
    int roomNumber;
    int capacity;
    int occupied;
};

struct Booking {
    int roomNumber;
    std::string studentName;
    std::string studentId;
};

class Hostel {
public:
    Hostel();

    void showMenu();
    void listRooms() const;
    void addRoom();
    void bookRoom();
    void viewBookings() const;

private:
    std::vector<Room> rooms;
    std::vector<Booking> bookings;

    Room* findRoom(int roomNumber);
};

#endif
