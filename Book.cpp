//
// Created by alex on 3/9/20.
//
#include <iostream>
#include "Book.h"
#include <sstream>
#include <ctime>
using namespace std;

int Book::idCounter = 10000;
int Book::objectCounter = 0;

// Privzeti
Book::Book() : title("None"), publisher("None"), pages(0), price(0), id(idCounter) {
    idCounter++;
    objectCounter++;
}

// Kopirni
Book::Book(const Book& b) : title(b.title), publisher(b.publisher), pages(b.pages), price(b.price), id(b.idCounter) {
    idCounter++;
    objectCounter++;
}

// Nastavitveni
Book::Book(string title1, string publisher1, int pages1, double price1) : title(title1), publisher(publisher1),
    pages(pages1), price(price1){
    id = idCounter;
    idCounter++;
    objectCounter++;
}

// Destruktor
Book::~Book() {
    objectCounter--;
}


// METODE
void Book::setTitle(string title) {
    this->title = title;
    this->id = idCounter;
    idCounter++;
}

void Book::setPublisher(string publ) {
    publisher = publ;
}

void Book::setPages(int pages1) {
    pages = pages1;
}

void Book::setPagesRead(int pagesRead1) {
    pagesRead = pagesRead1;
}

void Book::setPrice(double price1) {
}

string Book::getTitle() const {
    return title;
}

string Book::getPublisher() const {
    return publisher;
}

int Book::getPages() const {
    return pages;
}

double Book::getPrice() const {
    return price;
}

int Book::getIdCounter() const {
    return idCounter;
}

int Book::getBookId() const {
    return id;
}

int Book::getObjectCounter() {
    return objectCounter;
}

double Book::getBookTotal(const vector<Book *> &books) {
    double sum = 0;

    for (Book* i : books) {
        sum += i->getPrice();
    }

    return sum;
}

Book Book::createDemoBook() {
    string title[5] = {"Janko in Janez", "V višave", "Meddo sladkosned", "101 dalmatinec", "Nimam več idej"};
    string publisher[5] = {"Svetlana Makarovič", "Janez Drnovšek", "Janez Janša", "Igor Mezgič", "Anja Svetlanič"};

    srand(time(0));

    string novaTitle = title[rand() % 5];
    string novaPublisher = publisher[rand() % 5];
    int novaPages = 1 + (rand() % 500);
    int novaPrice = 1 + (rand() % 60);

    Book nova (novaTitle, novaPublisher, novaPages, novaPrice);

    return nova;

}

void Book::print() const {
    cout << "Title: " << this->title << endl;
    cout << "Publisher: " << this->publisher << endl;
    cout << "Pages: " << this->pages << endl;
    cout << "Price: " << this->price << endl;
    cout << "Id: " << this->id << endl;
}

string Book::toString() const {

    stringstream bookInfo;
    bookInfo << "Title: " <<  this->title << ", \nPublisher: " <<  this->publisher << ",\nPages: " << this->pages << ",\nPrice: "
        << this->price << ",\nID: " << this->id << endl << endl;

    return bookInfo.str();
}

int Book::pagesToFinish() {
    return (pages - pagesRead);
}



#include "Book.h"
