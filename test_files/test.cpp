#include <iostream>
#include "FitnessClass.h"

using namespace std;

int main()
{
    // Create a FitnessClass object
    FitnessClass yoga("Yoga", 10);

    // Add some time slots
    yoga.addTimeSlot("Monday 9:00 AM");
    yoga.addTimeSlot("Wednesday 6:00 PM");

    // User Interface
    cout << "Welcome to the Fitness Class Booking System" << endl;
    cout << "Available Fitness Class: " << yoga.getClassName() << endl;
    cout << "Capacity: " << yoga.getCapacity() << " people" << endl;

    // Display available time slots
    yoga.displayAvailableSlots();

    // Booking
    string selectedTime;
    cout << "Enter the time slot you want to book: ";
    getline(cin, selectedTime);

    // Attempt to book the selected time slot
    if (yoga.bookSlot(selectedTime)) {
        cout << "Booking successful for " << selectedTime << endl;
    } else {
        cout << "Sorry, the selected time slot is fully booked or invalid." << endl;
    }

    // Display updated bookings
    cout << "Updated Bookings:" << endl;
    yoga.displayBookings();

    return 0;
}
//method defination
FitnessClass::FitnessClass(const string& name, int capacity) : className(name), capacity(capacity) {}

std::string FitnessClass::getClassName() const
{
    return className;
}

int FitnessClass::getCapacity() const
{
    return capacity;
}

bool FitnessClass::addTimeSlot(const string& time)
{
    timeSlots.push_back(time);
    return true;
}

bool FitnessClass::bookSlot(const string& time)
{
    if (bookings.size() < capacity)
    {
        bookings.push_back(time);
        return true;
    }
    return false; // Capacity reached
}

bool FitnessClass::cancelBooking(const string& time)
{
    for (auto it = bookings.begin(); it != bookings.end(); ++it)
    {
        if (*it == time)
        {
            bookings.erase(it);
            return true;
        }
    }
    return false; // Booking not found
}

void FitnessClass::displayAvailableSlots() const
{
    cout << "Available time slots for " << className << " class:" << endl;
    for(const auto& slot : timeSlots)
    {
        cout << slot << endl;
    }
}

void FitnessClass::displayBookings() const
{
    cout << "Bookings for " << className << " class:" << endl;
    for (const auto& booking : bookings)
    {
        cout << booking << endl;
    }
}