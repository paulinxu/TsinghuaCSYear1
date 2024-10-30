#include <iostream>
#include "Instruction.h"
#include <vector>
#pragma once

using namespace std;

class Node
{
    public:
    vector<Instruction*>* instructions;
    int pos;

    Node(int i, vector<Instruction*>* _instructions) : pos(i), instructions(_instructions){}

    Node& operator+=(int x)
    {  
        instructions->push_back(new AddInt(pos, x));
        return *this;
    }

    Node& operator+=(Node x)
    {  
        instructions->push_back(new AddNode(pos, x.pos));
        return *this;
    }

    Node& operator=(Node x)
    {  
        instructions->push_back(new EqualsNode(pos, x.pos));
        return *this;
    }
};

class ENDL
{
    public:
    vector<Instruction*>* instructions;
    ENDL(vector<Instruction*>* _instructions) : instructions(_instructions){}
};

class MagicArray
{
    public:
    vector<Node> arr;
    vector<Instruction*>* instructions;
    int length;

    MagicArray(int n) : length(n)
    {
        instructions = new vector<Instruction*>;
        
        for (int i = 0; i < n ; i++)
        {
            arr.push_back(Node(i, instructions));
        }
    };

    Node& operator[](int i)
    {
        return arr[i];
    }

    template<typename T>
    void apply(std::vector<T> &vec)
    {
        for (auto& instruction : *instructions)
        {
            instruction -> apply(vec);
        }
    }

    vector<Instruction*>& getInstructions()
    {
        return *instructions;
    }

    ENDL endl()
    {
        return ENDL(instructions);
    }
};

ostream& operator<<(ostream& out, const Node& node)
{
    node.instructions -> push_back(new Print(node.pos));
    return out;
}

ostream& operator<<(ostream& out, const ENDL& x)
{
    x.instructions -> push_back(new PrintEndl());
    return out;
}