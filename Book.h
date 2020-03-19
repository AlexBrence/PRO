//
// Created by alex on 3/9/20.
//

#include<iostream>
#include <vector>

using namespace std;

#ifndef NALOGA0201_BOOK_H
#define NALOGA0201_BOOK_H


class Book {
private:
    static int idCounter;
    static int objectCounter;
    string title;
    string publisher;
    int pages;
    int pagesRead{};
    double price;
    int id;

public:
    // Privzeti
    Book();
    // Kopirni
    Book(const Book& b);
    // Konstruktor
    Book(string title, string publisher, int pages, double price);
    // Destruktor
    ~Book();

    // Metode
    void setTitle(string title1);
    void setPublisher(string publ);
    void setPages(int pages1);
    void setPagesRead(int pagesRead1);
    void setPrice(double price1);
    string getTitle() const;
    string getPublisher() const;
    int getPages() const;   // Const za metodo pomeni, da ne boš spremenil variable, ki jo vrneš z return.
    double getPrice() const;
    int getIdCounter() const;
    int getBookId() const;
    void print() const;
    string toString() const;
    int pagesToFinish();
    static Book createDemoBook();
    static int getObjectCounter();
    static double getBookTotal(const vector<Book*>& books);
};


#endif //NALOGA0201_BOOK_H
