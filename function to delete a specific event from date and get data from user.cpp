
// Segment 14: Function to delete a specific event from a date
void deleteEvent(std::map<Date, std::vector<std::string>>& events) {
    Date date;

    // Segment 15: Get the date from the user
    std::cout << "Enter date (day month year): ";
    std::cin >> date.day >> date.month >> date.year;
