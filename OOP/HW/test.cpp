#include <iostream>
#include <string>
#include <vector>


using namespace std;

class person
{
    private:

    int age;
    string name;

    public:

    person(int age_, string name_)
    {
        age = age_;
        name = name_;
    }
    void changeName(string newname)
    {
        name = newname;
    }
    void changeAge(int newage)
    {
        age = newage;
    }
    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
};

class student : public person
{

};

class teacher : public person
{
    int class_taught;
};

class school
{
    student* students;
    teacher* teachers;

    
};

int main()
{
    string name;
    int age;
    cin >> name;
    cin >> age;
    
    person Pau(age, name);

    cout << Pau.getAge() << endl;
    cout << Pau.getName() << endl;

}