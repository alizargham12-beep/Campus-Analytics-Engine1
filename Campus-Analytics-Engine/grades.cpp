#include "grades.h"
#include "attendance.h"

using namespace std;

// Excludes 2 lowest manually
double bestThreeOfFive(double q1, double q2, double q3, double q4, double q5) {
    double arr[5] = {q1, q2, q3, q4, q5};
    int min1 = 0;
    for(int i = 1; i < 5; i++) if(arr[i] < arr[min1]) min1 = i; 
    double temp = arr[min1]; 
    arr[min1] = 9999; 
    
    int min2 = 0;
    for(int i = 1; i < 5; i++) if(arr[i] < arr[min2]) min2 = i; 
    arr[min1] = temp; 
    
    double sum = 0;
    for(int i = 0; i < 5; i++) {
        if(i != min1 && i != min2) sum += arr[i];
    }
    return sum / 3.0; 
}

double computeWeightedTotal(double quizAvg, double asgnAvg, double mid, double finalMarks) {
    return (quizAvg * 0.10) + (asgnAvg * 0.10) + (mid * 0.30) + (finalMarks * 0.50); 
}

string getLetterGrade(double total) { 
    if (total >= 85) return "A";
    if (total >= 80) return "B+";
    if (total >= 70) return "B";
    if (total >= 60) return "C";
    if (total >= 50) return "L"; 
    return "F";
}

void applyAttendancePenalty(string roll, string courseCode, string& currentGrade) {
    if (getAttendancePct(roll, courseCode) < 75.0) currentGrade = "F"; 
}