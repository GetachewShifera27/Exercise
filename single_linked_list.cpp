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
#include <fstream>
#include <sstream>
#include <stdexcept>
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
const string FILENAME = "students.txt";

// Forward declaration
void insertAtEnd(int id, string fname, string lname, int age, string department, float cgpa, int graduationYear, int academicYear);

bool isDuplicateId(int id) {
    Student* temp = start;
    while (temp != NULL) {
        if (temp->id == id) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void saveToFile() {
    try {
        ofstream file(FILENAME.c_str());
        if (!file.is_open()) {
            throw runtime_error("Failed to open file for writing");
        }
        Student* temp = start;
        while (temp != NULL) {
            file << temp->id << "|" << temp->fname << "|" << temp->lname << "|" 
                 << temp->age << "|" << temp->department << "|" << temp->cgpa << "|" 
                 << temp->graduationYear << "|" << temp->academicYear << endl;
            temp = temp->next;
        }
        file.close();
        cout << "Data saved to file successfully" << endl;
    } catch (exception& e) {
        cout << "Error saving to file: " << e.what() << endl;
    }
}

void loadFromFile() {
    try {
        ifstream file(FILENAME.c_str());
        if (!file.is_open()) {
            cout << "File does not exist. Starting with empty list." << endl;
            return;
        }
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            int id, age, graduationYear, academicYear;
            string fname, lname, department;
            float cgpa;
            char delimiter;
            try {
                ss >> id >> delimiter >> fname >> delimiter >> lname >> delimiter 
                   >> age >> delimiter >> department >> delimiter >> cgpa >> delimiter 
                   >> graduationYear >> delimiter >> academicYear;
                insertAtEnd(id, fname, lname, age, department, cgpa, graduationYear, academicYear);
            } catch (exception& e) {
                cout << "Error parsing line from file: " << e.what() << endl;
            }
        }
        file.close();
        cout << "Data loaded from file successfully" << endl;
    } catch (exception& e) {
        cout << "Error loading from file: " << e.what() << endl;
    }
}
void insertAtStart(int id, string fname, string lname, int age, string department, float cgpa, int graduationYear, int academicYear) {
    try {
        if (isDuplicateId(id)) {
            throw runtime_error("Student with this ID already exists!");
        }
        if (id <= 0 || age <= 0 || cgpa < 0 || cgpa > 4.0 || graduationYear <= 0 || academicYear <= 0) {
            throw invalid_argument("Invalid input values");
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
        newStudent->next = start;
        start = newStudent;
        cout << "Student added successfully at start" << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
void insertAtEnd(int id, string fname, string lname, int age, string department, float cgpa, int graduationYear, int academicYear) {
    try {
        if (isDuplicateId(id)) {
            throw runtime_error("Student with this ID already exists!");
        }
        if (id <= 0 || age <= 0 || cgpa < 0 || cgpa > 4.0 || graduationYear <= 0 || academicYear <= 0) {
            throw invalid_argument("Invalid input values");
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
        if (start == NULL) {
            start = newStudent;
            cout << "Student added successfully at end" << endl;
            return;
        }
        Student* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
        cout << "Student added successfully at end" << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
void insertAtPosition(int id, string fname, string lname, int age, string department, float cgpa, int graduationYear, int academicYear, int position) {
    try {
        if (isDuplicateId(id)) {
            throw runtime_error("Student with this ID already exists!");
        }
        if (id <= 0 || age <= 0 || cgpa < 0 || cgpa > 4.0 || graduationYear <= 0 || academicYear <= 0) {
            throw invalid_argument("Invalid input values");
        }
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
            throw out_of_range("Position out of bounds");
        }
        newStudent->next = temp->next;
        temp->next = newStudent;
        cout << "Student added successfully at position " << position << endl;
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
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
    try {
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
                if (temp->age <= 0) throw invalid_argument("Age must be positive");
                cout << "Department: ";
                cin >> temp->department;
                cout << "CGPA: ";
                cin >> temp->cgpa;
                if (temp->cgpa < 0 || temp->cgpa > 4.0) throw invalid_argument("CGPA must be between 0 and 4.0");
                cout << "Graduation Year: ";
                cin >> temp->graduationYear;
                if (temp->graduationYear <= 0) throw invalid_argument("Graduation year must be positive");
                cout << "Academic Year: ";
                cin >> temp->academicYear;
                if (temp->academicYear <= 0) throw invalid_argument("Academic year must be positive");
                cout << "Student record updated successfully" << endl;
                return;
            }
            temp = temp->next;
        }
        throw runtime_error("Student not found");
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}
int main() {
    try {
        loadFromFile();
    } catch (exception& e) {
        cout << "Error loading file: " << e.what() << endl;
    }
    int choice;
    do {
        try {
            cout << "\n=== Main Menu ===" << endl;
            cout << "1. Insert" << endl;
            cout << "2. Delete" << endl;
            cout << "3. Search" << endl;
            cout << "4. Update" << endl;
            cout << "5. Display All Students" << endl;
            cout << "6. Save and Exit" << endl;
            cout << "Enter your choice: ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Invalid input. Please enter a number.");
            }
            switch (choice) {
                case 1: {
                    int id, age, graduationYear, academicYear, position;
                    string fname, lname, department;
                    float cgpa;
                    try {
                        cout << "\n=== Insert Student ===" << endl;
                        cout << "ID: ";
                        if (!(cin >> id)) throw invalid_argument("Invalid ID. Must be an integer.");
                        cout << "First Name: ";
                        cin >> fname;
                        cout << "Last Name: ";
                        cin >> lname;
                        cout << "Age: ";
                        if (!(cin >> age)) throw invalid_argument("Invalid Age. Must be an integer.");
                        cout << "Department: ";
                        cin >> department;
                        cout << "CGPA: ";
                        if (!(cin >> cgpa)) throw invalid_argument("Invalid CGPA. Must be a number.");
                        cout << "Graduation Year: ";
                        if (!(cin >> graduationYear)) throw invalid_argument("Invalid Graduation Year. Must be an integer.");
                        cout << "Academic Year: ";
                        if (!(cin >> academicYear)) throw invalid_argument("Invalid Academic Year. Must be an integer.");
                        cout << "Insert at position (1 for start, -1 for end): ";
                        if (!(cin >> position)) throw invalid_argument("Invalid position. Must be an integer.");
                        if (position == 1) {
                            insertAtStart(id, fname, lname, age, department, cgpa, graduationYear, academicYear);
                        } else if (position == -1) {
                            insertAtEnd(id, fname, lname, age, department, cgpa, graduationYear, academicYear);
                        } else {
                            insertAtPosition(id, fname, lname, age, department, cgpa, graduationYear, academicYear, position);
                        }
                    } catch (exception& e) {
                        cout << "Error: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    break;
                }
                case 2: {
                    int position;
                    try {
                        cout << "\n=== Delete Student ===" << endl;
                        cout << "Delete at position (1 for start, -1 for end): ";
                        if (!(cin >> position)) throw invalid_argument("Invalid position. Must be an integer.");
                        if (position == 1) {
                            deleteAtStart();
                        } else if (position == -1) {
                            deleteAtEnd();
                        } else {
                            deleteAtPosition(position);
                        }
                    } catch (exception& e) {
                        cout << "Error: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    break;
                }
                case 3: {
                    int id;
                    try {
                        cout << "\n=== Search Student ===" << endl;
                        cout << "Enter student ID to search: ";
                        if (!(cin >> id)) throw invalid_argument("Invalid ID. Must be an integer.");
                        searchById(id);
                    } catch (exception& e) {
                        cout << "Error: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    break;
                }
                case 4: {
                    int id;
                    try {
                        cout << "\n=== Update Student ===" << endl;
                        cout << "Enter student ID to update: ";
                        if (!(cin >> id)) throw invalid_argument("Invalid ID. Must be an integer.");
                        updateStudentRecord(id);
                    } catch (exception& e) {
                        cout << "Error: " << e.what() << endl;
                        cin.clear();
                        cin.ignore(10000, '\n');
                    }
                    break;
                }
                case 5: {
                    try {
                        cout << "\n=== Display All Students ===" << endl;
                        displayAllStudents();
                    } catch (exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                }
                case 6: {
                    try {
                        saveToFile();
                        cout << "Exiting..." << endl;
                    } catch (exception& e) {
                        cout << "Error: " << e.what() << endl;
                    }
                    break;
                }
                default: {
                    cout << "Invalid choice. Please try again." << endl;
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
            }
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while (choice != 6);
    return 0;
}

