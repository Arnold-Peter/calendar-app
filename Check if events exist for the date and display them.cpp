 // Segment 13: Check if events exist for the date and display them
    auto it = events.find(date);
    if (it != events.end()) {
        std::cout << "Events on " << date.day << "/" << date.month << "/" << date.year << ":\n";
        for (size_t i = 0; i < it->second.size(); ++i)
            std::cout << i + 1 << ". " << it->second[i] << "\n";
    } else {
        std::cout << "No events scheduled for this date.\n";
    }
}