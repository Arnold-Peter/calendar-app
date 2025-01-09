
// Segment 11: Function to view events for a specific date
void viewEvents(const std::map<Date, std::vector<std::string>>& events) {
    Date date;

    // Segment 12: Get the date from the user
    std::cout << "Enter date (day month year): ";
    std::cin >> date.day >> date.month >> date.year;
