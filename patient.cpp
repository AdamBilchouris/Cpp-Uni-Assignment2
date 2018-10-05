#include "patient.h"

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

Patient::Patient(const string& name, int UR, const string& bloodType, int tLevel) : name(name), UR(UR), bloodType(bloodType), tLevel(tLevel) {}

Patient::Patient(const Patient& p)
{
   name = p.getName();
   UR = p.getUR();
   bloodType = p.getBloodType();
   tLevel = p.getTLevel();
}

ostream& operator << (ostream& os, const Patient& p)
{
   os << "Patient:" << endl;
   os << "\t[ name: " << p.name << " UR: " << p.UR << endl;
   os << "\t  Blood Type: " << p.bloodType << " T Level: " << p.tLevel << endl;
   os << "\t]" << endl;
   return os;
}

istream& operator >> (istream& is, Patient& p)
{
   cout << "Enter patient name >> ";
   getline(is, p.name);

   cout << "Enter the UR number (int) >> ";
   is >> p.UR;

   is.ignore(10000, '\n');

   cout << "\nEnter blood type >> ";
   getline(is, p.bloodType);

   cout << "Enter t level >> ";
   is >> p.tLevel;

   is.ignore(10000, '\n');
   return is;
}

ofstream& operator << (ofstream& fout, const Patient& p)
{
   fout << p.name << endl;
   fout << p.UR << endl;
   fout << p.bloodType << endl;
   fout << p.tLevel << endl;

   return fout;
}

ifstream& operator >> (ifstream& fin, Patient& p)
{
   getline(fin, p.name);
   fin >> p.UR;
   fin.clear();
   fin.ignore(1000, '\n');
   getline(fin, p.bloodType);
   fin >> p.tLevel;
   fin.clear();
   fin.ignore(1000, '\n');
   
   return fin;
}
