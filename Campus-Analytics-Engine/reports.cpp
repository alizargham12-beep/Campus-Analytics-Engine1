#include "reports.h"
#include "filehandler.h"
#include <iostream>

using namespace std;

// Sorts students by CGPA in descending order and prints them
void printMeritList() {
    vector<vector<string>> students = readTXT("students.txt");
    
    // Manual Bubble Sort to sort by CGPA (Index 3)
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            double cgpa1 = stod(students[j][3]);
            double cgpa2 = stod(students[j+1][3]);
            
            // Swap if the next student has a higher CGPA
            if (cgpa1 < cgpa2) {
                vector<string> temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }

    // Formatted tabular output
    cout << "\n========================================" << endl;
    cout << "         UNIVERSITY MERIT LIST          " << endl;
    cout << "========================================" << endl;
    
    int rank = 1;
    for (int i = 0; i < students.size(); i++) {
        // Only print active students
        if (students[i][4] == "active") {
            cout << rank << ". " << students[i][0] << " - " << students[i][1] 
                 << " (CGPA: " << students[i][3] << ")" << endl;
            rank++;
        }
    }
    cout << "========================================\n" << endl;
}