#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void display_menu();
char get_selection();
void display(const vector <int> &v);
void add (vector <int> &v);
void average (const vector <int> &v);
void find (const vector <int> &v);
void quite ();
void unkown ();
void Smallest (const vector <int> &v);
void largest (const vector <int> &v);
bool find_state(const vector <int> &v,int target);


int main ()
{
    vector <int> numbers;
    char selection {};
    
    do
    {
        display_menu();
        selection= get_selection();
        
        switch(selection)
        {
            case 'P':
            display (numbers);
            break;
            
            case 'A':
            add (numbers);
            break;
            
            case 'M':
            average (numbers);
            break;
            
            case 'S':
            Smallest (numbers);
            break;
            
            case 'L':
            largest (numbers);
            break;
            
            case 'F':
            find (numbers);
            break;
            
            case 'Q':
            quite ();
            break;
            
            default:
            unkown();
        }
        
    }
    while(selection!='Q');
    cout<<endl;
    return 0;
    
}


void display_menu()
{
    cout<<"\nP - Print numbers"<<endl;
    cout<<"A - Add a number"<<endl;
    cout<<"M - Display the average"<<endl;
    cout<<"S - Display the smallest number"<<endl;
    cout<<"L - Display the largest number"<<endl;
    cout<<"F - Find a number"<<endl;
    cout<<"Q - Quit Operation"<<endl;
    cout<<"\nEnter your choice: ";
    
}

char get_selection()
{
    char selection{};
    cin>>selection;
    return toupper(selection);
}

void display(const vector <int> &v)
{
    if (v.size()==0)
    {
        cout<<"This is an empty list"<<endl;
    }
    else
        {
        cout<<"[ ";
        for (auto num:v)
        {
            cout<<num<<" ";
        }
        cout<<"]"<<endl;
        }
}

void add (vector <int> &v)
{
    int num{};
    cout<<"Enter an integer to add to the list: ";
    cin>>num;
    v.push_back(num);
    cout<<num<<" added"<<endl;
    
}

void average (const vector <int> &v)
{
    if (v.size()==0)
    {
        cout<<"The list is empty; unable to calculate the average"<<endl;
    }
    else
    {
        int total{};
        for(auto num:v)
        {
           total+=num;
        }
        //return static_cast<double>(total)/v.size(); 
        cout<<"The avergae value is: "<<static_cast<double>(total)/v.size()<<endl;
    }
    
}

void quite ()
{
    cout<<"GoodBye"<<endl;
}

void unkown ()
{
    cout<<"Unkown selection, plese try again"<<endl;
}

void Smallest (const vector <int> &v)
{
    if (v.size()==0)
    {
        cout<<"This is an empty list"<<endl;
    }
    else
    {
        int smallest=v.at(0);
        for (auto num:v)
        {
            if (num<smallest)
            {
                smallest=num;
                
            }
            
        }
        cout<<"The smallest number is: "<<smallest<<endl;
                    
    }
}

void largest (const vector <int> &v)
{
    if (v.size()==0)
    {
        cout<<"This is an empty list"<<endl;
    }
    else
    {
        int smallest=v.at(0);
        for (auto num:v)
        {
            if (num>smallest)
            {
                smallest=num;
                
            }
            
        }
        cout<<"The largest number is: "<<smallest<<endl;
                    
    }
}

void find (const vector <int> &v)
{
    int target{};
    cout<<"Find your target number: ";
    cin>>target;
    if(find_state(v,target))
    {
        cout<<target<<" was found"<<endl;
    }
    else
    {
        cout<<target<<" was not found"<<endl;
    }
    
    
}

bool find_state(const vector <int> &v,int target)
{
    for (auto num:v)
    {
        if (num==target)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    
}