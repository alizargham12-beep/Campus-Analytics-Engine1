#ifndef STUDENT_OPS_H
#define STUDENT_OPS_H


#include <string>
#include <vector>

using namespace std;

// Structure for student data
struct Student {
    string roll, name, dept, status;
    double cgpa;
};

// Function declarations
void addStudent(string roll, string name, string dept, double cgpa);
vector<string> searchByRoll(string roll);
vector<vector<string>> searchByName(string name);
void updateStudent(string roll, string newName, double newCgpa);
void softDelete(string roll);
vector<vector<string>> listActiveStudents();

#endif