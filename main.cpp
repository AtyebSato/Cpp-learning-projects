#include <iostream>
#include <vector>
#include <fstream> 
using namespace std;

int main(){
    int choice;

    struct Task{
        string name;
        bool completed = false;
    };

        vector<Task> tasks;


    bool open = true;
    while (open){
        cout << "\n1.Add a task\n2.View tasks\n3.Edit tasks\n4.Load tasks text file\n5.Save current tasks to file\n6.Exit\n";
        cin >> choice;

        while (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Try again: ";
            cin >> choice;
        }

        switch(choice){
            case 1: {
                Task task;
                cout << "Name your task:\n";
                
                cin.ignore();
                getline(cin, task.name);

                tasks.push_back(task);
                break;
            }

            case 2: 
                cout << "===============TASKS===============\n";
                for(int i = 0; i < tasks.size(); i++){
                    cout << i + 1 << "/" << tasks.at(i).name;
                    if (tasks.at(i).completed){
                        cout <<  "      COMPLETED\n";
                    }
                    else{
                        cout <<  "      UNCOMPLETED\n";
                    }
                }
                cout << "===================================\n";
                break;

            case 3:{
                cout << "Select a task to edit\n";
                int selectedtask;
                cin >> selectedtask;
                if (selectedtask < 1 || selectedtask > tasks.size()){
                    cout << "Task not found";
                    break;
                }
                cout << "--->" << tasks.at(selectedtask - 1).name << endl;

                cout << "1.Check/Uncheck task\n2.Rename task\n3.Delete task\n";
                int editchoice;
                cin >> editchoice;
                 
                switch (editchoice)
                {
                case 1:
                    tasks.at(selectedtask - 1).completed = !tasks.at(selectedtask - 1).completed;

                    break;

                case 2:{
                    cout << "Enter new name: ";
                    string newname;
                    cin.ignore();
                    getline(cin, newname);
                    tasks.at(selectedtask - 1).name = newname;
                    break;
                }

                case 3:
                    tasks.erase(tasks.begin() + selectedtask - 1);
                    break;
                }
            break;
            }

            case 4:{
                tasks.clear();
                cout << "Enter file name: ";
                string filename;
                cin >> filename;
                ifstream ifile;

                ifile.open(filename);

                if(!ifile.is_open()){
                    cout << "File not found";
                    break;
                }
                string temptaskname;
                while(getline(ifile, temptaskname)){
                    Task temptask;
                    temptask.name = temptaskname;
                    tasks.push_back(temptask);
                } 
            break;
            }

            case 5:{
                cout << "Enter saved file name: ";
                string filename;
                cin >> filename;
                ofstream ofile;
                
                ofile.open(filename);

                for(int i = 0; i < tasks.size();i++){
                    ofile << tasks.at(i).name << endl;
                }
            break;
            }

            case 6:
                open = false;
            break;
        }
    }
}