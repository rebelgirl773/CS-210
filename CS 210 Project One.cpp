// CS 210 Project One.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Sydney Porter

#include <iostream>
#include <iomanip>
#include <ctime>

class Clock {
private:
    std::time_t currentTime;

    // Function to format numbers as two digits
    std::string formatTwoDigits(int number) const {
        return (number < 10) ? "0" + std::to_string(number) : std::to_string(number);
    }

    // Function to output time in 24-hour format
    void outputTime24HourFormat() const {
        std::tm* localTime = std::localtime(&currentTime);
        std::cout << "24-Hour Clock: " << formatTwoDigits(localTime->tm_hour) << ":"
            << formatTwoDigits(localTime->tm_min) << ":" << formatTwoDigits(localTime->tm_sec) << std::endl;
    }

    // Function to output time in 12-hour format
    void outputTime12HourFormat() const {
        std::tm* localTime = std::localtime(&currentTime);
        std::cout << "12-Hour Clock: " << formatTwoDigits((localTime->tm_hour % 12 == 0) ? 12 : localTime->tm_hour % 12) << ":"
            << formatTwoDigits(localTime->tm_min) << ":" << formatTwoDigits(localTime->tm_sec)
            << ((localTime->tm_hour < 12) ? " AM" : " PM") << std::endl;
    }

public:
    Clock() {
        // Initialize the current time
        resetToMidnight();
    }

    // Function to add a second to the clock's time
    void addSecond() {
        currentTime += 1;
    }

    // Function to add a minute to the clock's time
    void addMinute() {
        currentTime += 60;
    }

    // Function to add an hour to the clock's time
    void addHour() {
        currentTime += 3600;
    }

    // Reset it back to midnight
    void resetToMidnight() {
        std::tm midnight = {};
        midnight.tm_hour = midnight.tm_min = midnight.tm_sec = 0;
        currentTime = std::mktime(&midnight);
    }

    // Function to print out the menu
    static void printMenu() {
        std::cout << "1. Update time\n";
        std::cout << "2. Display 12-hour clock\n";
        std::cout << "3. Display 24-hour clock\n";
        std::cout << "4. Add a second\n";
        std::cout << "5. Add a minute\n";
        std::cout << "6. Add an hour\n";
        std::cout << "7. Reset to midnight\n";
        std::cout << "8. Exit\n";
    }

    // Function to process user input for the clock
    void processUserInput() {
        int choice;
        do {
            printMenu();
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                updateCurrentTime();
                std::cout << "Time updated.\n";
                break;
            case 2:
                outputTime12HourFormat();
                break;
            case 3:
                outputTime24HourFormat();
                break;
            case 4:
                addSecond();
                std::cout << "One second added.\n";
                break;
            case 5:
                addMinute();
                std::cout << "One minute added.\n";
                break;
            case 6:
                addHour();
                std::cout << "One hour added.\n";
                break;
            case 7:
                resetToMidnight();
                std::cout << "Clock reset to midnight.\n";
                break;
            case 8:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }

        } while (choice != 8);
    }
};

int main() {
    Clock clock;

    // Process user input for the clock
    clock.processUserInput();

    return 0;
}
