#include <iostream>
using namespace std;
#include <string.h>
#include "researcher.h"

researcher::researcher(const employee &e) : employee(e), article_logical_size(0), article_physical_size(2)
{
    this->articles = new article *[article_physical_size];
    for (int i = 0; i < article_physical_size; i++)
    {
        articles[i] = nullptr;
    }
}
int researcher::get_article_logical_size()
{
    return article_logical_size;
}
int researcher::get_article_physical_size()
{
    return this->article_physical_size;
}
article **researcher::get_articles()
{
    return this->articles;
}

bool researcher::set_article_logical_size(int article_logical_size)
{
    this->article_logical_size = article_logical_size;
    return true;
}
bool researcher::set_article_phisycal_size(int article_physical_size)
{
    this->article_physical_size = article_physical_size;
    return true;
}
ostream &operator<<(ostream &os, const researcher &r)
{
    os << (employee&)r ;
    os << "---------- Articles List ----------";
    for(int i=0;i<r.article_logical_size;i++)
    {
        os <<"article " <<i+1 << r.articles[i]->get_articleName();
    }
    return os;
}

bool researcher::add_article_to_researcher(article *articlePtr)
{
       if (article_logical_size < article_physical_size)
   {

      this->articles[article_logical_size] = articlePtr;
      set_article_logical_size(article_logical_size+1);
   }
   else if (article_logical_size == article_physical_size)
   {
      article_physical_size *= 2;
      article **temp = new article *[article_physical_size];
      for (int i = 0; i < article_logical_size; i++)
      {
         temp[i] = articles[i];
      }
      delete[] articles;
      this->articles = temp;
      articles[article_logical_size] = articlePtr;
      set_article_logical_size(article_logical_size+1);
   }
   return true;
}
    

researcher::~researcher()
{
    for(int i=0; i<article_logical_size; i++)
    {
        delete articles[i];
    }
    delete []articles;
}
