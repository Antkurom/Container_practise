#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct employee{
    int employeeID;
    string name;
    string department;
    string position;
    string salary;

    bool operator==(const employee& other) const {
        return employeeID == other.employeeID &&
               name == other.name &&
               position == other.position &&
               department == other.department &&
               salary == other.salary;
    }
};


void add_employee(vector<employee>& employeeDatabase);
void display(employee em);
void display_all(vector<employee> employeeDatabase);
void find_by_name(vector<employee> employeeDatabase);
void find_by_ID(vector<employee> employeeDatabase);
void delete_employee(vector<employee> StdentDatabase, employee em);
void delete_by_name(vector<employee> employeeDatabase);
void delete_by_ID(vector<employee> employeeDatabase);
void update_employee(vector<employee> employeeDatabase);


int main(){
    vector<employee> employeeDatabase;
    cout << "You are in a employee Database. There is several options what you can do: \n";
    while (true){
        int input;
        cout << "\nTo exit from a program: --> 0\n"<<
                "Add a new employee: --> 1\n" <<
                "Find a employee by name: --> 2\n" <<
                "Find a employee by ID: --> 3\n" <<
                "Display all employees: --> 4\n" <<
                "Delete all: --> 5\n" <<
                "Delete by name: --> 6\n" <<
                "Delete by ID: --> 7\n";
        cin >> input;
        switch (input){
            case(0):
            cout << "Exiting from the system...\n";
            return 0;
            case(1):
            cout << "Adding a new employee...\n";
            add_employee(employeeDatabase);
            break;
            case(2):
            cout << "Find a employee by name...\n";
            find_by_name(employeeDatabase);
            break;
            case(3):
            cout << "Find a employee by ID...\n";
            find_by_ID(employeeDatabase);
            break;
            case(4):
            cout << "Display all employees in database...\n";
            display_all(employeeDatabase);
            break;
            case(5):
            cout << "Deleting everything...\n";
            employeeDatabase.clear();
            cout << "Operation is completed successfully";
            break;
            case(6):
            cout << "Deleting a employee by his name...\n";
            delete_by_name(employeeDatabase);
            break;
            case(7):
            cout << "Deleting a employee by his ID...\n";
            delete_by_ID(employeeDatabase);
            break;
            default:
            break;
        }
    }
}


void add_employee(vector<employee>& employeeDatabase){
    int employeeID;
    string name;
    string department;
    string position;
    int salary;

    employee somebody;


    cout << "\nEnter employee ID: ";
    cin >> employeeID;
    somebody.employeeID = employeeID;


    cout << "Enter name of a employee: ";
    cin >> name;
    somebody.name = name;


    cout << "Enter department of a employee: ";
    cin >> department;
    somebody.department = department;


    cout << "Enter position of a employee: ";
    cin >> position;
    somebody.position = position;

    cout << "Enter salary of a employee: ";
    cin >> salary;
    somebody.salary;




    employeeDatabase.push_back(somebody);
}


void display(employee em){
    cout << "\nemployee ID: " << em.employeeID << endl;
    cout << "employee name: " << em.name << endl;
    cout << "employee department: " << em.department << endl;
    cout << "employee position: " << em.position << endl;
    cout << "employee salary: " << em.salary << endl;
}


void display_all(vector<employee> employeeDatabase){
    for (employee em: employeeDatabase){
        cout << "\n---------------------------------------------\n";
        display(em);
    }
}


