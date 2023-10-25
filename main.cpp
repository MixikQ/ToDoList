#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
using namespace std;

int help() //show list of possible actions
{
    cout << "\nHow to use to-do-list:" << endl;
    cout << "Firstly open Command Prompt and cd to the directory with main.exe" << endl;
    cout << "Then you can use commands below: \n" << endl;
    cout << "$ main.exe help \t\t\t#Show short descriprion of all existing commands" << endl;
    cout << "$ main.exe add \"task\" \t\t\t#Add a new task" << endl;
    cout << "$ main.exe del \"number of task\" \t#Delete a task" << endl;
    cout << "$ main.exe done \"number of task\" \t#Mark task as completed" << endl;
    cout << "$ main.exe list \t\t\t#Show list of uncompleted tasks" << endl;
    cout << "$ main.exe rep \t\t\t\t#Show amount of completed and uncompleted tasks" << endl;
}

int add(string arg) //add a task
{
    int pending, done;
    string temp;
    vector <string> v;
    
    ifstream read;
    read.open("todo.txt");

    while (getline(read, temp))
    {
        v.push_back(temp);
    }
    read.close();

    bool check = false;

    for (int i = 0; i < v.size(); i++)
    {
        if (arg == v[i]) 
        {
            check = true; //task is already added earlier, needed to refresh it
        }
    }
    
    if (check == false) //if task is new
    {
        fstream write;
        write.open("todo.txt", ios::app);
        write << arg << endl;
        cout << "Added task: " << "\"" << arg << "\"" << endl;
        write.close();
    }
    else
    {
        ofstream write;
        write.open("todo.txt");
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != arg)
            {
                write << v[i] << endl;
            }
        }

        write << arg << endl;
        cout << "Added task: " << "\"" << arg << "\"" << endl;
        write.close();
    }

    return 0;
}

int del(int key_number) //delete a task
{
    string arg;
    vector <string> v;

    ifstream read;
    read.open("todo.txt");
    while (getline(read, arg))
    {
        v.push_back(arg);
    }
    read.close();

    if (key_number > v.size() || key_number < 1) //entered number of task does not exist 
    {
        cout << "No task to delete. Nothing deleted" << endl;
    }
    else //delete task with entered number
    {
        ofstream write;
        write.open("todo.txt");
        for (int i = 0; i < v.size(); i++)
        {
            if (i != key_number - 1)
            {
                write << v[i] << endl;
            }
        }
        cout << "Deleted task #" << key_number << endl;
    }
    
    return 0;
}

int rep() //show amount of completed tasks
{
    int pending = 0, done = 0;
    string arg;
    int year, month, date;

    ifstream read;
    read.open("todo.txt"); //count pending tasks
    if (read)
    {
        while (getline(read, arg))
        {
            pending++;
        }
    }
    read.close();

    read.open("done.txt"); //count completed tasks
    if (read)
    {
        while (getline(read, arg))
        {
            done++;
        }
    }
    read.close();

    time_t ttime = time(0);
    tm* local_time = localtime(&ttime);
    year = local_time -> tm_year + 1900;
    month = local_time -> tm_mon + 1;
    date = local_time -> tm_mday;

    cout << year << "/" << month << "/" << date << "\n" << "Pending tasks: " << pending << "\nCompleted tasks: " << done << endl;

    return 0;
}

int done(int key_number) //mark task as completed
{
    int year, month, date, z;
    vector <string> v;
    string arg, x;

    time_t ttime = time(0);
    tm* local_time = localtime(&ttime);
    year = local_time -> tm_year + 1900;
    month = local_time -> tm_mon + 1;
    date = local_time -> tm_mday;
    //get year, month and date data

    ifstream read;
    read.open("todo.txt");

    while (getline(read, arg))
    {
        v.push_back(arg);
    }
    read.close();

    if (key_number > v.size()) //if number of task does not exist
    {
        cout << "Entered not existing number. Nothing happend" << endl;
    }
    else //if entered existing number of task
    {
        ofstream write1, write2;
        write1.open("todo.txt");
        write2.open("done.txt", ios::app);
        
        for (int i = 0; i < v.size(); i++)
        {
            if (i == key_number - 1)
            {
                x = v[i];
                cout << "Task #" << key_number << " marked as completed" << endl;
            }
            else
            {
                write1 << v[i] << endl;
            }
        }
        write1.close();

        write2 << "x " << year << "/" << month << "/" << date << " " << x << endl; 
        write2.close();
    }
    
    return 0;
}

int lst() //show list of uncompleted tasks
{
    string arg;
    vector <string> v;

    ifstream read;
    read.open("todo.txt");
    while(getline(read, arg))
    {
        v.push_back(arg);
    }
    read.close();

    if (v.size() == 0)
    {
        cout << "There are no list of tasks" << endl;
    }
    else
    {
        for (int i = v.size() -1; i >= 0 ; i--)
        {
            arg = v.back();
            v.pop_back();
            cout << "[" << i+1 << "] " << arg << endl;
        }
    }
    
    return 0;
}

int main(int argc, char* argv[])
{
    string arg, arg2;
    int key_number = 0;

    if (argc > 1)
    {
        arg = argv[1];
    }

    if (argc == 1 || arg == "help")
    {
        help(); //call help function
    }
    else if (arg == "add")
    {
        if (argc == 2) //if called function add without task 
        {
            cout << "Missing task. Nothing added" << endl;
        }
        else //if called function add with given task
        {
            arg2 = argv[2];
            add(arg2); //call add function
        }
    }
    else if (arg == "del" || arg == "delete" || arg == "remove")
    {
        if (argc == 2) //if called function without number of task to delete
        {
            cout << "No task to delete. Nothing deleted" << endl;
        }
        else //delete task
        {
            arg2 = argv[2];
            key_number = stoi(arg2);
            del(key_number); //call delete function
        }
    }
    else if (arg == "rep" || arg == "report" || arg == "status")
    {
        rep(); //call report function
    }
    else if (arg == "done" || arg == "complete")
    {
        if (argc == 2) //if called function without number of completed task
        {
            cout << "No task to mark as completed" << endl;
        }
        else //delete completed task and add it to report list
        {
            arg2 = argv[2];
            key_number = stoi(arg2);

            if (key_number > 0)
            {
            done(key_number); //call done function
            }
            else
            {
                cout << "Wrong number. Nothing marked as completed" << endl;
            }
        }
    }
    else if (arg == "lst" || arg == "list")
    {
        lst(); //call function lst() 
    }

    return 0;
}