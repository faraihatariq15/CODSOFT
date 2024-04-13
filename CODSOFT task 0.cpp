#include <iostream>
using namespace std;

void print_tasks(string tasks[], int task_count) {
    cout << "Tasks to do: " << endl;
    cout << "----------------------------" << endl;
    for (int i = 0; i < task_count; i++) {
        cout << "Tasks: " << i << " : " << tasks[i] << endl;
    }
    cout << "----------------------------" << endl;
}

int main() {
    string tasks[10] = {""};
    int task_count = 0;
    int option = -1;
    while (option != 0) {
        cout << "---------TO DO LIST---------" << endl;
        cout << "1- To Add new tasks" << endl;
        cout << "2- To View tasks" << endl;
        cout << "3- To Remove tasks" << endl;
        cout << "0- Terminate program" << endl;
        cin >> option;
        switch (option) {
            case 1: {
                if (task_count > 9) {
                    cout << "Task List is full" << endl;
                } else {
                    cout << "Enter a new task: " << endl;
                    cin.ignore();
                    getline(cin, tasks[task_count]);
                    task_count++;
                }
                break;
            }
            case 2:
                system("cls");
                print_tasks(tasks, task_count);
                break;
            case 3: {
                system("cls");
                print_tasks(tasks, task_count);
                int del_task = 0;
                cout << "Enter a task# to delete: " << endl;
                cin >> del_task;
                if (del_task < 0 || del_task >= task_count) {
                    cout << "Oops! an invalid number" << endl;
                } else {
                    for (int i = del_task; i < task_count - 1; i++) {
                        tasks[i] = tasks[i + 1];
                    }
                    task_count--;
                }
                break;
            }
            case 0:
                cout << "Terminating the Program" << endl;
                break;
            default:
                cout << "Invalid number" << endl;
        }
    }
    return 0;
}

