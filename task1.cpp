#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<double> grade(n), credit(n);
    double totalCredits = 0, totalGradePoints = 0;

    for(int i = 0; i < n; i++) {
        cout << "\nCourse " << i + 1 << " Grade (0–10): ";
        cin >> grade[i];
        cout << "Course " << i + 1 << " Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    double gpa = totalGradePoints / totalCredits;
    double cgpa = gpa;   // assuming single semester for now

    cout << "\n-------------------------------";
    cout << "\n     COURSE DETAILS\n";
    cout << "-------------------------------\n";

    for(int i = 0; i < n; i++)
        cout << "Course " << i + 1 << " => Grade: " << grade[i]
             << ", Credit: " << credit[i] << endl;

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nGPA: " << gpa;
    cout << "\nCGPA: " << cgpa;
    cout << "\n-------------------------------\n";

    return 0;
}
