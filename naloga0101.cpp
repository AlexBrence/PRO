#include <iostream>

using namespace std;

bool isPrime(int counter) {
    for (int i = 2; i < counter; i++) {
        if (counter % i == 0) {
            return false;
        }
    }
    return true;
}




int main () {

    int zgmeja;
    int spmeja;
    int veckratnik;
    int deljiva = 1;
    int primeCount = 0;


    cout << "Vnesi zgornjo mejo: " << endl;
    cin >> zgmeja;
    cout << "Vnesi spodnjo mejo: " << endl;
    cin >> spmeja;

    while (zgmeja < 1) {
        cout << "Vnesi naravno število!" << endl;
        cin >> zgmeja;
    }

    cout << "Praštevila, ki so manjša od števila: " << zgmeja << ": ";
    for (int counter = spmeja; counter < zgmeja; counter++) {     // Counter - za praštevila
        if (isPrime(counter)) {
            cout << counter << ", ";
            primeCount++;
        }
    }
    cout << endl << "Število praštevil je: " << primeCount << endl << endl;

    cout << "Vnesi tretji večkratnik: " << endl;
    cin >> veckratnik;

    cout << "Stevila, ki so veckratniki stevil 3 in 5 ter so manjsa od stevila " << zgmeja << ": ";
    while (deljiva != zgmeja - 1) {
       if (deljiva % 3 == 0 && deljiva % 5 == 0 && deljiva % veckratnik == 0) {
           cout << deljiva << ", ";
       }
       deljiva++;
    }

    return 0;
}