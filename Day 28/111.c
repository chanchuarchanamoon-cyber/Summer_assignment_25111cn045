#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 10

// Structure to hold movie details
typedef struct {
    int id;
    char title[50];
    float price;
    int seats[ROWS][COLS]; // 0 = Available, 1 = Booked
} Movie;

// Function prototypes
void initMovies(Movie *m);
void displayMovies(Movie *m, int count);
void displaySeats(Movie m);
void bookTicket(Movie *m);
void cancelTicket(Movie *m);

int main() {
    Movie movies[3];
    initMovies(movies);
    int choice;

    while (1) {
        printf("\n==================================\n");
        printf("   MOVIE TICKET BOOKING SYSTEM    \n");
        printf("==================================\n");
        printf("1. View Movies & Showtimes\n");
        printf("2. View Seating Map\n");
        printf("3. Book a Ticket\n");
        printf("4. Cancel a Ticket\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                displayMovies(movies, 3);
                break;
            case 2: {
                int mId;
                displayMovies(movies, 3);
                printf("Enter Movie ID to view seats: ");
                scanf("%d", &mId);
                if (mId >= 1 && mId <= 3) {
                    displaySeats(movies[mId - 1]);
                } else {
                    printf("Invalid Movie ID!\n");
                }
                break;
            }
            case 3:
                bookTicket(movies);
                break;
            case 4:
                cancelTicket(movies);
                break;
            case 5:
                printf("Thank you for using the system!\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Initialize system with hardcoded movies and empty seats
void initMovies(Movie *m) {
    char titles[][50] = {"Inception", "Interstellar", "The Dark Knight"};
    float prices[] = {12.50, 10.00, 15.00};

    for (int i = 0; i < 3; i++) {
        m[i].id = i + 1;
        strcpy(m[i].title, titles[i]);
        m[i].price = prices[i];
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                m[i].seats[r][c] = 0; 
            }
        }
    }
}

// Display available movies
void displayMovies(Movie *m, int count) {
    printf("\nAvailable Movies:\n");
    printf("--------------------------------------------------\n");
    printf("%-5s %-25s %-10s\n", "ID", "Title", "Price");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-25s $%-9.2f\n", m[i].id, m[i].title, m[i].price);
    }
    printf("--------------------------------------------------\n");
}

// Display visual seating layout
void displaySeats(Movie m) {
    printf("\nSeating Map for: %s\n", m.title);
    printf("   ");
    for (int c = 0; c < COLS; c++) printf("%2d ", c + 1);
    printf("\n");

    for (int r = 0; r < ROWS; r++) {
        printf("%c: ", 'A' + r);
        for (int c = 0; c < COLS; c++) {
            if (m.seats[r][c] == 0) {
                printf("[O]"); // Available
            } else {
                printf("[X]"); // Booked
            }
        }
        printf("\n");
    }
    printf("\nLegend: [O] = Available  [X] = Booked\n");
}

// Ticket booking logic
void bookTicket(Movie *m) {
    int mId, col;
    char rowChar;
    
    displayMovies(m, 3);
    printf("Enter Movie ID to book: ");
    scanf("%d", &mId);

    if (mId < 1 || mId > 3) {
        printf("Invalid Movie ID!\n");
        return;
    }

    Movie *selectedMovie = &m[mId - 1];
    displaySeats(*selectedMovie);

    printf("Enter Row letter (A-%c) and Seat number (1-%d) [e.g., B 4]: ", 'A' + ROWS - 1, COLS);
    scanf(" %c %d", &rowChar, &col);

    int row = rowChar - 'A';
    col--; // Convert to 0-indexed array

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid seat position!\n");
        return;
    }

    if (selectedMovie->seats[row][col] == 1) {
        printf("Sorry, this seat is already booked!\n");
    } else {
        selectedMovie->seats[row][col] = 1;
        printf("Booking successful! Total cost: $%.2f\n", selectedMovie->price);
    }
}

// Ticket cancellation logic
void cancelTicket(Movie *m) {
    int mId, col;
    char rowChar;

    printf("Enter Movie ID to cancel booking: ");
    scanf("%d", &mId);

    if (mId < 1 || mId > 3) {
        printf("Invalid Movie ID!\n");
        return;
    }

    Movie *selectedMovie = &m[mId - 1];
    printf("Enter Row letter and Seat number to cancel [e.g., B 4]: ");
    scanf(" %c %d", &rowChar, &col);

    int row = rowChar - 'A';
    col--;

    if (row < 0 || row >= ROWS || col < 0 || col >= COLS) {
        printf("Invalid seat position!\n");
        return;
    }

    if (selectedMovie->seats[row][col] == 0) {
        printf("This seat is already empty!\n");
    } else {
        selectedMovie->seats[row][col] = 0;
        printf("Cancellation successful. Refund processed.\n");
    }
    return 0;
}
