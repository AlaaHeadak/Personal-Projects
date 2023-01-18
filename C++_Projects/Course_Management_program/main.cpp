#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Course.h"
#include "Person.h"



using namespace std;

//char enrollment;


/************* Helper Functions **************/

void display_menu();

int get_selection();

void quite ();

void counting();

void unkown ();

void course_list();

void not_fully_booked();

/************* Global Variables **************/



Course programming {"programming", "Dr. Ing."," Prof1"};

Course dataBase {"dataBase", "Dr."," Prof2"};

Course softwareEngineering {"softwareEngineering",  "Dr.Ing Prof."," Prof2",};


int main()

{

    int selection {};



    do

    {

        display_menu();

        selection= get_selection();

        switch(selection)

        {

            case 1: course_list(); break;

            case 2: counting ();   break;

			case 3: not_fully_booked(); break;

            case 4: quite (); break;

            default: unkown();

        }

    }

    while(selection!=4);

    cout<<endl;

    return 0;





}



void display_menu()

{

    cout<<"\n1 - Registration for a course"<<endl;

    cout<<"2 - Output of one/all courses with data of the participants"<<endl;

    cout<<"3 - Output of all courses that are not fully booked yet"<<endl;

    cout<<"4 - Quit Operation"<<endl;

    cout<<"\nEnter your choice: ";

}



int get_selection()

{

    int selection{};

    cin>>selection;

    return selection;

}



void quite ()

{

    cout<<"<..."<<endl;

}





void course_list () // Fill the students vector

{

    int choice{};

    Student student;

    student.info_personal();

    student.info_student();

    do

    {


    cout<<"Please choose one or more courses from the list below."<<endl;

    cout<<"\n1 - Programming"<<endl;

    cout<<"2 - Databases"<<endl;

    cout<<"3 - Software Engineering"<<endl;

    cout<<"4 - Go back to the main menu"<<endl;

    cin>>choice;



    switch(choice)

        {

            case 1:

			if(programming.isRegistered(student.getEmail())!=true)
            {
                programming.registeredStudents.push_back(student); // Add one student
                programming.participantCount++;
                programming.displayParticipantsCount();
                break;
            }
            cout<<"You are already registered in this course, please select another course"<<endl;



            break;



            case 2:


            if(dataBase.isRegistered(student.getEmail())!=true)
            {
                dataBase.registeredStudents.push_back(student); // Add one student
                dataBase.participantCount++;
                dataBase.displayParticipantsCount();
                break;
            }
            cout<<"You are already registered in this course, please select another course"<<endl;

			break;



            case 3:

            if(softwareEngineering.isRegistered(student.getEmail())!=true)
            {
                softwareEngineering.registeredStudents.push_back(student); // Add one student
                softwareEngineering.participantCount++;
                softwareEngineering.displayParticipantsCount();
                break;
            }
            cout<<"You are already registered in this course, please select another course"<<endl;

			break;

            case 4: quite(); break;

            default: unkown();

        }

    }

    while(choice!=4&&toupper(student.getEnroll())=='Y');



}



void counting()

{


		programming.displayParticipantsCount();

		programming.displayParticipants();



        dataBase.displayParticipantsCount();

		dataBase.displayParticipants();



        softwareEngineering.displayParticipantsCount();

		softwareEngineering.displayParticipants();



		cout<<endl;





        //display( persons);



		if (programming.participantCount<3)

        {

            cout<<"Insufficient number of participants for programming course - Course will not take place"<<endl;



        }

        if (dataBase.participantCount<3)

        {

            cout<<"Insufficient number of participants for dataBase course - Course will not take place"<<endl;



        }

        if (softwareEngineering.participantCount<3)

        {

            cout<<"Insufficient number of participants for softwareEngineering course - Course will not take place"<<endl;

        }

}



void not_fully_booked()

{

    if(programming.participantCount<10)

    {cout<<"Programming course has "<< 10-programming.participantCount <<" places left"<<endl;}

    if(dataBase.participantCount<10)

    {cout<<"DataBase course has "<< 10-dataBase.participantCount <<" places left"<<endl;}

    if(softwareEngineering.participantCount<10)

    {cout<<"SoftwareEngineering course has "<< 10-softwareEngineering.participantCount <<" places left"<<endl;}



}



void unkown ()

{

    cout<<"Unkown selection, plese try again"<<endl;

}
