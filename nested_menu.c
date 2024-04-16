#include <ncurses.h>

int main() {
    // Initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);

    // Print a welcome message
    printw("Welcome to the Sample Application\n\n");
    refresh();

    // Define main menu items
    char *main_menu_items[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit"
    };
    // Define submenu items for Option 1
    char *submenu1_items[] = {
        "Submenu 1 Option 1",
        "Submenu 1 Option 2",
        "Back"
    };
    // Define submenu items for Option 2
    char *submenu2_items[] = {
        "Submenu 2 Option 1",
        "Submenu 2 Option 2",
        "Back"
    };
    // Define submenu items for Option 3
    char *submenu3_items[] = {
        "Submenu 3 Option 1",
        "Submenu 3 Option 2",
        "Back"
    };

    int main_choice;
    int highlight_main = 0;
    int highlight_submenu;

    // Display main menu
    while (1) {
        clear();
        // Print main menu
        for (int i = 0; i < 4; i++) {
            if (i == highlight_main) {
                attron(A_REVERSE);
            }
            mvprintw(i + 1, 1, "%s", main_menu_items[i]);
            attroff(A_REVERSE);
        }
        refresh();

        // Get user input for main menu
        main_choice = getch();

        switch (main_choice) {
            case KEY_UP:
                highlight_main = (highlight_main == 0) ? 3 : (highlight_main - 1);
                break;
            case KEY_DOWN:
                highlight_main = (highlight_main == 3) ? 0 : (highlight_main + 1);
                break;
            case 10: // Enter key pressed
                // Handle main menu selection
                switch (highlight_main) {
                    case 0: // Option 1 selected
                        highlight_submenu = 0;
                        // Display submenu 1
                        while (1) {
                            clear();
                            // Print submenu 1
                            for (int i = 0; i < 3; i++) {
                                if (i == highlight_submenu) {
                                    attron(A_REVERSE);
                                }
                                mvprintw(i + 1, 1, "%s", submenu1_items[i]);
                                attroff(A_REVERSE);
                            }
                            refresh();

                            // Get user input for submenu 1
                            int submenu_choice = getch();

                            switch (submenu_choice) {
                                case KEY_UP:
                                    highlight_submenu = (highlight_submenu == 0) ? 2 : (highlight_submenu - 1);
                                    break;
                                case KEY_DOWN:
                                    highlight_submenu = (highlight_submenu == 2) ? 0 : (highlight_submenu + 1);
                                    break;
                                case 10: // Enter key pressed
                                    // Handle submenu 1 selection
                                    if (highlight_submenu == 0) {
                                        // Submenu 1 Option 1 selected
                                        printw("Submenu 1 Option 1 selected\n");
                                        refresh();
                                        getch(); // Wait for user to press any key
                                    } else if (highlight_submenu == 1) {
                                        // Submenu 1 Option 2 selected
                                        printw("Submenu 1 Option 2 selected\n");
                                        refresh();
                                        getch(); // Wait for user to press any key
                                    } else {
                                        // Back selected, break out of submenu loop
                                        break;
                                    }
                                    break;
                            }
                        }
                        break;
                    case 1: // Option 2 selected
                        highlight_submenu = 0;
                        // Display submenu 2
                        while (1) {
                            clear();
                            // Print submenu 2
                            for (int i = 0; i < 3; i++) {
                                if (i == highlight_submenu) {
                                    attron(A_REVERSE);
                                }
                                mvprintw(i + 1, 1, "%s", submenu2_items[i]);
                                attroff(A_REVERSE);
                            }
                            refresh();

                            // Get user input for submenu 2
                            int submenu_choice = getch();

                            switch (submenu_choice) {
                                case KEY_UP:
                                    highlight_submenu = (highlight_submenu == 0) ? 2 : (highlight_submenu - 1);
                                    break;
                                case KEY_DOWN:
                                    highlight_submenu = (highlight_submenu == 2) ? 0 : (highlight_submenu + 1);
                                    break;
                                case 10: // Enter key pressed
                                    // Handle submenu 2 selection
                                    if (highlight_submenu == 0) {
                                        // Submenu 2 Option 1 selected
                                        printw("Submenu 2 Option 1 selected\n");
                                        refresh();
                                        getch(); // Wait for user to press any key
                                    } else if (highlight_submenu == 1) {
                                        // Submenu 2 Option 2 selected
                                        printw("Submenu 2 Option 2 selected\n");
                                        refresh();
                                        getch(); // Wait for user to press any key
                                    } else {
                                        // Back selected, break out of submenu loop
                                        break;
                                    }
                                    break;
                            }
                        }
                        break;
                    case 2: // Option 3 selected
                        highlight_submenu = 0;
                        // Display submenu 3
                        while (1) {
                            clear();
                            // Print submenu 3
                            for (int i = 0; i < 3; i++) {
                                if (i == highlight_submenu) {
                                    attron(A_REVERSE);
                                }
                                mvprintw(i + 1, 1, "%s", submenu3_items[i]);
                                attroff(A_REVERSE);
                            }
                            refresh();

                            // Get user input for submenu 3
                            int submenu_choice = getch();

                            switch (submenu_choice) {
                                case KEY_UP:
                                    highlight_submenu = (highlight_submenu == 0) ? 2 : (highlight_submenu - 1);
                                    break;
                                case KEY_DOWN:
                                    highlight_submenu = (highlight_submenu == 2) ? 0 : (highlight_submenu + 1);
                                    break;
                                case 10: // Enter key pressed
                                    // Handle submenu 3 selection
                                    if (highlight_submenu == 0) {
                                        // Submenu 3 Option 1 selected
                                        printw("Submenu 3 Option 1 selected\n");
                                        refresh();
                                        getch(); // Wait for user to press any key
                                    } else if (highlight_submenu == 1) {
                                        // Submenu 3 Option 2 selected
                                        printw("Submenu 3 Option 2 selected\n");
                                        refresh();
                                        getch(); // Wait for user to press any key
                                    } else {
                                        // Back selected, break out of submenu loop
                                        break;
                                    }
                                    break;
                            }
                        }
                        break;
                    case 3: // Exit selected
                        // Clean up and exit
                        endwin();
                        return 0;
                }
                break;
        }
    }

    // Clean up and exit (should never reach here)
    endwin();
    return 0;
}

