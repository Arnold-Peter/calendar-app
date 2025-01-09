  // Segment 20: Display the menu and handle user input
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
