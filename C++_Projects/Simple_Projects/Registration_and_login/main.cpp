#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forget();


int main()
{
    int choice;
    cout<<"\t\t\t______________________________________________________\n\n\n";
    cout<<"\t\t\t           Welcome to the login page!                 \n\n\n";
    cout<<"\t\t\t___________________Menue______________________________\n\n\n";
    cout<<"                                                              \n\n";
    cout<<"\t   Press 1 to login                         |"<<endl;
    cout<<"\t   Press 2 to Register                      |"<<endl;
    cout<<"\t   Press 3 to Reset your password           |"<<endl;
    cout<<"\t   Press 4 to Exit                          |"<<endl;
    cout<<"\n\t\t\t Please enter 1,2,3 or 4"<<endl;
    cin>>choice;
    cout<<endl;
    switch (choice)
    {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forget();
            break;
        case 4:
            cout<<"\t\t\t  Thank you!  \n\n";
        default:
        system("cls");
        cout<<"\t\t\t  Invalid Process, Please only select 1,2,3 or 4"<<endl;
        main();
        
    }
    
}
void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t   Please enter the username & password: "<<endl;
    cout<<"\t\t\t  Username ";
    cin>>userId;
    cout<<"\t\t\t  Password ";
    cin>>password;
    
    ifstream input("records.txt");
    
    while(input>>id>>pass)
    {
        if(id==userId  && pass==password)
        {
            count=1;
            system("cls");
        }
        
    }
    input.close();
    if(count==1)
    {
        cout<<userId<<"\n Successful Login!";
        main();
    }
    else
    {
        cout<<"\n Login Error";
        main();
    }
    
}

void registration()
{
    string ruserId,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Login Enter the username: ";
    cin>>ruserId;
    cout<<"\t\t\t Login Enter the password: ";
    cin>>rpassword;
    
    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\t\t\t Registration Successful! ";
    main();
    
}

void forget()
{
    int option;
    system("cls");
    cout<<"\t\t\t  Click Here if you forget the password";
    cout<<"Press 1 to search your ID by your username";
    cout<<"Press 2 to go back to the main menue";
    cout<<"\t\t\t Press 1/2";
    cin>>option;
    
    switch(option)
    {
        case 1:
        {
            int count =0;
            string suserId, sId,spass;
            cout<<"\n\t\t\t Enter the Username you remember: ";
            cin>>suserId;
            
            ifstream f2 ("records.txt");
            while(f2>>sId>>spass)
            {
                if (sId==suserId)
                {
                    count=1;
                }
                f2.close();
                if (count==1)
                {
                    cout<<"\n\n your account is found! \n";
                    cout<<"\n\n your password is: "<<spass;
                    main();
                }
                else
                {
                   cout<<"\n\n Sorry, couldn't find your account!!! \n";
                   main();
 
                }
                break;
                
            }
        }
            case 2:
            {
                main();
            }
            default:
            cout<<"Wrong, Please try again!"<<endl;
            forget();
        }
        
    }
