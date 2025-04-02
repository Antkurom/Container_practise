#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct student{
    int StudentID;
    string name;
    int age;
    double grade;


    bool operator==(const student& other) const {
        return StudentID == other.StudentID &&
               name == other.name &&
               age == other.age &&
               grade == other.grade;
    }
};


void add_student(vector<student>& StudentDatabase);
void display(student st);
void display_all(vector<student> StudentDatabase);
void find_by_name(vector<student> StudentDatabase);
void find_by_ID(vector<student> StudentDatabase);
void delete_student(vector<student> StdentDatabase, student st);
void delete_by_name(vector<student> StudentDatabase);
void delete_by_ID(vector<student> StudentDatabase);


int main(){
    vector<student> StudentDatabase;
    cout << "You are in a Student Database. There is several options what you can do: \n";
    while (true){
        int input;
        cout << "\nTo exit from a program: --> 0\n"<<
                "Add a new student: --> 1\n" <<
                "Find a student by name: --> 2\n" <<
                "Find a student by ID: --> 3\n" <<
                "Display all students: --> 4\n" <<
                "Delete all: --> 5\n" <<
                "Delete by name: --> 6\n" <<
                "Delete by ID: --> 7\n";
        cin >> input;
        switch (input){
            case(0):
            cout << "Exiting from the system...\n";
            return 0;
            case(1):
            cout << "Adding a new student...\n";
            add_student(StudentDatabase);
            break;
            case(2):
            cout << "Find a student by name...\n";
            find_by_name(StudentDatabase);
            break;
            case(3):
            cout << "Find a student by ID...\n";
            find_by_ID(StudentDatabase);
            break;
            case(4):
            cout << "Display all students in database...\n";
            display_all(StudentDatabase);
            break;
            case(5):
            cout << "Deleting everything...\n";
            StudentDatabase.clear();
            cout << "Operation is completed successfully";
            break;
            case(6):
            cout << "Deleting a student by his name...\n";
            delete_by_name(StudentDatabase);
            break;
            case(7):
            cout << "Deleting a student by his ID...\n";
            delete_by_ID(StudentDatabase);
            break;
            default:
            break;
        }
    }
}


void add_student(vector<student>& StudentDatabase){
    int studentID;
    string name;
    int age;
    double grade;
    student somebody;


    cout << "\nEnter student ID: ";
    cin >> studentID;
    somebody.StudentID = studentID;


    cout << "Enter name of a student: ";
    cin >> name;
    somebody.name = name;


    cout << "Enter age of a student: ";
    cin >> age;
    somebody.age = age;


    cout << "Enter grade of a student: ";
    cin >> grade;
    somebody.grade = grade;




    StudentDatabase.push_back(somebody);
}


void display(student st){
    cout << "\nStudent ID: " << st.StudentID << endl;
    cout << "Student name: " << st.name << endl;
    cout << "Student age: " << st.age << endl;
    cout << "Student grade: " << st.grade << endl;
}


void display_all(vector<student> StudentDatabase){
    for (student st: StudentDatabase){
        cout << "\n---------------------------------------------\n";
        display(st);
    }
}


void find_by_name(vector<student> StudentDatabase){
    string name;
    int success = 0;
    cout << "Enter name of a student: ";
    cin >> name;


    for (student st: StudentDatabase){
        if(st.name == name){
            display(st);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a student with such name. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}


void find_by_ID(vector<student> StudentDatabase){
    int ID;
    int success = 0;
    cout << "Enter a student ID: ";
    cin >> ID;


    for (student st: StudentDatabase){
        if(st.StudentID == ID){
            display(st);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a student with such ID. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}


void delete_student(vector<student> StudentDatabase, student st){
    StudentDatabase.erase(remove(StudentDatabase.begin(), StudentDatabase.end(), st), StudentDatabase.end());
}


void delete_by_name(vector<student> StudentDatabase){
    string name;
    int success = 0;
    cout << "Enter name of a student, that you want to delete from database: \n";
    cin >> name;


    for (student st: StudentDatabase){
        if(st.name == name){
            delete_student(StudentDatabase, st);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a student with such name. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}


void delete_by_ID(vector<student> StudentDatabase){
    int ID;
    int success = 0;


    cout << "Enter ID of a student, that you want to delete: \n";
    cin >> ID;


    for (student st: StudentDatabase){
        if(st.StudentID == ID){
            delete_student(StudentDatabase, st);
            success++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a student with such ID. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}


