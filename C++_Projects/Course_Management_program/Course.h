#ifndef _COURSE_H_
#define _COURSE_H_

#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include <iterator>
using namespace std;

class Course

{

public:

    int participantCount = 0;

	string courseName;

	vector <Student> registeredStudents;

	Lecturer courseLecturer;

	Course(string cName, string lName, string lTitle)

	:courseName(cName), courseLecturer{lName,lTitle}

	{



	}


	;



	void displayParticipants(void);

	void displayParticipantsCount(void);

    bool isRegistered (string mail);



};




#endif // COURSE_H
