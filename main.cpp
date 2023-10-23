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
        help(); //calling help function
    }
    else if (arg == "add")
    {
        
    }
    else if (arg == "del")
    {
    
    }
    else if (arg == "rep")
    {
    
    }
    else if (arg == "done")
    {
    
    }
    else if (arg == "list")
    {
        
    }
    
    
    
}