/*
 * File Name:    patient.h
 *
 * Author:        Your Name
 * Creation Date: Monday, September 24 2018, 15:16 
 * Last Modified: Wednesday, September 26 2018, 22:28
 * 
 * File Description:
 *
 */
#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>
using std::string;
#include <fstream>

class Patient
{
public:
    Patient( ) = default;
    Patient(const string& name, int UR, const string& bloodType, int tLevel);
    Patient(const Patient &p);

    friend std::ostream& operator << ( std::ostream & os, const Patient & p );
    friend std::ofstream& operator << ( std::ofstream & os, const Patient & p );
    friend std::istream& operator >> ( std::istream & is, Patient & p );
    friend std::ifstream& operator >> ( std::ifstream & os, Patient & p );

    const string& getName() const { return name; }
    int getUR() const { return UR; }
    const string& getBloodType() const { return bloodType; }
    int getTLevel() const { return tLevel; }
    
private:
    string name {"not known"};
    int UR {-1};
    string bloodType {"Blood type not set"};
    int tLevel {-1};
};
#endif
