#include "student_ops.h"
#include "filehandler.h"
#include <iostream>

using namespace std;

// Validates roll format BSAI-YY-XXX using substr (no regex)
void addStudent(string roll, string name, string dept, double cgpa) {
    // Basic format check
    if (roll.substr(0, 5) != "BSAI-" || roll.length() != 10) {
        cout << "Invalid roll format!" << endl;
        return;
    }
    
    // Check for duplicates
    if (rowExists("students.txt", 0, roll)) {
        cout << "Student already exists!" << endl;
        return;
    }

    // Prepare row and append
    vector<string> newRow = {roll, name, dept, to_string(cgpa), "active"};
    appendTXT("students.txt", newRow);
}

// Sets status to 'inactive' (Soft Delete)
void softDelete(string roll) {
    vector<vector<string>> data = readTXT("students.txt");
    for (int i = 0; i < data.size(); i++) {
        if (data[i][0] == roll) {
            data[i][4] = "inactive"; // Index 4 is the status column
            break;
        }
    }
    writeTXT("students.txt", "roll,name,dept,cgpa,status", data);
}

// Selection sort implementation (no algorithm library)
vector<vector<string>> listActiveStudents() {
    vector<vector<string>> data = readTXT("students.txt");
    vector<vector<string>> active;

    // Filter only active
    for (int i = 0; i < data.size(); i++) {
        if (data[i][4] == "active") {
            active.push_back(data[i]);
        }
    }

    // Selection sort by roll number
    for (int i = 0; i < active.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < active.size(); j++) {
            if (active[j][0] < active[minIdx][0]) {
                minIdx = j;
            }
        }
        // Swap
        vector<string> temp = active[minIdx];
        active[minIdx] = active[i];
        active[i] = temp;
    }
    return active;
}