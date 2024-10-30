#include "library.h"
#include <string>

void Library::add_book(Book book)
{
    Books.push_back(book);
    std::cout << "Added:" << book.get_name() << std:: endl;
}

void Library::delete_book(int book_ID)
{
    for (auto x = Books.begin(); x < Books.end(); x++)
    {
        if (x->get_ID() == book_ID)
        {
            std::cout << "Deleted:" << x->get_name() << std::endl;
            Books.erase(x);
            return;
        }
    }

    std::cout << "Delete Failed" << std::endl;
}

void Library::find_book(int book_ID)
{
    bool found = false;
    for (Book& x : Books)
    {
        if (x.get_ID() == book_ID)
        {
            x.print_message();
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Find Failed" << std:: endl;
    }
}

void Library::borrow_book(int book_ID, string borrower)
{
    bool found = false;
    for (Book& x : Books)
    {
        if (x.get_ID() == book_ID)
        {
            if (x.get_state() == false)
            {
                std::cout << "Borrow Failed" << std:: endl;
                return;
            }

            x.change_state();
            x.change_state(borrower);
            std::cout << "Borrowed:" << x.get_name() << std:: endl;

            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Borrow Failed" << std:: endl;
    }
}

void Library::return_book(int book_ID)
{
    bool found = false;
    for (Book& x : Books)
    {
        if (x.get_ID() == book_ID)
        {
            if (x.get_state() == true)
            {
                std::cout << "Return Failed" << std:: endl;
                return;
            }

            x.change_state();
            std::cout << "Returned:" << x.get_name() << std:: endl;

            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Return Failed" << std:: endl;
    }
}