#include "filehandler.h"
#include <fstream>
#include <iostream>

using namespace std;

// Opens file and parses using character loop (no getline split)
vector<vector<string> > readTXT(string filename) {
    vector<vector<string> > table;
    ifstream file(filename.c_str());
    if (!file.is_open()) return table;

    string line;
    // Skip header row
    getline(file, line);

    while (getline(file, line)) {
        vector<string> row;
        string currentField = "";
        bool inQuotes = false;

        for (size_t i = 0; i < line.length(); ++i) {
            char c = line[i];
            if (c == '"') {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                row.push_back(currentField);
                currentField = "";
            } else {
                currentField += c;
            }
        }
        row.push_back(currentField);
        table.push_back(row);
    }
    file.close();
    return table;
}

// Opens file for overwrite and writes header row
void writeTXT(string filename, const vector<vector<string> >& data, string header) {
    ofstream file(filename.c_str());
    if (!file.is_open()) return;

    file << header << "\n";
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[i].size(); ++j) {
            file << data[i][j];
            if (j < data[i].size() - 1) file << ",";
        }
        file << "\n";
    }
    file.close();
}

// Appends a single row to the existing file
void appendTXT(string filename, const string& row) {
    ofstream file(filename.c_str(), ios::app);
    if (file.is_open()) {
        file << row << "\n";
        file.close();
    }
}

// Linear search through file rows
vector<string> findRow(string filename, int colIndex, string searchValue) {
    vector<vector<string> > data = readTXT(filename);
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].size() > colIndex && data[i][colIndex] == searchValue) {
            return data[i];
        }
    }
    return vector<string>();
}

// Returns true if any row has a value at colIndex
bool rowExists(string filename, int colIndex, string searchValue) {
    vector<vector<string> > data = readTXT(filename);
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i].size() > colIndex && data[i][colIndex] == searchValue) {
            return true;
        }
    }
    return false;
}
