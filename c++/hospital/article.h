#ifndef __ARTICLE_H
#define __ARTICLE_H
#include <iostream>
using namespace std;

class article
{
private:
    char *pupDate;
    char *articleName;
    char *magazineName;

public:
    article(const char *pupDate, const char *articleName, const char *magazineName);
    article(const article &a);
    article(article &&a);
    ~article();
    char* get_pupDate();
    char* get_articleName();
    char* get_magazineName();
    bool set_pupDate(char *pupDate);
    bool set_magazineName(char* magazineName);
    bool set_articleName(char* articleName);
    const article &operator=(const article &a);
    friend ostream &operator<<(ostream &os, const article &a);
};

#endif