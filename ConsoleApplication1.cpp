/*  Project Name: Chapter 5 Exercise 25 - Student Lineup
    File Name: ConsoleApplication1.cpp
    Programmer: Harrison Hudgins
    Date: November 14, 2024
    Requirements:
    Make a branch based off of the previous code and make it read from a file
*/

#include <iostream>
#include <algorithm>
#include <fstream>
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

    int startingPoint = 25 - studentAmount;
    int size = sizeof(studentTable) / sizeof(studentTable[0]);
    sort(studentTable, studentTable + size);

    string filePath;
    cout << "Please enter the file path of LineUp.txt\n";
    cin >> filePath;

    ofstream outfile(filePath);

    for (int interStudent = startingPoint; interStudent < size; interStudent++) {
        outfile << studentTable[interStudent] << endl;
    }
    outfile.close();

    ifstream inFile(filePath);
    string name;
    for (int interStudent = 0; interStudent < studentAmount; interStudent++) {
        inFile >> name;
        cout << name << endl;
    }
    inFile.close();
}