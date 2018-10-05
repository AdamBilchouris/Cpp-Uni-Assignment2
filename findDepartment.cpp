#include "findDepartment.h"

bool findDepartment::operator() (MedDept & md1, MedDept & md2) const
{
   if(md1.getCapacity() < md2.getCapacity())
   {
      return false;
   }
   else if(md1.getCapacity() > md2.getCapacity())
   {
      return true;
   }
   else
   {
      if(md1.getDepartmentName() < md2.getDepartmentName())
      {
         return true;
      }
      else
      {
         return false;
      }
   }
}

bool findDepartment::operator() (const MedDept & md1, const MedDept & md2) const
{
   if(md1.getCapacity() < md2.getCapacity())
   {
      return false;
   }
   else if(md1.getCapacity() > md2.getCapacity())
   {
      return true;
   }
   else
   {
      if(md1.getDepartmentName() < md2.getDepartmentName())
      {
         return true;
      }
      else
      {
         return false;
      }
   }
}

