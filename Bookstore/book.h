// Bria Weisblat Section: 2

// Bob Myers
//
// book.h -- header file for the Book class
//
// An object of type Book will store information about a single
// book.  The variable "type" stores the category of the book
// (one of the four items in the enumerated type Genre).

#ifndef _BOOK_H
#define _BOOK_H

enum Genre {FICTION, MYSTERY, SCIFI, COMPUTER};

class Book
{
public:
    // Default constructor- sets up blank book object
    Book();

    // Set function- allow incoming data to be received through parameters and loaded into the member data of the object
    void Set(const char* t, const char* a, Genre g, double p);

    // Returns the title stored in the object
    const char* GetTitle() const;

    // Returns the author
    const char* GetAuthor() const;

    // Returns the price
    double GetPrice() const;

    // Returns the genre
    Genre GetGenre() const;

    // Prints the book object
    void Display() const;

private:
    char title[31];	// may assume title is 30 characters or less
    char author[21];	// may assume author name is 20 characters or less
    Genre type;
    double price;
};


#endif

