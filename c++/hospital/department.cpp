#include <iostream>
using namespace std;
#include "department.h"
#include <string.h>

department::department(const char *dep_name) : Physical_size(2), logical_size(0)
{
   this->dep_name = new char[strlen(dep_name) + 1];
   strcpy(this->dep_name, dep_name);
   doctor_arr = new doctor *[Physical_size];
   for (int i = 0; i < Physical_size; i++)
   {
      doctor_arr[i] = nullptr;
   }
}
bool department::set_dep_name(char *dep_name)
{
   delete[] this->dep_name;
   this->dep_name = new char[strlen(dep_name) + 1];
   strcpy(this->dep_name, dep_name);
   return true;
}
bool department::set_Physical_size(int size)
{
   this->Physical_size = size;
   return true;
}
bool department::set_logical_size(int size)
{
   this->logical_size = size;
   return true;
}
char *department::get_dep_name()
{
   return dep_name;
}
int department::get_Physical_size()
{
   return Physical_size;
}
int department::get_logical_size()
{
   return logical_size;
}
doctor **department::get_doctor_arr()
{
   return doctor_arr;
}
department::~department()
{
   delete[] doctor_arr;
   delete[] dep_name;
}
bool department::add_doctor_to_dep(doctor *doctorPtr)
{
   if (logical_size < Physical_size)
   {

      this->doctor_arr[logical_size] = doctorPtr;
      (*doctorPtr).set_departmentPtr(this);
      set_logical_size(logical_size + 1);
   }
   else if (logical_size == Physical_size)
   {
      Physical_size *= 2;
      doctor **temp = new doctor *[Physical_size];
      for (int i = 0; i < logical_size; i++)
      {
         temp[i] = doctor_arr[i];
      }
      delete[] doctor_arr;
      this->doctor_arr = temp;
      doctor_arr[logical_size] = doctorPtr;
      (*doctorPtr).set_departmentPtr(this);
      set_logical_size(logical_size + 1);
   }
   return true;
}

ostream &operator<<(ostream &os, const department &d)
{
   os << "Department Details \n";
   os << "name: " << d.dep_name << "\n";
   os << "Logical Size: " << d.logical_size << "\n";
   os << "Physical Size: " << d.Physical_size << "\n";
   for (int i = 0; i < d.logical_size; i++)
   {
      if (d.doctor_arr[i] != nullptr)
      {
         cout << (*d.doctor_arr[i]);
         // os << "Department Name: " << d.dep_name << "\n";
      }
   }
   return os;
}
