#ifndef MED_DEPT_H
#define MED_DEPT_H

#include <iostream>
#include <string>
using std::string;
#include <fstream>

class MedDept
{
public:
    MedDept( ) = default;
    MedDept( const string & name, int capacity, const string & tType );
    MedDept( const string& name, int capacity, const string& tType, int currentPatients); //used for file reading
    MedDept( const MedDept& md );

    explicit MedDept( const string& name );

    ~MedDept( ) noexcept {     }

    const string& getDepartmentName( ) const
    { return name; }

    int getCapacity( ) const { return capacity; }

    const string& getTreatmentType() const 
    { return treatmentType; }

    friend std::ostream& operator << (std::ostream& os, const MedDept & md );
    friend std::ofstream& operator << (std::ofstream& os, const MedDept & md );

    friend std::istream& operator >> (std::istream& is, MedDept & md );
    friend std::ifstream& operator >> (std::ifstream& is, MedDept & md );

private:
    string name {"unknown Dept."};
    int capacity { 0 };
    string treatmentType {"generic"};
};

#endif
