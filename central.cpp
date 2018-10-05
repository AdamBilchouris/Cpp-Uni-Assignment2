#include "central.h"

//iostream
using std::cout;
using std::cin;
using std::string;
using std::endl;

//string
using std::string;

//fstream
using std::ifstream;
using std::ofstream;

//vector
using std::vector;

//list
#include <list>
using std::list;

//helper functions
bool fileExists(const string& fileName);
bool departmentExists(const string& departmentName, const HOSPITAL_MAP& hosMap);
bool patientExists(int urNumber, const HOSPITAL_MAP& hosMap);

static bool choiceForMenu = false;

int main( )
{
   int choice = -1;
   HOSPITAL_MAP hosMap;
   load( hosMap );

   while( choice != static_cast<int>(MAIN::EXIT ))
   {
      do
      {
         choiceForMenu = false;
         displayMainMenu( );
         std::cout << "Enter choice >> " ;
         std::cin >> choice;
         std::cin.ignore( 100000, '\n' );

         if(cin.fail() == true)
         {
            choiceForMenu = true; 
            cout << "Please enter an integer" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
         }

      }while(choiceForMenu == true);

      process(static_cast<MAIN>(choice), hosMap);
      //static_cast as we know that it going to be casted to an enum
   }

   std::cout << std::endl;

   return 0;
}

void process( MAIN choice, HOSPITAL_MAP& hosMap )
{
   //will make the variable to check if it is a bad input false again to make sure the loop doesn't stuff up
   switch( choice )
   {
      case MAIN::ADD_DEPARTMENT:
         addDepartment( hosMap );
         choiceForMenu = false;
         break;

      case MAIN::ADD_PATIENT: 
         addPatient( hosMap );
         choiceForMenu = false;
         break;

      case MAIN::DISPLAY:
         display( hosMap );
         choiceForMenu = false;
         break;

      case MAIN::SAVE:
         save( hosMap );
         choiceForMenu = false;
         break;

      case MAIN::EXIT:
         // just trap this choice so that it does not
         // show as an invalid menu choice
         break;

      default:
         std::cout << "That is not a valid choice" << std::endl;
         choiceForMenu = false;
         break;
   }
}

void displayMainMenu( )
{
   std::cout << "\nWelcome to the Hospital Main Menu" << std::endl;

   std::cout << static_cast<int>(MAIN::ADD_DEPARTMENT) << ". Add Department " << std::endl;

   std::cout << static_cast<int>(MAIN::ADD_PATIENT) << ". Add Patient" << std::endl;

   std::cout << static_cast<int>(MAIN::DISPLAY) << ". Display" << std::endl;

   std::cout << static_cast<int>(MAIN::SAVE) << ". Save to a text file" << std::endl;

   std::cout << static_cast<int>(MAIN::EXIT) << ". Close the program" << std::endl;
}

void addDepartment( HOSPITAL_MAP & hosMap )
{
   string departmentName;

   cout << "Enter department name >> ";
   getline(cin, departmentName);

   if(departmentExists(departmentName, hosMap) == true)
   {
      cout << "This department already exists" << endl;
   }
   else
   {
      MedDept tempMedDept(departmentName);
      cin >> tempMedDept;

      vector<Patient> tempVector;   //empty vector for the key-value pair

      hosMap.insert(H_MAP_VT(tempMedDept, tempVector));
   }
}

void display( const HOSPITAL_MAP & hosMap )
{
   //Reference: http://www.cplusplus.com/reference/map/map/begin/
   //Lab 08

   //creates a temporary list
   list<int> sizeOfEachDepartment;
   for(auto hosMapIter = hosMap.begin(); hosMapIter != hosMap.end(); ++hosMapIter)
   {
      int totalPatients = 0;
      vector<Patient>::const_iterator patientIter;

      for(patientIter = hosMapIter->second.begin(); patientIter != hosMapIter->second.end(); ++patientIter)
      {
         totalPatients += 1; 
      }
      sizeOfEachDepartment.emplace_back(totalPatients);
   }

   auto listIter = sizeOfEachDepartment.begin();

   for(auto hosMapIter = hosMap.begin(); hosMapIter != hosMap.end(); ++hosMapIter)
   {
      cout << hosMapIter->first;

      cout << endl;

      int tempSize = *listIter;  //assings a temporary variable

      if(tempSize == 0)
      {
         cout << "This Department has no patients" << endl;
      }

      else
      {
         cout << "This department currently has " << tempSize << " patients" << endl;
         cout << "\nCan take " << (hosMapIter->first.getCapacity() - tempSize) << " more patients" << endl;

         vector<Patient>::const_iterator patientIter;
         patientIter = hosMapIter->second.begin();

         cout << "\nHere are the list of patients for this Department" << endl;

         for(patientIter = hosMapIter->second.begin(); patientIter != hosMapIter->second.end(); ++patientIter)
         {
            cout << *patientIter << endl;
         }
      }

      cout << endl;
      ++listIter;
   }
}

