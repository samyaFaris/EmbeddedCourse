#include <iostream>
using namespace std;
#include <string.h>
#include "article.h"

article::article(const char *pupDate, const char *articleName, const char *magazineName)
{
    this->pupDate = new char[strlen(pupDate) + 1];
    strcpy(this->pupDate, pupDate);
    this->articleName = new char[strlen(articleName) + 1];
    strcpy(this->articleName, articleName);
    this->magazineName = new char[strlen(magazineName) + 1];
    strcpy(this->magazineName, magazineName);
}
article::article(const article &a)
{
    *this = a;
}
article::article(article &&a)
{
    this->pupDate =a.pupDate;
    a.pupDate = nullptr;
    this->articleName = a.articleName;
    a.articleName = nullptr;
    this->magazineName = a.magazineName;
    a.magazineName = nullptr;
}
article::~article()
{
    delete[] pupDate;
    delete[] articleName;
    delete[] magazineName;
}
char *article::get_pupDate()
{
    return this->pupDate;
}
char *article::get_articleName()
{
    return this->articleName;
}
char *article::get_magazineName()
{
    return this->magazineName;
}
bool article::set_pupDate(char *pupDate)
{
    delete[] this->pupDate;
    this->pupDate = new char[strlen(pupDate) + 1];
    strcpy(this->pupDate, pupDate);
    return true;
}
bool article::set_magazineName(char *magazineName)
{
    delete[] this->magazineName;
    this->magazineName = new char[strlen(magazineName) + 1];
    strcpy(this->magazineName, magazineName);
    return true;
}
bool article::set_articleName(char *articleName)
{
    delete[] this->articleName;
    this->articleName = new char[strlen(articleName) + 1];
    strcpy(this->articleName, articleName);
    return true;
}
const article &article::operator=(const article &a)
{
    if (this != &a)
    {
        if (this->pupDate != nullptr)
        {
            delete[] this->pupDate;
        }
        this->pupDate = new char[strlen(pupDate) + 1];
        strcpy(this->pupDate, pupDate);

        if (this->articleName != nullptr)
        {
            delete[] this->articleName;
        }
        this->articleName = new char[strlen(articleName) + 1];
        strcpy(this->articleName, articleName);
        if (this->magazineName != nullptr)
        {
            delete[] this->magazineName;
        }
        this->magazineName = new char[strlen(magazineName) + 1];
        strcpy(this->magazineName, magazineName);
    }
    return *this;
}
ostream &operator<<(ostream &os, const article &a)
{
    os << "------ Article Details ------\n";
    os << "Date : "<< a.pupDate << "\n";
    os << "Name : " << a.articleName << "\n";
    os << "Magazine Name : " << a.magazineName << "\n";
    return os;
}