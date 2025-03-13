#include <iostream>
#include <Windows.h>
#include <string>
using namespace std;

struct Serial {
    string title;
    string genre;
    int episodes;
    int seasons;
    double rating;
    int releaseYear;
};

// Function to display all serials
void showAllSerials(Serial serials[], int size) {
    cout << "List of all serials:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Title: " << serials[i].title
            << ", Genre: " << serials[i].genre
            << ", Episodes: " << serials[i].episodes
            << ", Seasons: " << serials[i].seasons
            << ", Rating: " << serials[i].rating
            << ", Release Year: " << serials[i].releaseYear << endl;
    }
}

// Function to find serials by rating
void findByRating(Serial serials[], int size, double minRating) {
    cout << "Serials with a rating above " << minRating << ":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (serials[i].rating >= minRating) {
            cout << serials[i].title << " - Rating: " << serials[i].rating << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No serials found with this rating." << endl;
    }
}

// Function to find serials by genre
void findByGenre(Serial serials[], int size, string genre) {
    cout << "Serials in the genre " << genre << ":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (serials[i].genre == genre) {
            cout << serials[i].title << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No serials found in this genre." << endl;
    }
}

// Function to find serials by release year
void findByReleaseYear(Serial serials[], int size, int year) {
    cout << "Serials released in " << year << ":" << endl;
    bool found = false;
    for (int i = 0; i < size; i++) {
        if (serials[i].releaseYear == year) {
            cout << serials[i].title << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No serials found released in this year." << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int size = 6; // number of serials
    Serial serials[size] = {
        {"Breaking Bad", "Drama", 62, 5, 9.5, 2008},
        {"Game of Thrones", "Fantasy", 73, 8, 9.3, 2011},
        {"Stranger Things", "Sci-Fi", 34, 4, 8.7, 2016},
        {"Chernobyl", "History", 5, 1, 9.4, 2019},
        {"The Office", "Comedy", 201, 9, 8.9, 2005},
        {"Friends", "Comedy", 236, 10, 8.8, 1994}
    };

    showAllSerials(serials, size);
    cout << endl;

    int Choice;
    do {
        cout << "Select an attribute for search:" << endl;
        cout << "1. Rating" << endl;
        cout << "2. Genre" << endl;
        cout << "3. Release Year" << endl;
        cout << "4. Exit" << endl;
        cin >> Choice;

        switch (Choice) {
        case 1: {
            double minRating;
            cout << "Enter the minimum rating: ";
            cin >> minRating;
            findByRating(serials, size, minRating);
            break;
        }
        case 2: {
            string genre;
            cout << "Enter the genre: ";
            cin >> ws;
            getline(cin, genre);
            findByGenre(serials, size, genre);
            break;
        }
        case 3: {
            int year;
            cout << "Enter the release year: ";
            cin >> year;
            findByReleaseYear(serials, size, year);
            break;
        }
        case 4:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (Choice != 4);

    return 0;
}