#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct task{
    int taskID;
    string name;
    string deadline;
    string status;
    int priority;

    bool operator==(const task& other) const {
        return taskID == other.taskID &&
               name == other.name &&
               status == other.status &&
               deadline == other.deadline &&
               priority == other.priority;
    }
};


void add_task(vector<task>& taskManager);
void display(task tsk);
void display_all(vector<task> taskManager);
void find_by_name(vector<task> taskManager);
void find_by_ID(vector<task> taskManager);
void delete_task(vector<task> StdentManager, task tsk);
void delete_by_name(vector<task> taskManager);
void delete_by_ID(vector<task> taskManager);
void update_task(vector<task> taskManager);


int main(){
    vector<task> taskManager;
    cout << "You are in a task Manager. There is several options what you can do: \n";
    while (true){
        int input;
        cout << "\nTo exit from a program: --> 0\n"<<
                "Add a new task: --> 1\n" <<
                "Find a task by name: --> 2\n" <<
                "Find a task by ID: --> 3\n" <<
                "Display all tasks: --> 4\n" <<
                "Delete all: --> 5\n" <<
                "Delete by name: --> 6\n" <<
                "Delete by ID: --> 7\n" <<
                "Update task information --> 8\n";
        cin >> input;
        switch (input){
            case(0):
            cout << "Exiting from the system...\n";
            return 0;
            case(1):
            cout << "Adding a new task...\n";
            add_task(taskManager);
            break;
            case(2):
            cout << "Find a task by name...\n";
            find_by_name(taskManager);
            break;
            case(3):
            cout << "Find a task by ID...\n";
            find_by_ID(taskManager);
            break;
            case(4):
            cout << "Display all tasks in Manager...\n";
            display_all(taskManager);
            break;
            case(5):
            cout << "Deleting everything...\n";
            taskManager.clear();
            cout << "Operation is completed successfully";
            break;
            case(6):
            cout << "Deleting a task by his name...\n";
            delete_by_name(taskManager);
            break;
            case(7):
            cout << "Deleting a task by his ID...\n";
            delete_by_ID(taskManager);
            break;
            case(8):
            cout << "Start changing task information...\n";
            update_task(taskManager);
            break;
            default:
            break;
        }
    }
}


void add_task(vector<task>& taskManager){
    int taskID;
    string name;
    string deadline;
    string status;
    int priority;

    task somebody;


    cout << "\nEnter task ID: ";
    cin >> taskID;
    somebody.taskID = taskID;


    cout << "Enter name of a task: ";
    cin >> name;
    somebody.name = name;


    cout << "Enter deadline of a task: ";
    cin >> deadline;
    somebody.deadline = deadline;


    cout << "Enter status of a task: ";
    cin >> status;
    somebody.status = status;

    cout << "Enter priority of a task: ";
    cin >> priority;
    somebody.priority;




    taskManager.push_back(somebody);
}


void display(task tsk){
    cout << "\ntask ID: " << tsk.taskID << endl;
    cout << "task name: " << tsk.name << endl;
    cout << "task deadline: " << tsk.deadline << endl;
    cout << "task status: " << tsk.status << endl;
    cout << "task priority: " << tsk.priority << endl;
}


void display_all(vector<task> taskManager){
    for (task tsk: taskManager){
        cout << "\n---------------------------------------------\n";
        display(tsk);
    }
}


void find_by_name(vector<task> taskManager){
    string name;
    int success = 0;
    cout << "Enter name of a task: ";
    cin >> name;


    for (task tsk: taskManager){
        if(tsk.name == name){
            display(tsk);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a task with such name. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully\n";
    }
}


void find_by_ID(vector<task> taskManager){
    int ID;
    int success = 0;
    cout << "Enter a task ID: ";
    cin >> ID;


    for (task tsk: taskManager){
        if(tsk.taskID == ID){
            display(tsk);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a task with such ID. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully\n";
    }
}


void delete_task(vector<task> taskManager, task tsk){
    taskManager.erase(remove(taskManager.begin(), taskManager.end(), tsk), taskManager.end());
}


void delete_by_name(vector<task> taskManager){
    string name;
    int success = 0;
    cout << "Enter name of a task, that you want to delete from Manager: \n";
    cin >> name;


    for (task tsk: taskManager){
        if(tsk.name == name){
            delete_task(taskManager, tsk);
            success ++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a task with such name. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully\n";
    }
}


void delete_by_ID(vector<task> taskManager){
    int ID;
    int success = 0;


    cout << "Enter ID of a task, that you want to delete: \n";
    cin >> ID;


    for (task tsk: taskManager){
        if(tsk.taskID == ID){
            delete_task(taskManager, tsk);
            success++;
            break;
        }
    }
    if(success == 0){
        cout << "Program is feild to find a task with such ID. Check your spelling\n";
    } else{
        cout << "Operation is completed successfully\n";
    }
}

void update(task tsk){
    while(true){
        display(tsk);
        int input;
        cout << "\ntaskID --> 0\n" <<
        "name --> 1\n" <<
        "deadline --> 2\n" <<
        "status --> 3\n" <<
        "priority --> 4\n" <<
        "End of changes --> 5\n";
        cin >> input;

        int new_ID;
        string new_name;
        string new_deadline;
        string new_status;
        int new_priority;
        int end = 0;

        switch (input){
            case(0):
            cout << "Enter new taskID: ";
            cin >> new_ID;
            tsk.taskID = new_ID;
            break;
            case(1):
            cout << "Enter new name: ";
            cin >> new_name;
            tsk.name = new_name;
            break;
            case(2):
            cout << "Enter new deadline: ";
            cin >> new_deadline;
            tsk.deadline = new_deadline;
            break;
            case(3):
            cout << "Enter new status: ";
            cin >> new_status;
            tsk.status = new_status;
            break;
            case(4):
            cout << "Enter new priority: ";
            cin >> new_priority;
            tsk.priority = new_priority;
            break;
            case(5):
            cout << "Ending of changes...\n";
            end ++;
            break;
        }
        if (end==1){
            break;
        }
    }
}

void update_task(vector<task> taskManager){
    int input;
    cout << "Search by name (0) or ID (1):\n";
    cin >> input;
    string name;
    int ID;
    int success = 0;
    switch(input){
        case(0):
        cout << "Enter name of a task, that you want to update: \n";
        cin >> name;


        for (task tsk: taskManager){
            if(tsk.name == name){
                success ++;
                cout << "task was found successfully. What would you like to change\n";
                update(tsk);
                break;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a task with such name. Check your spelling\n";
        } 
        break;
        case(1):
        cout << "Enter a task ID, that you want to update: \n";
        cin >> ID;


        for (task tsk: taskManager){
            if(tsk.taskID == ID){
                success ++;
                cout << "task was found successfully. What would you like to change\n";
                update(tsk);
                break;
            }
        }
        if(success == 0){
            cout << "Program is feild to find a task with such ID. Check your spelling\n";
        } 

        }

}
