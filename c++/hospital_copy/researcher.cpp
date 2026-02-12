#include <iostream>
using namespace std;
#include <string.h>
#include "researcher.h"

researcher::researcher(const string &rName, const string &rId, int idCounter) : employee(rId, rName, idCounter)

{
}

list<article> researcher::get_articles() const
{
    return this->articles;
}

ostream &operator<<(ostream &os, const researcher &r)
{
    os << "---------- RESEARCHER DETAILS  ----------";
    os << (employee &)r;
    list<article>::const_iterator itr = r.articles.begin();
    list<article>::const_iterator itrEnd = r.articles.end();
   if (itr == itrEnd)
    {
        cout << "Collection is empty!\n";
        return os;
    }
        for (; itr != itrEnd; ++itr)
    {
         os << "article "  << *itr;
    }
    return os;
}

bool researcher::add_article_to_researcher(article *articlePtr)
{
    articles.push_back(*articlePtr);
    return true;
}
