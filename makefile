#
# This is the makefile for 
# CSE1CPP Assignment B, Semester 2, 2018

CC = g++
LIBS = -g -Wall -std=c++17


hospital: sortPatient.o findDepartment.o patient.o meddept.o central.o
	$(CC) $(LIBS) -o hospital findDepartment.o patient.o meddept.o \
	                 sortPatient.o central.o

patient.o: patient.cpp
	$(CC) $(LIBS) -c patient.cpp

meddept.o: meddept.cpp
	$(CC) $(LIBS) -c meddept.cpp

central.o: central.cpp
	$(CC) $(LIBS) -c central.cpp

findDepartment.o: findDepartment.cpp
	$(CC) $(LIBS) -c findDepartment.cpp

sortPatient.o:sortPatient.cpp
	$(CC) $(LIBS) -c sortPatient.cpp

all: hospital clean

clean:
	rm *.o
