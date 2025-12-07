#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool userExists(string username) {
    ifstream file(username + ".txt");
    return file.good();
}

void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "Username already exists!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();

    cout << "Registration Successful!\n";
}

void loginUser() {
    string username, password, fileUser, filePass;
    cout << "Enter username: ";
    cin >> username;

    if (!userExists(username)) {
        cout << "User not found!\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ifstream file(username + ".txt");
    getline(file, fileUser);
    getline(file, filePass);

    if (password == filePass)
        cout << "Login Successful!\n";
    else
        cout << "Incorrect Password!\n";
}

int main() {
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1) registerUser();
    else if (choice == 2) loginUser();
    else cout << "Invalid choice!";

    return 0;
}
