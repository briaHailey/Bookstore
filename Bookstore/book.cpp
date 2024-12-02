// Bria Weisblat Section: 2

#include "book.h"
#include <iostream>
#include <iomanip>

Book::Book() {
   // Set the book title blank
    for (int i =0; i < 31; i++){
       title[i] = ' ';
   }

    // Set the author title blank
    for (int i=0; i < 21; i++){
        author[i] = ' ';
    }

    // Set the genre to a default (FICTION)
    type = FICTION;

    // Set the price to 0
    price = 0;
}

void Book::Set(const char *t, const char *a, Genre g, double p) {
    //Store the title of the book
    for (int i =0; i < 31; i++){
        title[i] = t[i];
    }

    // Store the name of the author
    for (int i =0; i < 21; i++){
        author[i] = a[i];
    }

    // If the genre is a valid genre type, store it
    if ( (g== FICTION) || (g== MYSTERY) || (g== SCIFI) || (g== COMPUTER)){
        type = g;
    }

    // If the genre is not a valid genre type set it to the default (fiction)
    else {
        type = FICTION;
    }

    // If the price is non-negative, store it
    if (p >= 0){
        price = p;
    }
    // If the price is negative set it to zero
    else {
        p =0;
    }
}

// Return the stored title
const char *Book::GetTitle() const {
    return Book::title;
}

// Return the stored author
const char *Book::GetAuthor() const {
    return Book::author;
}

// Return the stored price
double Book::GetPrice() const {
    return Book::price;
}

// Return the stored genre type
Genre Book::GetGenre() const {
    return Book::type;
}

void Book::Display() const {
    int numCharsTitle = 0;
    int numSpacesTitle = 0;

    // Print each character of the title
    int i = 0;
    while ((title[i] != '\0') && (i < 31)) {
        std::cout << title[i];
        numCharsTitle++;
        i++;
    }

    // Calculate the number of spaces it takes to fill up 30 characters
    numSpacesTitle = 30 - numCharsTitle;

    // Print spaces to make the number of characters each book title takes up even
    for (int j = 0; j < numSpacesTitle - 2; j++) {
        std::cout << ' ';
    }

    int numCharsAuthor = 0;
    int numSpacesAuthor = 0;

    // Print each character of the author name
    std::cout << "\t";
    int k = 0;
    while ((author[k] != '\0') && (k < 21)) {
        std::cout << author[k];
        numCharsAuthor++;
        k++;
    }

    // Calculate the number of spaces it takes to fill up 20 characters
    numSpacesAuthor = 20 - numCharsAuthor;

    // Print spaces to make the number of characters each author name takes up even
    for (int l = 0; l < numSpacesAuthor - 4; l++) {
        std::cout << ' ';
    }

    // Print the genre type with the correct number of spaces after (11 characters total)
    // Fiction is 7 characters + 4 spaces
    if (type == FICTION) {
        std::cout << "\tFiction";
        std::cout << "   ";
    }
    // Mystery is 7 characters + 4 spaces
    else if (type == MYSTERY) {
        std::cout << "\tMystery";
        std::cout << "   ";
    }
    // Sci-fi with dash is 6 characters + 5 spaces
    else if (type == SCIFI) {
        std::cout << "\tSci-fi";
        std::cout << "    ";
    }
    // Computer is 8 characters + 3 spaces
    else if (type == COMPUTER) {
        std::cout << "\tComputer";
        std::cout << "  ";
    }
    //Print the price
    if (price < 10) {
        std::cout << std::fixed << std::setprecision(2) << "\t$     " << price << "\n";
    }
    else if (price > 9.99){
        std::cout << std::fixed << std::setprecision(2) << "\t$    " << price << "\n";
    }


}
