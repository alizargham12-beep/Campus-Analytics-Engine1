#include <iostream>
#include "student_ops.h"
#include "course_ops.h"
#include "attendance.h"
#include "reports.h"

using namespace std;

int main() {
    int choice;
    string roll, name, dept, sem, course;
    double cgpa;

    while (true) {
        cout << "\n--- Campus Engine ---" << endl;
        cout << "1. Add Student | 2. Enroll | 3. Merit List | 0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) break;
        if (choice == 1) {
            cout << "Roll, Name, Dept, CGPA: ";
            cin >> roll >> name >> dept >> cgpa;
            addStudent(roll, name, dept, cgpa);
        } else if (choice == 2) {
            cout << "Roll, Course, Semester: ";
            cin >> roll >> course >> sem;
            enrollStudent(roll, course, sem);
        } else if (choice == 3) {
            printMeritList();
        }
    }
    return 0;
}