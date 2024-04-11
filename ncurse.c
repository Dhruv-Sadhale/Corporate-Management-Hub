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

    // Define menu items
    char *menu_items[] = {
        "Option 1",
        "Option 2",
        "Option 3",
        "Exit"
    };
    int choice;
    int highlight = 0;

    // Display menu
    while (1) {
        clear();
        for (int i = 0; i < 4; i++) {
            if (i == highlight) {
                attron(A_REVERSE);
            }
mvprintw(i + 1, 1, "%s", menu_items[i]);

            attroff(A_REVERSE);
        }

        // Get user input
        choice = getch();

        switch (choice) {
            case KEY_UP:
                highlight = (highlight == 0) ? 3 : (highlight - 1);
                break;
            case KEY_DOWN:
                highlight = (highlight == 3) ? 0 : (highlight + 1);
                break;
            default:
                break;
        }

        if (choice == 10) {
            break;  // Exit loop on Enter key press
        }
    }

    // Clean up and exit
    endwin();
    return 0;
}

