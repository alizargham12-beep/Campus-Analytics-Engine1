#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>

using namespace std;

void markAttendance(string courseCode, string date);
double getAttendancePct(string roll, string courseCode);

#endif