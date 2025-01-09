 // Segment 16: Check if events exist for the date
    auto it = events.find(date);
    if (it != events.end()) {
        std::cout << "Events on " << date.day << "/" << date.month << "/" << date.year << ":\n";
        for (size_t i = 0; i < it->second.size(); ++i)
            std::cout << i + 1 << ". " << it->second[i] << "\n";
