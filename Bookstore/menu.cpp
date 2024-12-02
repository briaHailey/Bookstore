// Bria Weisblat Section: 2

#include <iostream>
#include <iomanip>
#include "store.h"

// Menu function declaration
void printMenu();

int main() {

    // Menu variables
    double startingMoney;
    char selection;

    std::cout << "*** Welcome to Bookstore Inventory Manager ***\n";
    std::cout << "Please input the starting amount of money in the cash register: ";
    std:: cin >> startingMoney;
    // Make sure that the user inputs a positive amount of money for the cash register
    while (startingMoney < 0){
        std::cout << "Must enter a positive price, please re-enter.\n";
        std::cout << "Please input the starting amount of money in the cash register: ";
        std::cin >> startingMoney;
    }
    // Store the user-inputted amount of money in the cash register
    Store s1(startingMoney);
    std::cout << "\n";
    // Print the menu for the first time
    printMenu();

    do {
        std::cout << "\nMake a selection: ";
        std:: cin >> selection;
        // Accept upper and lowercase input
        selection = toupper(selection);
        // Print an error message if the user entered an invalid selection
        while ( (selection != 'A') && (selection != 'F') && (selection != 'S') && (selection != 'D') && (selection != 'G') && (selection != 'O') && (selection != 'M') && (selection != 'X')){
            std:: cout << "This is not a valid selection. Enter a new selection: ";
            std:: cin >> selection;
            selection = toupper(selection);
        }

        switch (selection){
            // Add a book to inventory
            case 'A': {
                char userTitle[31];
                char userAuthor[21];
                char userGenre;
                double userPrice;

                std::cout << "Enter title: ";
                // Ignore the \n
                std::cin.ignore(1);
                // Read in the book title
                std::cin.getline(userTitle, 31, '\n');

                std::cout << "Enter author: ";
                // Read in the author
                std::cin.getline(userAuthor, 21, '\n');

                std::cout << "Enter Genre- (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
                // Read in the genre
                std::cin >> userGenre;
                // Accept upper and lower case characters
                userGenre = toupper(userGenre);
                // Ensure that the genre is valid
                while ( (userGenre != 'F') && (userGenre != 'M') && (userGenre != 'S') && (userGenre != 'C')){
                    std::cout << "Invalid Genre entry, please re-enter. \n";
                    std::cout << "Enter Genre- (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
                    std::cin >> userGenre;
                    userGenre = toupper(userGenre);
                }

                std::cout << "Enter price: ";
                // Read in the price of the book
                std::cin >> userPrice;
                // Ensure that the price is positive
                while (userPrice < 0){
                    std::cout << "Must enter a positive price, please re-enter. \n";
                    std::cout << "Enter price: ";
                    std::cin >> userPrice;
                }

                // Create a book object
                Book inputBook;
                // Fill the empty book object with the user-entered data
                inputBook.Set(userTitle, userAuthor, s1.toGenre(userGenre), userPrice);
                // Add the book
                s1.Add(inputBook);
                break;
            }

            // Find a book from inventory
            case 'F':
                char search[31];
                std::cout << "Enter search string (title or author): ";
                // Ignore the \n
                std::cin.ignore(1);
                // Read in the search
                std::cin.getline(search, 31, '\n');
                // Have the search function complete the search
                s1.Find(search);
                break;

            // Sell a book
            case 'S':
                char sellSearch[31];
                std::cout << "Enter search string (title only): ";
                // Ignore the \n
                std::cin.ignore(1);
                // Read in the search
                std::cin.getline(sellSearch, 30, '\n');
                // Use the sell function to sell the book
                s1.Sell(sellSearch);
                break;

            // Display the inventory list
            case 'D':
                // Print the books in the inventory, the number of books, and the amount of money in the cash register
                s1.Display();
                break;

            // Genre summary
            case 'G':
                char userGenre;
                std::cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
                std::cin >> userGenre;
                // Accept upper and lowercase inputs
                userGenre = toupper(userGenre);
                // Ensure that the user enters a valid genre type
                while ( (userGenre != 'F') && (userGenre != 'M') && (userGenre != 'S') && (userGenre != 'C')){
                    std::cout << "Invalid Genre entry, please re-enter.\n";
                    std::cout << "Enter Genre - (F)iction, (M)ystery, (S)ci-Fi, or (C)omputer: ";
                    std::cin >> userGenre;
                    // Accept upper and lowercase inputs
                    userGenre = toupper(userGenre);
                }
                s1.GenreSummary(userGenre);
                break;

            // Sort inventory list
            case 'O':
                char userSelection;
                std:: cout << "Sort by (T)itle or (A)uthor? ";
                std:: cin >> userSelection;
                s1.Sort(userSelection);
                break;

            // Show this menu
            case 'M':
                printMenu();
                break;
            default:
                break;
        }

    } while (selection != 'X');

    // Goodbye message
    if (selection == 'X'){
        std::cout << "\nFinal amount of money in the store cash register: $ " << s1.GetPrice();
        std::cout << "\nGoodbye!";
    }
}

void printMenu(){
    std::cout << "\n        *** BOOKSTORE MENU *** \n";
    std::cout << "A:   Add a book to inventory\n";
    std::cout << "F:   Find a book from inventory\n";
    std::cout << "S:   Sell a book\n";
    std::cout << "D:   Display the inventory list\n";
    std::cout << "G:   Genre summary\n";
    std::cout << "O:   Sort inventory list \n";
    std::cout << "M:   Show this menu\n";
    std::cout << "X:   eXit the program\n";

};
