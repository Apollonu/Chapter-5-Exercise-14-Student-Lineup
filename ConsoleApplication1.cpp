// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;


int studentAmount;
string student;
string studentTable[25];

int main()
{
    cout << "Please enter how many students are in your class. (1-25)\n";
    cin >> studentAmount;

    while (studentAmount < 1 || 25 < studentAmount) {
        cout << "Please enter a valid amount of students.";
        cin >> studentAmount;
    }

    for (int interStudent = 0; interStudent < studentAmount; interStudent++) {
        cout << "Please enter a student.\n";
        cin >> student;
        studentTable[interStudent] = {student};
    }

    cout << endl;
    cout << "The list of students is followed below:\n";

    int startingPoint = 25 - studentAmount;
    int size = sizeof(studentTable) / sizeof(studentTable[0]);
    sort(studentTable, studentTable + size);

    for (int interStudent = startingPoint; interStudent < size; interStudent++) {
        cout << studentTable[interStudent] << endl;
    }
}