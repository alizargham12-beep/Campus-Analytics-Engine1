 #ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

// Using structs only as required by rubric
struct Student {
    string roll, name, dept, status;
    double cgpa;
};

// M1 Functions
vector<vector<string>> readTXT(string filename);
void writeTXT(string filename, const vector<vector<string>>& data, string header);
void appendTXT(string filename, const string& row);
vector<string> findRow(string filename, int colIndex, string searchValue);
bool rowExists(string filename, int colIndex, string searchValue);

#endif
