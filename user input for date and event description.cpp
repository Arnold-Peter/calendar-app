 // Segment 9: Get user input for date and event description
    std::cout << "Enter date (day month year): ";
    std::cin >> date.day >> date.month >> date.year;
    std::cin.ignore(); // Clear the newline character from the input buffer
    std::cout << "Enter event description: ";
    std::getline(std::cin, description);
