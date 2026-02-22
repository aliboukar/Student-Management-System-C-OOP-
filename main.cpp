#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {

private:
    string name;
    int id;
    double grade;

public:
    
    Student(string n, int num, double g) {
        name = n;
        id = num;
        grade = g;
    }

    int getID() {
        return id;
    }

    double getGrade() {
        return grade;
    }

    void updateGrade(double newGrade) {
        grade = newGrade;
    }

    void displayinfo() {
        cout << "Student name is: " << name << endl;
        cout << "Student ID is: " << id << endl;
        cout << "Student grade is: " << grade << endl;
    }
};

int main() {
    string name;
    int id;
    double grade;

    vector<Student> students;
    int choice;

    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. Update the grade" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Display all Students" << endl;
        cout << "5. Exit" << endl;

        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter your name: " << endl;
                cin >> name;
                cout << "Enter your ID: " << endl;
                cin >> id;
                cout << "Enter your grade: " << endl;
                cin >> grade;
                students.push_back(Student(name, id, grade));
                cout << "Student added successfully" << endl;
                break;
            }
            case 2: {
                bool found = false;
                int EnteredID;
                double newGrade;

                cout<<"Enter your ID"<<endl;
                cin>>EnteredID;
                cout<<"Enter New Grade Here: "<<endl;
                cin>>newGrade;
                for(auto &student : students){
                    if(student.getID() == EnteredID){
                        student.updateGrade(newGrade);
                        found = true;
                        cout<<"Grade updated !"<<endl;
                        break;
                    }
                }
                if(!found) {cout<<"Grade not updated"<<endl;

                }
                break;
            }
            case 3 : {
                int EnteredID;
                bool found = false;

                cout<<"Enter ID: "<<endl;
                cin>>EnteredID;
                for(auto &student : students) {
                if(student.getID() == EnteredID) {
                student.displayinfo();
                found = true;
                break;
    }
}
if(!found) {
    cout<<"student not found"<<endl;
}

break;
        }
            case 4: {
                if (students.empty()) {
                    cout << "No students to display." << endl;
                } else {
                    for (auto &student : students) {
                        student.displayinfo();
                    }
                }
                break;
            }

            case 5:
                return 0;

            default:
                cout << "Invalid choice!" << endl;
    }
    }
    return 0;
}
