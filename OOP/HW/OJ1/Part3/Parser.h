#pragma once
#include <string>

class Argument
{
    public:
    std::string command;
    int default_value;
    std::string help_message;
    int value = -1;
};

class Parser
{
    private:

    char input[100];
    Argument arguments[3];
    
    public:

    void init(char* x);

    void add_argument(std::string command, int default_value, std::string help_message);

    int get_argument(std::string arg);


};