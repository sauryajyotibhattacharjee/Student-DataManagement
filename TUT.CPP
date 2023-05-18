#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Student {
    int roll_number;
    string name;
    string address;
};

class StudentDatabase {
    private:
        vector<Student> students;
    public:
        void add_student(Student s);
        void delete_student(int roll_number);
        void search_student(int roll_number);
        void display_all_students();
};

void StudentDatabase::add_student(Student s) {
    students.push_back(s);
    cout << "Student record added successfully!" << endl;
}

void StudentDatabase::delete_student(int roll_number) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->roll_number == roll_number) {
            students.erase(it);
            cout << "Student record deleted successfully!" << endl;
            return;
        }
    }
    cout << "Student record not found!" << endl;
}

void StudentDatabase::search_student(int roll_number) {
    for (auto s : students) {
        if (s.roll_number == roll_number) {
            cout << "Roll Number: " << s.roll_number << endl;
            cout << "Name: " << s.name << endl;
            cout << "Address: " << s.address << endl;
            return;
        }
    }
    cout << "Student record not found!" << endl;
}

void StudentDatabase::display_all_students() {
    for (auto s : students) {
        cout << "Roll Number: " << s.roll_number << endl;
        cout << "Name: " << s.name << endl;
        cout << "Address: " << s.address << endl;
        cout << endl;
    }
}

int main() {
    StudentDatabase db;
    int choice;
    while (true) {
        cout << "-----------------------------" << endl;
        cout << "Enter your choice:" << endl;
        cout << "1. Add student record" << endl;
        cout << "2. Delete student record" << endl;
        cout << "3. Search student record" << endl;
        cout << "4. Display all student records" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 1:
                {
                    Student s;
                    cout << "Enter roll number: ";
                    cin >> s.roll_number;
                    cout << "Enter name: ";
                    cin >> s.name;
                    cout << "Enter address: ";
                    cin >> s.address;
                    db.add_student(s);
                    break;
                }
            case 2:
                {
                    int roll_number;
                    cout << "Enter roll number of student to delete: ";
                    cin >> roll_number;
                    db.delete_student(roll_number);
                    break;
                }
            case 3:
                {
                    int roll_number;
                    cout << "Enter roll number of student to search: ";
                    cin >> roll_number;
                    db.search_student(roll_number);
                    break;
                }
            case 4:
                db.display_all_students();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

