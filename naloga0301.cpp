#include <iostream>
#include "Book.h"
#include <vector>

using namespace std;


int main() {
    vector<Book*> books;

    Book a;
    Book b("Janko in Metka", "Nevemvec", 165, 12.50);
    Book c(b);

    cout << "===== Write out a, b, c objects =====" << endl;
    a.print();
    cout << endl;

    b.print();
    cout << endl;

    c.print();
    cout << endl << endl;


    vector<Book*> dynObjects;
    Book *d = new Book();
    Book *e = new Book("Metka in Janko", "Pojmanimam", 50, 14.99);
    Book *f = new Book(*e);

    dynObjects.push_back(d);
    dynObjects.push_back(e);
    dynObjects.push_back(f);


    cout << "===== Write out d, e, f dynamic objects =====" << endl;
    d->print();
    cout << endl;

    e->print();
    cout << endl;

    f->print();
    cout << endl << endl;

    a.setTitle("Programiranje2");
    a.setPublisher("ProfNaFeriju");
    a.setPages(100);
    a.setPrice(29.99);

    cout << "===== Object 'a' after giving it data =====" << endl;
    cout << "Title: " << a.getTitle() << endl;
    cout << "Publisher: " << a.getPublisher() << endl;
    cout << "Pages: " << a.getPages() << endl;
    cout << "Price: " << a.getPrice() << endl;
    cout << "Id: " << a.getBookId() << endl << endl;

    cout << "-----To string method-----" << endl;
    cout << e->toString() << endl << endl;

    e->setPagesRead(14);
    cout << "Pages to finish: " << e->pagesToFinish() << endl << endl;

    cout << "Total price is: " << Book::getBookTotal(dynObjects) << "€." << endl << endl;   // ZAKAJ MORA BITI STATIČNO DA DELUJE??

    cout << "===== DEMO BOOK =====" << endl;
    Book::createDemoBook().print();

    cout << endl << "===== Number of objects =====" << endl;
    cout << Book::getObjectCounter() << endl << endl;

    delete d;
    delete e;
    delete f;
}