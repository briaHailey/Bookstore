// Bria Weisblat Section: 2

#include "store.h"
#include <iomanip>
#include <iostream>

// Default constructor
Store::Store() {

}

// Constructor that takes in an optional double cash variable
Store::Store(double cash) {
    // Store cash if the value is positive
    if (cash > 0){
        cashRegister = cash;
    }
    else{
        cashRegister = 0;
    }

    numList = 0;
    numSpaces = 5;

    // For 0 books, five spaces are allowed
    listPtr = new Book[5];
}


// A- add book function
void Store::Add(Book b1) {
    // If there is not enough space to add a new book
    if (numSpaces <= numList) {
        Book * tempPtr = new Book[numSpaces + 5];
        // Perform a deep copy
        for (int i = 0; i < numList; i++) {
            tempPtr[i] = listPtr[i];
        }
        // Add the book
        tempPtr[numList] = b1;
        // Deallocate
        delete listPtr;
        //Overwrite listPtr
        listPtr = tempPtr;

        // Keep track of the number of books
        numList++;
        // Add more slots
        numSpaces += 5;
    }
    // If there is enough space to add a new book
    else {
        // Add the book
        listPtr[numList] = b1;
        // Keep track of the number of books
        numList++;
    }
}

// F- find book function
void Store::Find(char *search) {
    bool found = false;
    // Check each book in the list
    for (int i=0; i < numList; i++){
        // If the search is the same as a stored title/ stored author, display it
        if ( (strcmp(Store::listPtr[i].GetTitle(), search) == 0 ) || (strcmp(Store::listPtr[i].GetAuthor(), search) == 0 )){
            Store::listPtr[i].Display();
            found = true;
        }
    }
    if (found)
        std::cout << "Book found.\n";
    else
        std::cout << "Book not found.\n";
}

// S- sell book function
void Store::Sell(char *search) {
    bool bookFound = false;
    // Check each book in the list
    for (int i=0; i < numList; i++){
        // If the search is the same as a stored title
        if ( (strcmp(Store::listPtr[i].GetTitle(), search) == 0 ) ){
            // Add the price of the sold book to the cash register
            cashRegister = cashRegister + listPtr[i].GetPrice();
            // Account for the loss of one book
            Book *temp = new Book[numSpaces-1];
            for (int j=0; j < i; j++) {
                // Copy over all old books
                temp[j] = Store::listPtr[j];
            }
            for (int j=i; j < numList-1; j++){
                temp[j] = Store::listPtr[j+1];
            }
            // Account for the loss of one book
            numList--;
            numSpaces--;
            delete listPtr;
            listPtr = temp;

            bookFound = true;
        }
    }
    if (bookFound == true){
        std::cout << "Sale complete!";
    }
    else {
        std::cout << search << " not found in inventory \n";
        std::cout << "* No sale made *";
    }
}

// D- display the inventory list
void Store::Display() {
    if (numList == 0){
        std::cout << "No books currently in inventory.";
    }
    else {
        // Print category headings
        std::cout << "**Title**\t                \t**Author**\t    \t**Genre**\t**Price** \n\n";
    }
    for (int i = 0; i < numList; i++) {
        Store::listPtr[i].Display();
    }
    std::cout << "\nNumber of books = " << numList << "\n";
    std::cout << "Money in register = " << std::fixed << std::setprecision(2) << "$" << cashRegister << "\n";
}

// G- genre summary function
void Store::GenreSummary(char userGenre) {
    // Accept upper and lowecase inputs
    userGenre = toupper(userGenre);
    // Make sure the number of books resets each time the function is called
    numGenre = 0;
    // Make sure the sum of the costs of the books in a genre is reset each time the function is called
    sumGenre = 0;
    switch (userGenre) {
        case 'F':
            for (int i = 0; i < numList; i++) {
                // If the book genre is fiction, display it
                if (Store::listPtr[i].GetGenre() == FICTION) {
                    Store::listPtr[i].Display();
                    // Keep track of the number of books in the genre
                    numGenre++;
                    // Update the sum of the prices of the books in the genre
                    sumGenre += Store::listPtr[i].GetPrice();
                }
            }
            break;
        case 'M':
            for (int i = 0; i < numList; i++) {
                // If the book genre is mystery, display it
                if (Store::listPtr[i].GetGenre() == MYSTERY) {
                    Store::listPtr[i].Display();
                    // Keep track of the number of books in the genre
                    numGenre++;
                    // Update the sum of the prices of the books in the genre
                    sumGenre += Store::listPtr[i].GetPrice();
                }
            }
            break;
        case 'S':
            for (int i = 0; i < numList; i++) {
                // If the book genre is scifi, display it
                if (Store::listPtr[i].GetGenre() == SCIFI) {
                    Store::listPtr[i].Display();
                    // Keep track of the number of books in the genre
                    numGenre++;
                    // Update the sum of the prices of the books in the genre
                    sumGenre += Store::listPtr[i].GetPrice();
                }
            }
            break;
        case 'C':
            for (int i = 0; i < numList; i++) {
                // If the book genre is computer, display it
                if (Store::listPtr[i].GetGenre() == COMPUTER) {
                    Store::listPtr[i].Display();
                    // Keep track of the number of books in the genre
                    numGenre++;
                    // Update the sum of the prices of the books in the genre
                    sumGenre += Store::listPtr[i].GetPrice();
                }
            }
            break;
    }
    if (numGenre == 0){
        std::cout<< "There are no books of that genre type in the store inventory.";
    }
    std::cout<< "\nTotal books in this genre = " << numGenre;
    std::cout << "\nTotal price of the books in this genre = $" << std::fixed << std::setprecision(2) << sumGenre << "\n";
}

// O- sort inventory list
void Store::Sort(char userSelection) {
    userSelection = toupper(userSelection);
    // If the user wants to sort by title
    if (userSelection == 'T') {
        for (int i = 0; i < numList - 1; i++) {
            for (int j = 0; j < numList - i - 1; j++) {
                // Bubble sort
                if (strcmp(Store::listPtr[j].GetTitle(), Store::listPtr[j + 1].GetTitle()) > 0) {
                    Book temp = Store::listPtr[j];
                    Store::listPtr[j] = Store::listPtr[j + 1];
                    Store::listPtr[j + 1] = temp;
                }
            }
        }
        std:: cout << "Sort complete";
    }
    // If the user wants to sort by author
    else if (userSelection == 'A'){
        for (int i = 0; i < numList - 1; i++) {
            for (int j = 0; j < numList - i - 1; j++) {
                // Bubble sort
                if (strcmp(Store::listPtr[j].GetAuthor(), Store::listPtr[j + 1].GetAuthor()) > 0) {
                    Book temp = Store::listPtr[j];
                    Store::listPtr[j] = Store::listPtr[j + 1];
                    Store::listPtr[j + 1] = temp;
                }
            }
        }
        std:: cout << "Sort complete";
    }
}

// Converts the user-inputted charcter into genre type
Genre Store::toGenre(char g) {
    Genre type;
    g = toupper(g);
    if (g == 'F'){
        type = FICTION;
    }
    else if (g == 'M'){
        type = MYSTERY;
    }
    else if (g == 'S'){
        type = SCIFI;
    }
    else if (g == 'C'){
        type = COMPUTER;
    }
    return type;
}

// Get the amount of money stored in cashRegister(private)
double Store::GetPrice() const {
    return cashRegister;
}

// Deconstructor
Store::~Store() {
    delete listPtr;
}
