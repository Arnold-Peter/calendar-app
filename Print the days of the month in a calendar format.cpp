// Segment 7: Print the days of the month in a calendar format
    for (int day = 1; day <= daysInMonth[month - 1]; ++day) {
        std::cout << std::setw(4) << day;
        if ((day + startDay) % 7 == 0)
            std::cout << "\n";
    }
    std::cout << "\n";
}