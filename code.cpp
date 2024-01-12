#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    double grade;
};

void displayMenu() {
    cout << "\n----- Grade Tracker Menu -----\n";
    cout << "1. Add a Student\n";
    cout << "2. Display All Students\n";
    cout << "3. Calculate Average Grade\n";
    cout << "4. Display Highest and Lowest Grade\n";
    cout << "5. Exit\n";
}

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    cin >> newStudent.name;
    cout << "Enter student grade: ";
    cin >> newStudent.grade;
    students.push_back(newStudent);
}

void displayAllStudents(const vector<Student>& students) {
    cout << "\n----- All Students -----\n";
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Grade: " << student.grade << endl;
    }
}

double calculateAverageGrade(const vector<Student>& students) {
    double total = 0.0;
    for (const auto& student : students) {
        total += student.grade;
    }
    return (students.empty()) ? 0.0 : (total / students.size());
}

void displayHighLowGrade(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students entered yet.\n";
        return;
    }

    auto maxGrade = max_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });

    auto minGrade = min_element(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.grade < b.grade;
    });

    cout << "\nHighest Grade: " << maxGrade->name << " - " << maxGrade->grade << endl;
    cout << "Lowest Grade: " << minGrade->name << " - " << minGrade->grade << endl;
}

int main() {
    vector<Student> students;

    while (true) {
        displayMenu();

        int choice;
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                cout << "Average Grade: " << calculateAverageGrade(students) << endl;
                break;
            case 4:
                displayHighLowGrade(students);
                break;
            case 5:
                cout << "Exiting the Grade Tracker. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please choose a number between 1 and 5.\n";
        }
    }

    return 0;
}
