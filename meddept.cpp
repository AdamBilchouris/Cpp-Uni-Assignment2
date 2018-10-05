#include "meddept.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

#include <string>
using std::string;
#include<fstream>
using std::ifstream;
using std::ofstream;

MedDept::MedDept(const string& name, int capacity, const string& tType) : name(name), capacity(capacity), treatmentType(tType) { }  //for user input

MedDept::MedDept(const MedDept& md)             //copy constructor
{
   name = md.getDepartmentName();
   capacity = md.getCapacity();
   treatmentType = md.getTreatmentType();
}

MedDept::MedDept(const string& name) : name(name) {}

//overloaded output operator
ostream& operator << (ostream& os, const MedDept& md)
{
   os << "Department: " << md.name << "\tFunction: " << md.treatmentType << endl;
   os << "Capacity: " << md.capacity << endl;

   return os;
}

//overloaded input operator
istream& operator >> (istream& is, MedDept& md)
{
   cout << "Enter the capacity of the department >> ";
   is >> md.capacity;
   is.clear();
   is.ignore(10000, '\n');

   cout << "Enter treatment type of the department >> ";
   getline(is, md.treatmentType);

   is.ignore(10000, '\n');

   return is;
}

//overloaded ofstream
ofstream& operator << (ofstream& fout, const MedDept& md)
{
   fout << md.name << endl;
   fout << md.capacity << endl;
   fout << md.treatmentType << endl;
   return fout;
}

//overloaded ifstream
ifstream& operator >> (ifstream& fin, MedDept& md)
{
   getline(fin, md.name); 
   fin >> md.capacity;
   fin.clear();
   fin.ignore(1000, '\n');
   getline(fin, md.treatmentType); 

   return fin;
}
