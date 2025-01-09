
//header files
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <string>





// Define Date structure
struct Date {
    int day, month, year;

    // Comparison operator for map keys
    bool operator<(const Date& other) const {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }
};








// Function to display the calendar for a given month and year
void displayCalendar(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29; // Leap year adjustment





    std::cout << "\n   Calendar for " << month << "/" << year << "\n";
    std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";




    // Zeller's Congruence to find the starting day of the month
    int d = 1, m = (month < 3) ? month + 12 : month, y = (month < 3) ? year - 1 : year;
    int startDay = (d + (13 * (m + 1)) / 5 + y + (y / 4) - (y / 100) + (y / 400)) % 7;





    // Print leading spaces
    for (int i = 0; i < startDay; ++i)
        std::cout << "    ";





    // Print days
    for (int day = 1; day <= daysInMonth[month - 1]; ++day) {
        std::cout << std::setw(4) << day;
        if ((day + startDay) % 7 == 0)
            std::cout << "\n";
    }
    std::cout << "\n";
}





// Function to add an event
void addEvent(std::map<Date, std::vector<std::string>>& events) {
    Date date;
    std::string description;

    std::cout << "Enter date (day month year): ";
    std::cin >> date.day >> date.month >> date.year;
    std::cin.ignore(); // Clear the newline character from the input buffer




    std::cout << "Enter event description: ";
    std::getline(std::cin, description);

    events[date].push_back(description);
    std::cout << "Event added successfully!\n";
}



// Function to view events for a specific date
void viewEvents(const std::map<Date, std::vector<std::string>>& events) {
    Date date;
    std::cout << "Enter date (day month year): ";
    std::cin >> date.day >> date.month >> date.year;

    auto it = events.find(date);
    if (it != events.end()) {
        std::cout << "Events on " << date.day << "/" << date.month << "/" << date.year << ":\n";
        for (size_t i = 0; i < it->second.size(); ++i)
            std::cout << i + 1 << ". " << it->second[i] << "\n";
    } else {
        std::cout << "No events scheduled for this date.\n";
    }
}





// Function to delete an event
void deleteEvent(std::map<Date, std::vector<std::string>>& events) {
    Date date;
    std::cout << "Enter date (day month year): ";
    std::cin >> date.day >> date.month >> date.year;

    auto it = events.find(date);
    if (it != events.end()) {
        std::cout << "Events on " << date.day << "/" << date.month << "/" << date.year << ":\n";
        for (size_t i = 0; i < it->second.size(); ++i)
            std::cout << i + 1 << ". " << it->second[i] << "\n";

        int choice;
        std::cout << "Enter the number of the event to delete: ";
        std::cin >> choice;

        if (choice > 0 && choice <= static_cast<int>(it->second.size())) {
            it->second.erase(it->second.begin() + choice - 1);
            if (it->second.empty())
                events.erase(it); // Remove date if no events remain
            std::cout << "Event deleted successfully!\n";
        } else {
            std::cout << "Invalid choice.\n";
        }
    } else {
        std::cout << "No events scheduled for this date.\n";
    }
}

int main() {
    std::map<Date, std::vector<std::string>> events;
    int choice;

    do {
        std::cout << "\nCalendar Application\n";
        std::cout << "1. Display Calendar\n";
        std::cout << "2. Add Event\n";
        std::cout << "3. View Events\n";
        std::cout << "4. Delete Event\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int month, year;
                std::cout << "Enter month and year: ";
                std::cin >> month >> year;
                displayCalendar(month, year);
                break;
            }
            case 2:
                addEvent(events);
                break;
            case 3:
                viewEvents(events);
                break;
            case 4:
                deleteEvent(events);
                break;
            case 5:
                std::cout << "Exiting the application.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
