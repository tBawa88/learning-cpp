#include <cstdio>
#include <cstring>
/**
 * A Plain-Old-Data class (POD) can be thought of as an array of heteregenous elements.
 * It's just a container of different types of data
 * It's defined using the keyword 'struct'
 */

struct Book {
    char name[250];
    char author[250];
    int year;
    int pages;
    bool hardcover;
};

// Declare variables of this new Data type just like any other data type
// to access a field, use the (.) notation

int main() {
    Book book;
    strcpy(book.author, "Tolkein");  // this is the correct way of assigning strings to character arrays in C++/C
    strcpy(book.name, "The Hobbit");
    book.pages = 500;

    printf("The book is %s\n", book.name);

    return 0;
}
