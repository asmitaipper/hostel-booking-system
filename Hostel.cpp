#include "Hostel.h"
#include <iostream>

Hostel::Hostel() {
    rooms.push_back({101, 2, 0});
    rooms.push_back({102, 2, 0});
    rooms.push_back({201, 3, 0});
}

void Hostel::showMenu() {
    int choice;
    do {
        std::cout << "\n===== Hostel Booking System =====\n";
        std::cout << "1. List rooms\n";
        std::cout << "2. Add room\n";
        std::cout << "3. Book room\n";
        std::cout << "4. View bookings\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: listRooms();      break;
        case 2: addRoom();        break;
        case 3: bookRoom();       break;
        case 4: viewBookings();   break;
        case 0: std::cout << "Goodbye!\n"; break;
        default: std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}

void Hostel::listRooms() const {
    std::cout << "\nRoom\tCapacity\tOccupied\n";
    for (const auto& r : rooms) {
        std::cout << r.roomNumber << "\t"
                  << r.capacity << "\t\t"
                  << r.occupied << "\n";
    }
}

void Hostel::addRoom() {
    Room r;
    std::cout << "Enter room number: ";
    std::cin >> r.roomNumber;
    std::cout << "Enter capacity: ";
    std::cin >> r.capacity;
    r.occupied = 0;
    rooms.push_back(r);
    std::cout << "Room added.\n";
}

Room* Hostel::findRoom(int roomNumber) {
    for (auto& r : rooms) {
        if (r.roomNumber == roomNumber) return &r;
    }
    return nullptr;
}

void Hostel::bookRoom() {
    int roomNo;
    std::cout << "Enter room number to book: ";
    std::cin >> roomNo;

    Room* room = findRoom(roomNo);
    if (!room) {
        std::cout << "Room not found.\n";
        return;
    }

    if (room->occupied >= room->capacity) {
        std::cout << "Room is full.\n";
        return;
    }

    Booking b;
    b.roomNumber = roomNo;
    std::cout << "Enter student name: ";
    std::cin.ignore();
    std::getline(std::cin, b.studentName);
    std::cout << "Enter student ID: ";
    std::getline(std::cin, b.studentId);

    bookings.push_back(b);
    room->occupied++;
    std::cout << "Room booked successfully.\n";
}

void Hostel::viewBookings() const {
    if (bookings.empty()) {
        std::cout << "No bookings yet.\n";
        return;
    }

    std::cout << "\nRoom\tStudent Name\tStudent ID\n";
    for (const auto& b : bookings) {
        std::cout << b.roomNumber << "\t"
                  << b.studentName << "\t"
                  << b.studentId << "\n";
    }
}
