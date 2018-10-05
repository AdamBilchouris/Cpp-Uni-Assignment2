/*
 * File Name:    findDepartment.h
 *
 * Author:        Your Name
 * Creation Date: Tuesday, September 25 2018, 14:26 
 * Last Modified: Wednesday, September 26 2018, 22:27
 * 
 * File Description:
 *
 */
#ifndef FIND_DEPARTMENT_H
#define FIND_DEPARTMENT_H

#include "meddept.h"

class findDepartment
{
public:
    bool operator( ) ( MedDept & md1, MedDept & md2 ) const;
    bool operator( ) ( const MedDept & md1, const MedDept & md2 ) const;
private:
};

#endif
