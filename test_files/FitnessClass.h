#ifndef FITNESSCLASS_H
#define FITNESSCLASS_H

#include <string>
#include <vector>

class FitnessClass {
private:
    std::string className;
    int capacity;
    std::vector<std::string> timeSlots;
    std::vector<std::string> bookings;

public:
    FitnessClass(const std::string& name, int capacity);

    std::string getClassName() const;
    int getCapacity() const;

    bool addTimeSlot(const std::string& time);
    bool bookSlot(const std::string& time);
    bool cancelBooking(const std::string& time);

    void displayAvailableSlots() const;
    void displayBookings() const;
};

#endif //