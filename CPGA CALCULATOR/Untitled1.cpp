#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Course {
private:
    string courseName;
    int credits;
    double gradePoints;

public:
    Course(string name, int cr, double gp) : courseName(name), credits(cr), gradePoints(gp) {}
    
    int getCredits() const { return credits; }
    double getGradePoints() const { return gradePoints; }
    string getName() const { return courseName; }
};

class Student {
private:
    vector<Course> courses;

public:
    void addCourse(string name, int credits, double gradePoints) {
        if (credits <= 0 || gradePoints < 0.0 || gradePoints > 4.0) {
            cout << "Invalid input! Please enter valid credits and grade points.\n";
            return;
        }
        courses.push_back(Course(name, credits, gradePoints));
        cout << "Course added successfully!\n";
    }
    
    void deleteCourse(string name) {
        for (auto it = courses.begin(); it != courses.end(); ++it) {
            if (it->getName() == name) {
                courses.erase(it);
                cout << "Course removed successfully!\n";
                return;
            }
        }
        cout << "Course not found!\n";
    }

    void displayCourses() const {
        if (courses.empty()) {
            cout << "No courses added yet.\n";
            return;
        }
        cout << "\nCourses Taken:\n";
        cout << left << setw(20) << "Course Name" << setw(10) << "Credits" << "Grade Points" << endl;
        for (const auto &course : courses) {
            cout << left << setw(20) << course.getName() << setw(10) << course.getCredits() << course.getGradePoints() << endl;
        }
    }
    
    double calculateGPA() const {
        if (courses.empty()) return 0.0;
        double totalGradePoints = 0.0;
        int totalCredits = 0;
        for (const auto &course : courses) {
            totalGradePoints += course.getGradePoints() * course.getCredits();
            totalCredits += course.getCredits();
        }
        return totalCredits == 0 ? 0.0 : (totalGradePoints / totalCredits);
    }
};

int main() {
    Student student;
    int choice;
    do {
        cout << "\nCGPA Calculator\n";
        cout << "1. Add Course\n";
        cout << "2. Delete Course\n";
        cout << "3. Display Courses\n";
        cout << "4. Calculate GPA\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string name;
                int credits;
                double gradePoints;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Credits: ";
                cin >> credits;
                cout << "Enter Grade Points (0.0 - 4.0): ";
                cin >> gradePoints;
                student.addCourse(name, credits, gradePoints);
                break;
            }
            case 2: {
                string name;
                cout << "Enter Course Name to delete: ";
                cin.ignore();
                getline(cin, name);
                student.deleteCourse(name);
                break;
            }
            case 3:
                student.displayCourses();
                break;
            case 4:
                cout << "Your GPA is: " << fixed << setprecision(2) << student.calculateGPA() << endl;
                break;
            case 5:
                cout << "Exiting Program...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}
