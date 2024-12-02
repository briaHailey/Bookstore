// Bria Weisblat Section: 2


#include "book.h"

class Store {

public:
    // Default constructor
    Store();

    // Constructor that takes in a double cash variable
    Store(double cash);

    // A- add book function
    void Add(Book b1);

    // F- find book function
    void Find(char *search);

    // S- sell book function
    void Sell(char *search);

    // D- display the inventory list
    void Display();

    // G- genre summary
    void GenreSummary(char userGenre);

    // O- sort inventory list
    void Sort(char userSelection);

    // Converts the user-inputted charcter into genre type
    Genre toGenre(char g);

    // Gets the price in the cash register
    double GetPrice() const;

    // Deconstructor
    ~Store();

private:

    // Book type pointer
    Book * listPtr;

    // Number of items in the list
    int numList;

    // Maximum number of books (before resizing)
    int numSpaces;

    // Stored cash
    double cashRegister;

    // Keeps track of the number of books in a genre
    int numGenre =0;

    // Keeps track of the total cost of all of the books in one genre
    double sumGenre;
};

