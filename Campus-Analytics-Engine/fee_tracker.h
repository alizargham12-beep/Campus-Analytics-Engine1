#ifndef FEE_TRACKER_H
#define FEE_TRACKER_H

#include <string>
#include <vector>

using namespace std;

// M6 Function declarations
int daysBetween(string date1, string date2);
double computeLateFine(string dueDate, string paidDate, double amountDue);
void generateReceipt(string roll, double amountDue, double amountPaid, double fine);

#endif