//01-27-2022
//This program asks for the user to input information about the number
//of students, their names, and their test scores. With this information it
//organises the information and displays each student's name and test scores.

#include <iostream>
#include <string>

using namespace std;

int inputData(string*&, double**&);
void displayData(string*, double**, int);
void cleanHeap(string*, double**, int);

int main() {
    string* namesPtr = nullptr;
    double** testScoresPtr = nullptr;

    int numberOfStudents = inputData(namesPtr, testScoresPtr);
    displayData(namesPtr, testScoresPtr, numberOfStudents);
    cleanHeap(namesPtr, testScoresPtr, numberOfStudents);
}

//This function receives a pointer and a double pointer. Then it asks for
//information about the students in the system, including their names and
//test scores and stores them in the heap.
int inputData(string*& names, double**& testScores) {
    int numOfTests, numOfStudents;
    do {
        cout << "Please enter how many students you have in the system: ";
        cin >> numOfStudents;
        cin.ignore();

        if(numOfStudents < 0){
            cout << "Please enter a non-negative number." << endl;
        }
    } while (numOfStudents < 0);

    testScores = new double *[numOfStudents];
    names = new string[numOfStudents];

    for (int i = 0; i < numOfStudents; i++){

        cout << "Enter student's name: ";
        getline(cin, *(names + i));

        do {
            numOfTests = 0;
            cout << "Enter how many tests " << *(names + i)
                    << " has taken: ";
            cin >> numOfTests;

            if(numOfTests < 0){
                cout << "Please enter a non-negative "
                        "number of tests." << endl;
            }
        } while (numOfTests < 0);


        testScores[i] = new double[numOfTests + 1];

        for(int j = 1; j < numOfTests + 1; j++ ) {
            do {
                testScores[i][j] = 0;
                cout << "Enter grade #" << j << ": ";
                cin >> testScores[i][j];
                if(testScores[i][j] < 0 || testScores[i][j] > 100){
                    cout << "Please enter a scores "
                            "between 0 and 100." << endl;
                }
            } while (testScores[i][j] < 0 || testScores[i][j] > 100);
        }
        testScores[i][0] = numOfTests;
        cin.ignore();

    }
    return numOfStudents;
}

//This function receives the name pointer, test scores double pointer,
//and number of students, and displays the student information.
void displayData(string* names, double** testScores, int numOfStud) {
    cout << "\nYou have " << numOfStud << " students in the system." << endl;
    for (int i = 0; i < numOfStud; i++){
        cout << "Name of student #" << i + 1 << ": " << names[i] << endl;
        cout << "Grades for student #" << i + 1 << ": ";

        for (int j = 1; j < (testScores[i][0]) + 1; j++) {
            cout << *((testScores[i]) + j) << " ";
        }
        cout << endl;
    }
}

//This function receives the name pointer,test scores double pointer,
//and number of students, and cleans the heap.
void cleanHeap(string* names, double** testScores, int numOfStud) {

    for(int i = 0; i < numOfStud; i++)
        delete[] testScores[i];
    delete[] testScores;
    delete[] names;
}
/*
Please enter how many students you have in the system: -1
Please enter a non-negative number.
Please enter how many students you have in the system: 3
Enter student's name: Jennifer Lum
Enter how many tests Jennifer Lum has taken: 3
Enter grade #1: 100
Enter grade #2: 99.7
Enter grade #3: 100.5
Please enter a scores between 0 and 100.
Enter grade #3: 78.6

Enter student's name: James Ling
Enter how many tests James Ling has taken: 2
Enter grade #1: 34.4
Enter grade #2: 23.8

Enter student's name: John Smith
Enter how many tests John Smith has taken: 4
Enter grade #1: 100
Enter grade #2: 77.8
Enter grade #3: 60
Enter grade #4: 30.5

You have 3 students in the system.
Name of student #1: Jennifer Lum
Grades for student #1: 100 99.7 78.6
Name of student #2: James Ling
Grades for student #2: 34.4 23.8
Name of student #3: John Smith
Grades for student #3: 100 77.8 60 30.5

Process finished with exit code 0
 */