#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person

{

private:

    string First_name;

    string Last_name;

    string mail;

public:
    void info_personal();
    string getFirstName(){return First_name;}
    string getLastName() {return Last_name;}
    string getEmail() {return mail;}

};

class Student:public Person

{

private:

    int matriculation;
    char enrollment;
public:
	void info_student();
	void displayStudentInfo(void);
	char getEnroll() {return enrollment;}

};





class Lecturer: private Person

{

    public:

    string academicTitle;

	string lecturerName;

    Lecturer(string aTitel, string lName): academicTitle(aTitel), lecturerName(lName)

    {



    }


};



#endif // PERSON_H
