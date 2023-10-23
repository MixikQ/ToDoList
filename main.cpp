#include <bits/stdc++.h>
#include <sstream>
#include <iostream>
using namespace std;

int help() //show list of possible actions
{

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

int rep() //show completed tasks
{

}

int done() //mark task as completed
{

}

int list() //show list of uncompleted tasks
{

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
    else if (arg == "del")
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
    else if (arg == "rep")
    {
        rep(); //call report function
    }
    else if (arg == "done")
    {
        if (argc == 2) //if called function without number of completed task
        {
            cout << "No task to mark as completed" << endl;
        }
        else //delete completed task and add it to report list
        {
            arg2 = argv[2];
            key_number = stoi(arg2);

            if (k > 0)
            {
            done(key_number); //call done function
            }
            else
            {
                cout << "Wrong number. Nothing marked as completed" << endl;
            }
        }
    }
    else if (arg == "list")
    {
        list(); //call list function
    }
    
    
    
}