#include "book.h"
#include <string>

Book::Book(int ID, string name, string author, string publishing_house)
{
    this->ID = ID;
    this->name = name;
    this->author = author;
    this->publishing_house = publishing_house;
    this->state.first = true;
}
int Book::get_ID()
{
    return ID;
}
string Book::get_name()
{
    return name;
}
string Book::get_author()
{
    return author;
}
string Book::get_publishing_house()
{
    return publishing_house;
}
bool Book::get_state()
{
    return state.first;
}
void Book::change_state()
{
    this->state.first = !state.first;
    //std::cout << "STATE:" << state.first << endl; // DELETE LINE
}
void Book::change_state(string name)
{
    state.second = name;
}
void Book::print_message()
{
    std::cout << "ID:" << ID << std::endl;
    std::cout << "name:" << name << std::endl;
    std::cout << "author:" << author << std::endl;
    std::cout << "publishing_house:" << publishing_house << std::endl;
    if (state.first == true)
    {
        std::cout << "state:loanable" << std::endl;
    }
    else 
    {
        std::cout << "borrower:" << state.second << std::endl;
        std::cout << "state:borrowed" << std::endl;
    }
}