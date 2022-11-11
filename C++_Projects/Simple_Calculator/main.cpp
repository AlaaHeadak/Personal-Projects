#include <iostream>
#include <math.h>
using namespace std;


int getValue()
{

  int num1;
  int counter=0;

  cout<<"Please enter 2 numbers"<<endl;
  cin>>num1;

  return num1;

}

int getChoice()
{

  int choice ;

  cout<<"Please enter the number of your operation (1:5)"<<endl<<"Press 1 for submission"<<endl<<"Press 2 for subtraction"<<endl<<"Press 3 for Multiplication"<<endl<<"Press 4 for Division"<<endl<<"Press 5 for Remainder"<<endl<<"Press 6 for Power"<<endl;
  cin>>choice;

  return choice;

}


double Add(double a, double b)
{
    return a+b;
}
double Sub(double a, double b)
{
    return a-b;
}
double Multi(double a, double b)
{
    return a*b;
}
double Div(double a, double b)
{
    return a/b;
}
int Remainder(int a, int b)
{
    return a%b;
}
double Power(double a, double b)
{
    return pow(a,b);
}



double result()
{

    int num1, num2;
    int choice;

    num1= getValue();
    num2=getValue();
    choice=getChoice();



    switch(choice)
    {
    case 1:
        cout<<"result"<<"="<<" "<<num1<<"+"<<num2<<"="<<num1+num2;
        break;

    case 2:
        cout<<"result"<<"="<<" "<<num1<<"-"<<num2<<"="<<num1-num2;
        break;

    case 3:
        cout<<"result"<<"="<<" "<<num1<<"*"<<num2<<"="<<num1*num2;
        break;

    case 4:
        cout<<"result"<<"="<<" "<<num1<<"/"<<num2<<"="<<num1/num2;
        break;

    case 5:
        cout<<"result"<<"="<<" "<<num1<<"%"<<num2<<"="<<num1%num2;
        break;

    case 6:
        cout<<"result"<<"="<<" "<<num1<<"^"<<num2<<"="<<pow(num1,num2);
        break;

    default:
        cout<<"Invalid Choice";
        break;
    }
}


int main()
{
    result();
    return 0;
}
