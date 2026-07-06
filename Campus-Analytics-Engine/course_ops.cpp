#include "filehandler.h"
#include <iostream>
#include <fstream>

using namespace std;

// Reads all data from a text file, skipping the header row
vector<vector<string>> readTXT(string filename) {
    vector<vector<string>> data;
    ifstream file(filename);
    string line;
    
    // Skip the first line (the header)
    if (file.is_open()) {
        getline(file, line); 
    }
    
    // Read the rest of the lines
    while (getline(file, line)) {
        vector<string> row;
        string currentWord = "";
        
        // Manual split by comma (student friendly way)
        for (int i = 0; i < line.length(); i++) {
            if (line[i] == ',') {
                row.push_back(currentWord);
                currentWord = ""; // reset for next word
            } else {
                currentWord += line[i];
            }
        }
        row.push_back(currentWord); // Add the last word
        data.push_back(row);
    }
    file.close();
    return data;
}

// Overwrites the file completely (used when updating or deleting)
void writeTXT(string filename, string header, const vector<vector<string>>& data) {
    ofstream file(filename);
    
    // Write header first
    file << header << "\n";
    
    // Write all rows
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            file << data[i][j];
            if (j != data[i].size() - 1) {
                file << ","; // Add comma between words
            }
        }
        file << "\n";
    }
    file.close();
}

// Adds one new row to the bottom of the file
void appendTXT(string filename, const vector<string>& row) {
    // ios::app means "append" mode so it doesn't delete old data
    ofstream file(filename, ios::app); 
    
    for (int i = 0; i < row.size(); i++) {
        file << row[i];
        if (i != row.size() - 1) {
            file << ",";
        }
    }
    file << "\n";
    file.close();
}

// Finds and returns a specific row (like finding a student by roll number)
vector<string> findRow(string filename, int colIndex, string searchValue) {
    vector<vector<string>> data = readTXT(filename);
    for (int i = 0; i < data.size(); i++) {
        if (data[i].size() > colIndex && data[i][colIndex] == searchValue) {
            return data[i];
        }
    }
    return vector<string>(); // Return empty if not found
}

// Checks if a record already exists to prevent duplicates
bool rowExists(string filename, int colIndex, string searchValue) {
    vector<vector<string>> data = readTXT(filename);
    for (int i = 0; i < data.size(); i++) {
        if (data[i].size() > colIndex && data[i][colIndex] == searchValue) {
            return true;
        }
    }
    return false;
}