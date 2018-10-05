#ifndef CENTRAL
#define CENTRAL

#include "patient.h"
#include "meddept.h"
#include <map>
#include <vector>
#include "findDepartment.h"
#include "sortPatient.h" 

#include <algorithm>

typedef std::map<MedDept, std::vector<Patient>, findDepartment> HOSPITAL_MAP;
typedef HOSPITAL_MAP::value_type H_MAP_VT;
typedef HOSPITAL_MAP::iterator hMapIter;
typedef HOSPITAL_MAP::const_iterator hMapConstIter;

enum class MAIN { ADD_DEPARTMENT = 1, ADD_PATIENT, DISPLAY, SAVE, EXIT};

void process( MAIN choice, HOSPITAL_MAP& hMap );

void displayMainMenu( );

void addDepartment( HOSPITAL_MAP& hMap );

void addPatient( HOSPITAL_MAP& hMap );

void display( const HOSPITAL_MAP & hMap );

void save( const HOSPITAL_MAP & hMap );

void load( HOSPITAL_MAP & hMap );

#endif
