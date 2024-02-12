/*
 * clock.cpp
 *
 *  Date: 01.27.2024
 *  Author: Shpetim Racaj
 */



#include <iostream>
#include <iomanip>   // Needed for setw and setfill to format the clock display
#include <windows.h>

using namespace std;

struct Clock {
    int hour, minute, second;

    Clock() : hour(0), minute(0), second(0) {}  //Constructor to initialize clock to 00:00:00

    void addHour() {
        hour = (hour + 1) % 24;
    }

    void addMinute() {
        minute = (minute + 1) % 60;
        if (minute == 0) addHour();
    }

    void addSecond() {
        second = (second + 1) % 60;
        if (second == 0) addMinute();
    }

    void display() const {
        char colon = ':';
        string ampm = hour < 12 ? "AM" : "PM";
        int hour12 = hour % 12;
        if (hour12 == 0) hour12 = 12;

        cout << "**************************\t**************************" << endl;
        cout << "*     12-Hour Clock      *\t*     24-Hour Clock      *" << endl;
        cout << "*       " << setw(2) << setfill('0') << hour12 << colon 
             << setw(2) << setfill('0') << minute << colon 
             << setw(2) << setfill('0') << second << " " << ampm 
             << "      *\t*       " << setw(2) << setfill('0') << hour << colon 
             << setw(2) << setfill('0') << minute << colon 
             << setw(2) << setfill('0') << second 
             << "         *" << endl;
        cout << "**************************\t**************************" << endl;
    }
};

void displayTime(const Clock& clock) {
    system("cls"); // Clear the screen for a clean display
    clock.display(); // Display the current time
}

int main() {
    Clock clock;
    int choice;
    // Prompt user for initial time
    cout << "Enter initial time in HH MM SS format (e.g., 01 02 03 for 1 hour, 2 minutes, and 3 seconds): ";
    if (!(cin >> clock.hour >> clock.minute >> clock.second)) {
        cout << "Invalid input format." << endl;
        return 1;
    }

    if (clock.hour < 0 || clock.hour >= 24 || clock.minute < 0 || clock.minute >= 60 || clock.second < 0 || clock.second >= 60) {
        cout << "Invalid time. Please ensure hours are 0-23, minutes and seconds are 0-59." << endl;
        return 1;
    }

    do {
        displayTime(clock); // Display the current time
        cout << "\n1. Add Hour\n2. Add Minute\n3. Add Second\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) clock.addHour();
        else if (choice == 2) clock.addMinute();
        else if (choice == 3) clock.addSecond();
        else if (choice == 4) break; // Exit the loop to end the program
        else cout << "Invalid option. Please try again.\n"; // Handle invalid input

    } while (true);  // Repeat until user chooses to exit

    return 0;
}
