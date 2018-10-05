#include "sortPatient.h"

bool sortPatient::operator() (const Patient& p1, const Patient& p2) const
{
   if(p1.getTLevel() > p2.getTLevel())
   {
      return true;
   }
   else if(p1.getTLevel() < p2.getTLevel())
   {
      return false;
   }
   else
   {
      return true;
   }
}

bool sortPatient::operator() (Patient& p1, Patient& p2) const
{
   if(p1.getTLevel() > p2.getTLevel())
   {
      return true;
   }
   else if(p1.getTLevel() < p2.getTLevel())
   {
      return false;
   }
   else
   {
      return true;
   }
}

