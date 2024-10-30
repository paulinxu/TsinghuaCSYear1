#include "Parser.h"
#include <cstring>
#include <string>
#include <vector>
#include <iostream>

bool isInt(std::string a)
{
    for (int i = 0 ; i < a.length() ; i ++)
    {
        if (a[i] < '0' || a[i] > '9') {return false;}
    }
    return true;
}

void printHelp()
{
    std::cout << "usage: ./main [--help] [--first FIRST] [--second SECOND] [--third THIRD]" << std::endl;
    std::cout << std::endl;
    std::cout << "optional arguments:" << std::endl;
    std::cout << "--help   show this help message and exit" << std::endl;
    std::cout << "--first FIRST   First number" << std::endl;
    std::cout << "--second SECOND   Next number" << std::endl;
    std::cout << "--third THIRD   Third number" << std::endl;
}

void printErrorInvalid(Argument argument, std::string text)
{
    std::cout << "usage: ./main [--help] [--first FIRST] [--second SECOND] [--third THIRD]" << std::endl;
    std::cout << "./main: error: argument " << argument.command << ": invalid int value: '" << text << "'" << std::endl;
}

void printErrorExpected(Argument argument)
{
    std::cout << "usage: ./main [--help] [--first FIRST] [--second SECOND] [--third THIRD]" << std::endl;
    std::cout << "./main: error: argument " << argument.command << ": expected an argument" << std::endl;
}

void printErrorUnrecognized(std::string text)
{
    std::cout << "usage: ./main [--help] [--first FIRST] [--second SECOND] [--third THIRD]" << std::endl;
    std::cout << "./main: error: unrecognized arguments: "<< text << std::endl;
}

void Parser::init(char* x) 
{
    // split input by spaces
    
    char* token = strtok(x, " ");
    std::vector<std::string> tokens(0);

    while (token != nullptr) {
        tokens.push_back(token);
        token = strtok(nullptr, " ");
    }

    for (std::string x : tokens)
    {
        //std::cout << "TokenValue:'" << x << "'" << std::endl;
        if (strcmp(x.c_str(), "--help") == 0)
        {
            printHelp();
            exit(0);
        }
    }

    // assign values

    for (int i = 0 ; i < tokens.size() ; i ++)
    {
        bool validCommand = false;
        
        for (int j = 0 ; j < 3 ; j ++)
        {
            
            //std::cout << tokens[i] << " = " << arguments[j].command << std::endl;

            if (strcmp(tokens[i].c_str(), arguments[j].command.c_str()) == 0)
            {

                if (i+1 >= tokens.size())
                {
                    printErrorExpected(arguments[j]);
                    exit(0);
                }

                if (!isInt(tokens[i+1]))
                {
                    printErrorInvalid(arguments[j], tokens[i+1]);
                    exit(0);
                }

                arguments[j].value = stoi(tokens[i+1]);
                //std::cout << arguments[j].command << " = " << arguments[j].value << std::endl;
                i++;
                validCommand = true;
                break;
            }
        }

        if (tokens[i][0] == '-' && tokens[i][1] == '-')
        {
            if (!validCommand)
            {
                printErrorUnrecognized(tokens[i]);
                exit(0);
            }
        }
    }

}

int counter = 0;

void Parser::add_argument(std::string command, int default_value, std::string help_message)
{
    Argument arg;
    arg.command = command;
    arg.default_value = default_value;
    arg.help_message = help_message;
    arguments[counter] = arg;
    counter++;
    //std::cout << "add_argument(): " << arg.command << std::endl;
}

int Parser::get_argument(std::string arg)
{
    int val;
    arg = "--" + arg;
    for (int i = 0 ; i < 3 ; i ++)
    {
        if (strcmp(arg.c_str(), arguments[i].command.c_str()) == 0)
        {
            val = arguments[i].value;
        }

        if (val == -1)
        {
            val = arguments[i].default_value;
        }
    }

    //std::cout << "get_argument(): " << val << std::endl;
    return val;
}