#include "fee_tracker.h"
#include "filehandler.h"
#include <iostream>
#include <iomanip> // Required for formatted receipts

using namespace std;

// Parses DD-MM-YYYY and returns the difference in days without using <ctime>
int daysBetween(string date1, string date2) {
    int d1 = stoi(date1.substr(0, 2));
    int m1 = stoi(date1.substr(3, 2));
    int y1 = stoi(date1.substr(6, 4));
    
    int d2 = stoi(date2.substr(0, 2));
    int m2 = stoi(date2.substr(3, 2));
    int y2 = stoi(date2.substr(6, 4));
    
    // Simplified calculation assuming 30 days per month
    int total1 = (y1 * 365) + (m1 * 30) + d1; 
    int total2 = (y2 * 365) + (m2 * 30) + d2;
    
    return total2 - total1;
}

// Calculates 2% fine per complete week late
double computeLateFine(string dueDate, string paidDate, double amountDue) {
    int daysLate = daysBetween(dueDate, paidDate);
    if (daysLate > 0) {
        int weeksLate = daysLate / 7;
        return amountDue * (0.02 * weeksLate);
    }
    return 0.0;
}

// Generates a formatted receipt using iomanip
void generateReceipt(string roll, double amountDue, double amountPaid, double fine) {
    cout << "\n-----------------------------------" << endl;
    cout << "           FEE RECEIPT             " << endl;
    cout << "-----------------------------------" << endl;
    cout << left << setw(20) << "Roll Number:" << roll << endl;
    cout << left << setw(20) << "Tuition Due:" << amountDue << endl;
    cout << left << setw(20) << "Late Fine:" << fine << endl;
    cout << left << setw(20) << "Total Paid:" << amountPaid << endl;
    cout << left << setw(20) << "Balance:" << (amountDue + fine) - amountPaid << endl;
    cout << "-----------------------------------\n" << endl;
}