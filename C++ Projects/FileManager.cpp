#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;

int main() {
    // Get the current working directory
    string currentDirectory = filesystem::current_path();

    // Display the current working directory
    cout << "Current working directory: " << currentDirectory << endl;

    // Get the user's input for the file operation
    string operation;
    cout << "Enter operation (create, read, write, delete): ";
    cin >> operation;

    // Get the user's input for the file name
    string fileName;
    cout << "Enter file name: ";
    cin >> fileName;

    // Create a file
    if (operation == "create") {
        ofstream file(fileName);
        if (file.is_open()) {
            cout << "File created successfully." << endl;
            file.close();
        } else {
            cout << "Error creating file." << endl;
        }
    }

    // Read a file
    else if (operation == "read") {
        ifstream file(fileName);
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Error opening file." << endl;
        }
    }

    // Write to a file
    else if (operation == "write") {
        ofstream file(fileName);
        if (file.is_open()) {
            string content;
            cout << "Enter content to write: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, content);
            file << content;
            file.close();
            cout << "Content written to file successfully." << endl;
        } else {
            cout << "Error opening file." << endl;
        }
    }

    // Delete a file
    else if (operation == "delete") {
        if (remove(fileName.c_str()) == 0) {
            cout << "File deleted successfully." << endl;
        } else {
            cout << "Error deleting file." << endl;
        }
    }

    // Invalid operation