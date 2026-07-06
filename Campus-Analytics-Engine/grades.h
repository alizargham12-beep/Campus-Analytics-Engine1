#ifndef GRADES_H
#define GRADES_H

#include <string>
#include <vector>

using namespace std;

// Struct required by rubric
struct Stats {
    double highest, lowest, mean, median;
};

// M5 Function declarations
double bestThreeOfFive(double q1, double q2, double q3, double q4, double q5);
double computeWeightedTotal(double quizAvg, double asgnAvg, double mid, double finalMarks);
string getLetterGrade(double total);
void applyAttendancePenalty(string roll, string courseCode, string& currentGrade);

#endif