void addPatient( HOSPITAL_MAP & hosMap )
{
   int indexOfDepartment = 0;
   int sizeOfDepartment = 0;

   list<int> sizeOfEachDepartment;
   for(auto hosMapIter = hosMap.begin(); hosMapIter != hosMap.end(); ++hosMapIter)
   {
      int totalPatients = 0;
      vector<Patient>::const_iterator patientIter;

      for(patientIter = hosMapIter->second.begin(); patientIter != hosMapIter->second.end(); ++patientIter)
      {
         totalPatients += 1; 
      }
      sizeOfEachDepartment.emplace_back(totalPatients);
   }

   string departmentName;

   cout << "Enter department name >> ";
   getline(cin, departmentName);

   if(departmentExists(departmentName, hosMap) == false)
   {
      cout << "No Department with that name was found" << endl;
   }

   else
   {
      string patientName; string bloodType; int urNumber = 0; int tLevel = 0;

      hMapIter hosMapIter;

      for(hosMapIter = hosMap.begin(); hosMapIter != hosMap.end(); ++hosMapIter)
      {
         if(hosMapIter->first.getDepartmentName() == departmentName)
         {
            break;
         }
         else
         {
            indexOfDepartment += 1;
         }
      }

      auto tempListIter = sizeOfEachDepartment.begin();
      for(int i = 0; i < indexOfDepartment; ++i)
      {
         ++tempListIter;
      }

      sizeOfDepartment = *tempListIter;

      if(sizeOfDepartment >= hosMapIter->first.getCapacity())
      {
         cout << "This Department is at full capacity, cannot add anymore patients" << endl;
      }
      else
      {
         cout << "Enter patient name >> ";
         getline(cin, patientName);

         cout << "Enter the UR number (int) >> ";
         cin >> urNumber;
         cin.clear();
         cin.ignore(1000, '\n');

         if(patientExists(urNumber, hosMap) == true)
         {
            cout << "A patient wiht this UR Number already exists" << endl;
         }
         
         else
         {
            cout << "\nEnter blood type >> ";
            getline(cin, bloodType);
            
            cout << "Enter t level (int) >> ";
            cin >> tLevel;
            cin.clear();
            cin.ignore(1000, '\n');

            Patient tempPatient(patientName, urNumber, bloodType, tLevel);

            hosMapIter->second.emplace_back(tempPatient);
            std::sort(hosMapIter->second.begin(), hosMapIter->second.end(), sortPatient());
         }
      }

      //make an iterator and a for loop
      //keep searching the for loop until the department name is found
      //e.g. hosMapIter->first.getDepartmentName() == departmentName;
      //check if the the department can hold more people
   }

}

void save( const HOSPITAL_MAP & hMap )
{
   string fileName {""};

   cout << "Enter the file name (to save to) >> ";
   getline(cin, fileName);

   ofstream fout(fileName);

   list<int> sizeOfEachDepartment;

   for(auto hMapIter = hMap.begin(); hMapIter != hMap.end(); ++hMapIter)
   {
      int totalPatients = 0;
      vector<Patient>::const_iterator patientIter;

      for(patientIter = hMapIter->second.begin(); patientIter != hMapIter->second.end(); ++patientIter)
      {
         totalPatients += 1; 
      }
      sizeOfEachDepartment.emplace_back(totalPatients);
   }

   auto listIter = sizeOfEachDepartment.begin();

   for(auto hMapIter = hMap.begin(); hMapIter != hMap.end(); ++hMapIter)
   {
      fout << hMapIter->first;

      fout << (*listIter) << endl;

      for(auto patientIter = hMapIter->second.begin(); patientIter != hMapIter->second.end(); ++patientIter)
      {
         fout << *patientIter;
      }

      ++listIter;
   }
}

void load( HOSPITAL_MAP & hMap )
{
   string fileName {""};

   cout << "Enter file name >> ";
   getline(cin, fileName);

   if(fileExists(fileName) == false)   //gets the state of the good bit from the method below, if the good bit is false (i.e. anything but the good bit), it say that the file is empty
   {
      cout << "The file you entered does not exist, returning to the menu" << endl;
      return;
   }
   else
   {
      ifstream fin(fileName);

      if(fin.peek() == EOF)   //checks for the End Of File bit
      {
         cout << "The file you entered is empty, returning to the menu" << endl;
         return;
      }
      else
      {
         while(!fin.eof())
         {
            int patientsToRead;
            vector<Patient> tempPatientVector;

            MedDept tempMedDept;

            fin >> tempMedDept;

            Patient tempPatient; 

            fin >> patientsToRead;
            fin.ignore(1000, '\n');

            for(int i = 0; i < patientsToRead; ++i)
            {
               fin >> tempPatient;
               tempPatientVector.emplace_back(tempPatient);
            }

            std::sort(tempPatientVector.begin(), tempPatientVector.end(), sortPatient());

            hMap.insert(H_MAP_VT(tempMedDept, tempPatientVector));

            if(fin.peek() == EOF)
            {
               break;
            }
         }
      }

      fin.close();
   }
   //get an integer in, use a for loop to read that many patients from the given
   //variable, could be something like:
   //department -> map; int patientsToRead -> some value; for(int i = 0; i < patientsToRead; i++) { fin >> patients; }
}

//to see if the file exists, if it doesn't display an error to the user
bool fileExists(const string& fileName)
{
   //creates a ifstream object for the given filename
   ifstream fin(fileName);
   //returns the conidition of the good bit, if the file doesn't exist, the bit
   //will be bad, if it does exist the but will be good.
   return fin.good();
}

bool departmentExists(const string& departmentName, const HOSPITAL_MAP& hosMap)
{
   //scans through every department name, if a department with the same name
   //exists, return true
   for(auto hosMapItr = hosMap.begin(); hosMapItr != hosMap.end(); ++hosMapItr)
   {
      if((hosMapItr->first.getDepartmentName()) == departmentName)
      {     
         return true;
      }
   }
   return false;
}

bool patientExists(int urNumber, const HOSPITAL_MAP& hosMap)
{
   for(auto hosMapIter = hosMap.begin(); hosMapIter != hosMap.end(); ++hosMapIter)
   {
      vector<Patient>::const_iterator patientIter;
      patientIter = hosMapIter->second.begin();

      for(patientIter = hosMapIter->second.begin(); patientIter != hosMapIter->second.end(); ++patientIter)
      {
         if(patientIter->getUR() == urNumber)
         {
            return true;
         }
      }
   }
   return false;
   //scan through each department and their patients, if any return true, give an error
}
