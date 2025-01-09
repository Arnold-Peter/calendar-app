// Function to display the calendar for a given month and year
void displayCalendar(int month, int year) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29; // Leap year adjustment
    std::cout << "\n   Calendar for " << month << "/" << year << "\n";
    std::cout << " Sun Mon Tue Wed Thu Fri Sat\n";