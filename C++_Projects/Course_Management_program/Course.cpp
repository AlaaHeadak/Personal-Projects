#include "Course.h"

//unsigned int i{};
void Course:: displayParticipants(void)

	{


		if (registeredStudents.size()==0)
            {
                cout<<"None is added yet!"<<endl;
            }

		else

			cout<<"[ ";

			for (auto everyone:registeredStudents)

			{

				everyone.displayStudentInfo();

			}

			cout<<"]"<<endl;


	}



	void Course:: displayParticipantsCount(void)

	{


	    cout << "Course: " << this->courseName << " has " << this->participantCount << " Students" << endl;

		cout << "Lecturer Name: " << this->courseLecturer.lecturerName

			 << "Title: " << this->courseLecturer.academicTitle << endl;



    }


    bool Course:: isRegistered (string mail)
    {
        for(auto student:registeredStudents)
        {
            if(student.getEmail().compare(mail)==0)
            {
                return true;

            }
        }
        return false;
    }



