#include "attendance.h"
#include "filehandler.h"
#include <iostream>

using namespace std;

void markAttendance(string courseCode, string date) {
    vector<vector<string>> enroll = readTXT("enrollments.txt");
    bool found = false;

    for (int i = 0; i < enroll.size(); i++) {
        if (enroll[i][1] == courseCode && enroll[i][3] == "enrolled") {
            found = true;
            string status;
            cout << "Student " << enroll[i][0] << " (P/A/L): ";
            cin >> status;
            
            vector<string> row = {enroll[i][0], courseCode, date, status};
            appendTXT("attendance_log.txt", row);
        }
    }
    if (!found) cout << "No students found." << endl;
}

double getAttendancePct(string roll, string courseCode) {
    vector<vector<string>> log = readTXT("attendance_log.txt");
    double present = 0.0, total = 0.0;

    for (int i = 0; i < log.size(); i++) {
        if (log[i][0] == roll && log[i][1] == courseCode) {
            total++;
            if (log[i][3] == "P") present += 1.0;
            else if (log[i][3] == "L") present += 0.5; 
        }
    }
    if (total == 0) return 100.0; 
    return (present / total) * 100.0;
}