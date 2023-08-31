/**
 * File : 01229749125_Task1_3.cpp
 * Author : Youssef Ahmed Kamle Ali
 * Description : this is a Minions Task Manager
 * Date : [13/8/2023]
 * 
 * 
 * 
 * sorry there is some issue i can't understand, it is when i entered a random option it goes into infinite loop  even thought i wrote an else condition
*/


/* Header files*/
#include <iostream> // Standard Input / Output Streams Library
#include <string> // strings functions
using namespace std;


/* Main Function */
int main()
{
    int option, count=0, task_removed, task_completed; // declared some variables
    string *Tasks = new string[50]; // array of strings using dynamic memory allocation
    bool completed[50] = {0}; // array of booleans values to check if the task is completed or not

    /* program description */
    cout << "Minions Task Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Remove Task\n";
    cout << "4. Show the complete and incomplete Tasks \n";
    cout << "5. Mark tasks as completed\n";
    cout << "6. Show the data in a table format\n";
    cout << "7. Exit\n";
    
    /* Code */
    while(true)
    {
        cout << "\nSelect an option: ";
        cin >> option;

        if (option == 1){
            cin.ignore();  // this line is added to clear the newline character
            cout << "\nEnter task description: "; // count -> the number of tasks
            getline(cin, Tasks[count], '\n');  // read the task from the user
            count++;  // increment the number of tasks
            cout << "Task added successfully!\n";
        }

        else if (option == 2){
            cout << "Current Tasks:\n";  
            for (int i = 0; i < count; i++){
                cout << "\nTask ID: "  << i + 1 << endl;
                cout << "Description: " << Tasks[i] << endl;
            }
        }

        else if (option == 3){
            cout << "Enter task ID to remove: ";
            cin >> task_removed;
            for (int i = task_removed-1; i < count; i++){ // remove element from the array
                Tasks[i] = Tasks[i+1];
            }
            count--; // decrement the number of tasks
            cout << "Task removed successfully!\n" << endl;
        }

        else if (option == 4){  
            cout << "Here's all the tasks: 0 means not completed and 1 means completed\n";
            for (int i = 0; i < count; i++){  
                cout << i+1 << ". " << Tasks[i] << " -> " << completed[i] << endl; 
                // if there is a zero after '->' that means that the task is not completed
                // if there is a one after '->' that means that the task is completed
            }
        }
        else if (option == 5){
            cout << "Mark tasks as completed\n";
            while(1){
                cout << "if you want to quit enter 0 next\nEnter ID: ";
                cin >> task_completed;
                cin.ignore();

                if (task_completed == 0) break; // condition to end the loop
                
                if (task_completed >= 1 && task_completed <= count){ // check if the number entered in the range of the existing tasks
                    if (completed[task_completed - 1] == false) // if the task not completed
                        completed[task_completed - 1] = true; // make it completed
                    else // that means the user enter a task is already completed
                        cout << "this task is already completed\n";
                }
                else 
                    cout << "please enter a number from 1 to " << count << endl;
            }
        }

        else if (option == 6) { // May be it doesn't work if the task's lenght is too long
            cout << "Current Tasks:\n";
            cout << "+----------------------------------+\n";
            cout << "| Task ID |      Description       |\n";
            cout << "+----------------------------------+\n";
    
            for (int i = 0; i < count; i++) {
                cout << "|   " << i + 1 << "     | " << Tasks[i];
                cout << string(28 - Tasks[i].length(), ' ') << "|\n";
            }
            cout << "+----------------------------------+\n";
        }

        else if (option == 7){
            cout << "Exiting Minions Task Manager. Have a great day!\n";
            break; // break the loop and end the program
        }

        else  
            cout << "Please enter an option from 1 to 4\n";
    }

    delete[] Tasks;

    return (0);
}