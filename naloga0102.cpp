#include <iostream>
#include <random>

using namespace std;

void menu() {
    cout << "=========================" << endl;
    cout << "======== MENU: ==========" << endl;
    cout << "=========================" << endl;
    cout << "1 ... GENERATE GRADES" << endl;
    cout << "2 ... PRINT GRADES" << endl;
    cout << "0 ... EXIT" << endl;
    cout << "=========================" << endl;
    cout << "Select: ";
}

void fillArrayOfGrades(int *grades, int numberOfGrades) {

    for (int i = 0; i < numberOfGrades; i++) {
        grades[i] = 5 + rand() % 6;

    }
}

void printArrayOfGrades(int *grades, int numerOfGrades) {
    int averageGrade = 0;
    int countGrades[10]= {0,0,0,0,0,0,0,0,0,0};

    cout << "Grades: ";
    for (int i = 0; i < numerOfGrades; i++) {
        averageGrade += grades[i];
        cout << ((i > 0) ? ", " : "") << grades[i];
    }

    cout << "." << endl;
    cout << "Povprečna ocena je " << averageGrade / 30 << "." << endl;

    for (int i = 0; i < numerOfGrades; i++) {
        countGrades[grades[i]-1]++;
    }

    for (int i = 5; i < 10; i++) {
        cout << i+1  << ": " << countGrades[i] << endl;
    }

}

void changeAt(int *grades, int index, int newGrade) {
    grades[index] = newGrade;
}


void bestWorstGrade(int *grades) {
    int theBest = 0;
    int theWorst = 10;

    for (int i = 0; i < 30; i++) {
        if (grades[i] > theBest) {
            theBest = grades[i];
        }
        else if (grades[i] < theWorst) {
            theWorst = grades[i];
        }
    }

    cout << "Ocena najboljšega učenca je: " << theBest << endl;
    cout << "Ocena učenca, ki je najbolj zabušaval je: " << theWorst << endl << endl;

}


int main() {
    int numberOfGrades = 30;
    int* grades = new int[numberOfGrades];
    bool running = true;
    int selection;

    char decision;
    int index;
    int newGrade;

    do {
        menu();
        cin >> selection;
        switch (selection) {
            case 1:
                fillArrayOfGrades(grades, numberOfGrades);
                break;
            case 2:
                printArrayOfGrades(grades, numberOfGrades);
                bestWorstGrade(grades);

                cout << "Ali želiš katero oceno popraviti? (y/n): ";
                cin >> decision;
                if (decision == 'y') {
                    cout << "Vpiši index ocene ter novo oceno: " << endl;
                    cin >> index;
                    cin >> newGrade;
                    changeAt(grades, index, newGrade);
                }
                break;
            case 0:
                running = false;
                break;
            default:
                cout << "Wrong selection!" << endl;
                break;
        }
        cout << endl;

    } while (running);

    delete[] grades;

    return 0;
}