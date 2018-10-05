/*
 * File Name:    sortPatient.h
 *
 * Author:        Your Name
 * Creation Date: Tuesday, September 25 2018, 16:05 
 * Last Modified: Wednesday, September 26 2018, 22:27
 * 
 * File Description:
 *
 */
#ifndef SORT_PATIENT_H
#define SORT_PATIENT_H

#include "patient.h"

class sortPatient
{
public:
    bool operator( ) ( const Patient& p1, const Patient& p2 ) const;
    bool operator( ) ( Patient& p1, Patient & p2 ) const;
private:
};
#endif
