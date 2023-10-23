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
    int k = 0;

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
    
    }
    else if (arg == "rep")
    {
        rep(); //call report function
    }
    else if (arg == "done")
    {
    
    }
    else if (arg == "list")
    {
        list(); //call list function
    }
    
    
    
}