#include "Person.h"
#include "Course.h"

void Person::info_personal(void)

    {


        cout<<"Please enter your First name"<<endl;
        cin>>First_name;

        cout<<"Please enter your Last name"<<endl;
        cin>>Last_name;

        cout<<"Please enter your e-mail address"<<endl;
        cin>>mail;


    }

void  Student::info_student(void)

    {

        cout<<"Enter your matriculation number"<<endl;
        cin>>matriculation;

        cout<<"Are you enrolled in this university? (Y/N)"<<endl;
        cin>>enrollment;

        if (toupper(enrollment)=='Y')

        {

            cout<<"You can register in muliple courses"<<endl;

        }

        else

        {

            cout<<"You can register in only one course"<<endl;

        }

    }
void Student::displayStudentInfo(void)

	{

		cout << "==========Student Data==========" << endl;

		cout << "First name: " << getFirstName() << endl;

		cout << "Last name: " << getLastName() << endl;

		cout << "Email: " <<  getEmail() << endl;

		cout << "Matriculation number: " <<  matriculation << endl;

		cout << "=================================" << endl;

	}


