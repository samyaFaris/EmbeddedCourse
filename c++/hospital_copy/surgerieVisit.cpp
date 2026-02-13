#include <iostream>
using namespace std;
#include <string.h>
#include "surgerieVisit.h"

surgerieVisit::surgerieVisit(const string &visit_date, patient *patientPtr, int numSurgerieRoom, bool isFasting) : visit(visit_date, patientPtr)
{

    this->numSurgerieRoom = numSurgerieRoom;
    this->isFasting = isFasting;
}
int surgerieVisit::get_numSurgerieRoom() const
{
    return this->numSurgerieRoom;
}
bool surgerieVisit::get_isFasting() const
{
    return this->isFasting;
}
bool surgerieVisit::set_numSurgerieRoom(const int numSurgerieRoom)
{
    this->numSurgerieRoom = numSurgerieRoom;
    return true;
}
bool surgerieVisit::set_numSurgerieRoom(const bool isFasting)
{
    this->isFasting = isFasting;
    return true;
}
ostream &operator<<(ostream &os, const surgerieVisit &s)
{
    os << "Surgerie Visit Details: \n";
    os << (visit &)s;
    os << "Num Surgerie Room : " << s.numSurgerieRoom << "\n";
    if (s.isFasting)
    {
        os << "Is Fasting : Yes";
    }
    else
    {
        os << "Is Fasting : No";
    }
    return os;
}