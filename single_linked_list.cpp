//single linked list implementation in c++ that register student id,fname,lname,age,department,cgpa,graduatoion year,and academic year by accept from user
// insert at start, insert at end, insert at position, delete at start, delete at end, delete at position, search by id, display all students
//update student record by id
//duplicate id check method
//when we click insert display insert at start, insert at end, insert at position and back to main menu
//when we click delete display delete at start, delete at end, delete at position and back to main menu
//when we click search display search by id and back to main menu
//when we click update display update by id and back to main menu
//when we click display all students display all students and back to main menu
//main menu display insert, delete, search, update, display all students and exit

#include <iostream>
using namespace std;
struct Student {
    int id;
    string fname;
    string lname;
    int age;
    string department;
    float cgpa;
    int graduationYear;
    int academicYear;
    Student* next;
};
Student *start = NULL;
void insertAtStart(int id, string fname, string lname, int age, string department, float cgpa, int graduationYear, int academicYear) {
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->fname = fname;
    newStudent->lname = lname;
    newStudent->age = age;
    newStudent->department = department;
    newStudent->cgpa = cgpa;
    newStudent->graduationYear = graduationYear;
    newStudent->academicYear = academicYear;
    newStudent->next = start;
    start = newStudent;
}
void insertAtEnd(int id, string fname, string lname, int age, string department, float cgpa, int graduationYear, int academicYear) {
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->fname = fname;
    newStudent->lname = lname;
    newStudent->age = age;
    newStudent->department = department;
    newStudent->cgpa = cgpa;
    newStudent->graduationYear = graduationYear;
    newStudent->academicYear = academicYear;
    newStudent->next = NULL;
    if (start == NULL) {
        start = newStudent;
        return;
    }
    Student* temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newStudent;
}
void insertAtPosition(int id, string fname, string lname, int age, string department, float cgpa, int graduationYear, int academicYear, int position) {
    if (position == 1) {
        insertAtStart(id, fname, lname, age, department, cgpa, graduationYear, academicYear);
        return;
    }
    Student* newStudent = new Student;
    newStudent->id = id;
    newStudent->fname = fname;
    newStudent->lname = lname;
    newStudent->age = age;
    newStudent->department = department;
    newStudent->cgpa = cgpa;
    newStudent->graduationYear = graduationYear;
    newStudent->academicYear = academicYear;
    newStudent->next = NULL;
    Student* temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    newStudent->next = temp->next;
    temp->next = newStudent;
}
void deleteAtStart() {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Student* temp = start;
    start = start->next;
    delete temp;
}
void deleteAtEnd() {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (start->next == NULL) {
        delete start;
        start = NULL;
        return;
    }
    Student* temp = start;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}
void deleteAtPosition(int position) {
    if (start == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (position == 1) {
        deleteAtStart();
        return;
    }
    Student* temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    Student* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
}
void searchById(int id) {
    Student* temp = start;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Student found: " << temp->fname << " " << temp->lname << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found" << endl;
}
void displayAllStudents() {
    Student* temp = start;
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Name: " << temp->fname << " " << temp->lname << ", Age: " << temp->age
             << ", Department: " << temp->department << ", CGPA: " << temp->cgpa
             << ", Graduation Year: " << temp->graduationYear << ", Academic Year: " << temp->academicYear << endl;
        temp = temp->next;
    }
}
void updateStudentRecord(int id) {
    Student* temp = start;
    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Enter new details for the student:" << endl;
            cout << "First Name: ";
            cin >> temp->fname;
            cout << "Last Name: ";
            cin >> temp->lname;
            cout << "Age: ";
            cin >> temp->age;
            cout << "Department: ";
            cin >> temp->department;
            cout << "CGPA: ";
            cin >> temp->cgpa;
            cout << "Graduation Year: ";
            cin >> temp->graduationYear;
            cout << "Academic Year: ";
            cin >> temp->academicYear;
            cout << "Student record updated successfully" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found" << endl;
}
int main() {
    int choice;
    do {
        cout << "Main Menu:" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Search" << endl;
        cout << "4. Update" << endl;
        cout << "5. Display All Students" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int id, age, graduationYear, academicYear, position;
                string fname, lname, department;
                float cgpa;
                cout << "Enter student details:" << endl;
                cout << "ID: ";
                cin >> id;
                cout << "First Name: ";
                cin >> fname;
                cout << "Last Name: ";
                cin >> lname;
                cout << "Age: ";
                cin >> age;
                cout << "Department: ";
                cin >> department;
                cout << "CGPA: ";
                cin >> cgpa;
                cout << "Graduation Year: ";
                cin >> graduationYear;
                cout << "Academic Year: ";
                cin >> academicYear;
                cout << "Insert at position (1 for start, -1 for end): ";
                cin >> position;
                if (position == 1) {
                    insertAtStart(id, fname, lname, age, department, cgpa, graduationYear, academicYear);
                } else if (position == -1) {
                    insertAtEnd(id, fname, lname, age, department, cgpa, graduationYear, academicYear);
                } else {
                    insertAtPosition(id, fname, lname, age, department, cgpa, graduationYear, academicYear, position);
                }
                break;
            }
            case 2: {
                int position;
                cout << "Delete at position (1 for start, -1 for end): ";
                cin >> position;
                if (position == 1) {
                    deleteAtStart();
                } else if (position == -1) {
                    deleteAtEnd();
                } else {
                    deleteAtPosition(position);
                }
                break;
            }
            case 3: {
                int id;
                cout << "Enter student ID to search: ";
                cin >> id;
                searchById(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter student ID to update: ";
                cin >> id;
                updateStudentRecord(id);
                break;
            }
            case 5: {
                displayAllStudents();
                break;
            }
            case 6: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    } while (choice != 6);
    return 0;
}