void find_by_name(vector<employee> employeeDatabase){
    string name;
    int success = 0;
    cout << "Enter name of a employee: ";
    cin >> name;


    for (employee em: employeeDatabase){
        if(em.name == name){
            display(em);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a employee with such name. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}


void find_by_ID(vector<employee> employeeDatabase){
    int ID;
    int success = 0;
    cout << "Enter a employee ID: ";
    cin >> ID;


    for (employee em: employeeDatabase){
        if(em.employeeID == ID){
            display(em);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a employee with such ID. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}


void delete_employee(vector<employee> employeeDatabase, employee em){
    employeeDatabase.erase(remove(employeeDatabase.begin(), employeeDatabase.end(), em), employeeDatabase.end());
}


void delete_by_name(vector<employee> employeeDatabase){
    string name;
    int success = 0;
    cout << "Enter name of a employee, that you want to delete from database: \n";
    cin >> name;


    for (employee em: employeeDatabase){
        if(em.name == name){
            delete_employee(employeeDatabase, em);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a employee with such name. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}


void delete_by_ID(vector<employee> employeeDatabase){
    int ID;
    int success = 0;


    cout << "Enter ID of a employee, that you want to delete: \n";
    cin >> ID;


    for (employee em: employeeDatabase){
        if(em.employeeID == ID){
            delete_employee(employeeDatabase, em);
            success++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a employee with such ID. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully";
    }
}

void update_employee(vector<employee> employeeDatabase){
    int input;
    cout << "Search by ID (0) or name (1):\n";
    cin >> input;
    string name;
    int ID;
    int success = 0;
    switch(input){
        case(0):
        cout << "Enter name of a employee, that you want to delete from database: \n";
        cin >> name;


        for (employee em: employeeDatabase){
            if(em.name == name){
                success ++;
                cout << "Employee was found successfully. What would you like to change";
                while(true){
                    display(em);
                    int input;
                    cout << "employeeID --> 0\n" <<
                    "name --> 1\n" <<
                    "department --> 2\n" <<
                    "position --> 3\n" <<
                    "salary --> 4\n";
                    cin >> input;

                    int new_ID;
                    string new_name;
                    string new_department;
                    string new_position;
                    int new_salary;

                    switch (input){
                        case(0):
                        cout << "Enter new employeeID: ";
                        cin >> new_ID;
                        em.employeeID = new_ID;
                        break;
                        case(1):
                        cout << "Enter new name: ";
                        cin >> new_name;
                        em.name = new_name;
                        break;
                        case(2):
                        cout << "Enter new department: ";
                        cin >> new_department;
                        em.department = new_department;
                        break;
                        case(3):
                        cout << "Enter new position: ";
                        cin >> new_position;
                        em.position = new_position;
                        break;
                        case(4):
                        cout << "Enter new salary: ";
                        cin >> new_salary;
                        em.salary = new_salary;
                        break;
                    }
                }
                break;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a employee with such name. Check your spelling\n";
        } 
        break;
        case(1):
        cout << "Enter a employee ID: ";
        cin >> ID;


        for (employee em: employeeDatabase){
            if(em.employeeID == ID){
                success ++;
                cout << "Employee was found successfully. What would you like to change";
                while(true){
                    display(em);
                    int input;
                    cout << "employeeID --> 0\n" <<
                    "name --> 1\n" <<
                    "department --> 2\n" <<
                    "position --> 3\n" <<
                    "salary --> 4\n";
                    cin >> input;

                    int new_ID;
                    string new_name;
                    string new_department;
                    string new_position;
                    int new_salary;

                    switch (input){
                        case(0):
                        cout << "Enter new employeeID: ";
                        cin >> new_ID;
                        em.employeeID = new_ID;
                        break;
                        case(1):
                        cout << "Enter new name: ";
                        cin >> new_name;
                        em.name = new_name;
                        break;
                        case(2):
                        cout << "Enter new department: ";
                        cin >> new_department;
                        em.department = new_department;
                        break;
                        case(3):
                        cout << "Enter new position: ";
                        cin >> new_position;
                        em.position = new_position;
                        break;
                        case(4):
                        cout << "Enter new salary: ";
                        cin >> new_salary;
                        em.salary = new_salary;
                        break;
                    }
                }
                break;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a employee with such ID. Check your spelling\n";
        } 

        }

}
