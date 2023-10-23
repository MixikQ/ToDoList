#include <iostream>
using namespace std;

int help() //show list of possible actions
{

}

int add() //add a task
{

}

int del() //delete a task
{

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