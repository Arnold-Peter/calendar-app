
        // Segment 17: Let the user choose which event to delete
        int choice;
        std::cout << "Enter the number of the event to delete: ";
        std::cin >> choice;

        if (choice > 0 && choice <= static_cast<int>(it->second.size())) {