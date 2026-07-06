#ifndef COURSE_OPS_H
#define COURSE_OPS_H

#include <string>
#include <vector>

using namespace std;

int getCreditLoad(string roll, string semester);
bool checkPrerequisite(string roll, string courseCode);
void enrollStudent(string roll, string courseCode, string semester);
void dropCourse(string roll, string courseCode, string semester);

#endif
