#ifndef __RESEARCHER_H
#define __RESEARCHER_H
#include <iostream>
using namespace std;
#include "employee.h"
#include "article.h"

class researcher : virtual public employee
{
protected:
    article **articles;
    int article_logical_size;
    int article_physical_size;

public:
    researcher(const employee &e);
    researcher(const char *rName, const char *rId, int idCounter);
    researcher(employee &&e);
    int get_article_logical_size();
    int get_article_physical_size();
    article **get_articles();
    bool set_article_logical_size(int article_logical_size);
    bool set_article_phisycal_size(int article_physical_size);
    bool add_article_to_researcher(article *articlePtr);
    friend ostream &operator<<(ostream &os, const researcher &r);
    ~researcher();
};
#endif