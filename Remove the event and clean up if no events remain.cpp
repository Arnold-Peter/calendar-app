    // Segment 18: Remove the event and clean up if no events remain
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