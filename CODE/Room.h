#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>

class Room
{
    private:
        std::string roomNumber;
        std::string slot;
        std::string day;
    public:
        Room() = default;
        Room(std::string roomNumber) : roomNumber(roomNumber) {}
        Room(std::string slot) : roomNumber(slot) {}
        Room(std::string day) : day(day) {}
        Room(std::string roomNumber, std::string slot , std::string day) : roomNumber(roomNumber), slot(slot), day(day) {}
        std::string getRoomNumber() const;
        std::string getSlot() const;
        std::string getDay() const;
        void setDay(std::string day);
        void setRoomNumber(std::string roomNumber);
        void setSlot(std::string slot);
};

#endif