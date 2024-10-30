#pragma once
#include <vector>

using namespace std;
class Instruction
{
public:
    int val=0;
    int pos;
    virtual void apply(std::vector<int> &vec) = 0;
    virtual void apply(std::vector<double> &vec) = 0;
    virtual void output() = 0;
};

class AddInt : public Instruction
{
public:
    int pos = 0;
    int val = 0;
    AddInt(int _pos, int _val) : pos(_pos) , val(_val){};

    void apply(std::vector<int> &vec)
    {
        vec[pos] += val;
    }
    void apply(std::vector<double> &vec)
    {
        vec[pos] += val;
    }
    void output()
    {
        cout << "arr[" << pos << "] += " << val << endl;
    }
};

class AddNode : public Instruction
{
public:
    int pos = 0;
    int pos2 = 0;

    AddNode(int _pos, int _pos2) : pos(_pos) , pos2(_pos2){};

    void apply(std::vector<int> &vec)
    {
        vec[pos] += vec[pos2];
    }
    void apply(std::vector<double> &vec)
    {
        vec[pos] += vec[pos2];
    }
    void output()
    {
        cout << "arr[" << pos << "] +=arr[" << pos2 << "]" << endl;
    }
};

class EqualsNode : public Instruction
{
public:
    int pos = 0;
    int pos2 = 0;

    EqualsNode(int _pos, int _pos2) : pos(_pos) , pos2(_pos2){};

    void apply(std::vector<int> &vec)
    {
        vec[pos] = vec[pos2];
    }
    void apply(std::vector<double> &vec)
    {
        vec[pos] = vec[pos2];
    }
    void output()
    {
        cout << "arr[" << pos << "] = arr[" << pos2 << "]" << endl;
    }
};

class Print : public Instruction
{
public:
    int pos = 0;
    Print(int _pos) : pos(_pos){};

    void apply(std::vector<int> &vec)
    {
        cout << vec[pos];
    }
    void apply(std::vector<double> &vec)
    {
        cout << vec[pos];
    }
    void output()
    {
        cout << "cout << arr[" << pos <<"]" << endl;
    }
};

class PrintEndl : public Instruction
{
public:
    PrintEndl() {}

    void apply(std::vector<int> &vec)
    {
        cout << endl;
    }
    void apply(std::vector<double> &vec)
    {
        cout << endl;
    }
    void output()
    {
        cout << "cout << endl" << endl;
    }
};