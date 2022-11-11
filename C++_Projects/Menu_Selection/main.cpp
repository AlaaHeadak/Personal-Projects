#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> numbers{};
    char selection{};
    
    do
    {
        /* Display Menue*/
        cout<<"\nP - Print numbers"<<endl;
        cout<<"A - Add a number"<<endl;
        cout<<"M - Display the average"<<endl;
        cout<<"S - Display the smallest number"<<endl;
        cout<<"L - Display the largest number"<<endl;
        cout<<"Q - Quit"<<endl;
        cout<<"\nEnter your choice"<<endl;
        cin>>selection;
        
        if (selection=='P'||selection=='p')
        {
            if (numbers.size()==0)
            {
                cout<<"The list is empty"<<endl;
                
            }
            else
            {
                cout<<"[";
                for(auto num: numbers)
                {
                    cout<<num<< " ";
                }
                cout<<"]";
                
            }
            
        }
        else if(selection=='A'||selection=='a')
        {
            int num_add{};
            cout<<"Enter an integer to add to the list"<<endl;
            cin>> num_add;
            numbers.push_back(num_add);
            cout<<num_add<<" added"<<endl;
        }
        else if (selection=='M'||selection=='m')
        {
            if (numbers.size()==0)
            {
                cout<<"This is an empty list"<<endl;
            }
            else
            {
                int total{};
                for(auto num:numbers)
                {
                    total+=num;
                }
                cout<<"The avergae value is: "<<static_cast<double>(total)/numbers.size()<<endl;
                
            }
            
        }
        else if (selection=='S'||selection=='s')
        {
            if (numbers.size()==0)
            {
                cout<<"This is an empty list"<<endl;
            }
            else
            {
                int smallest=numbers.at(0);
                for (auto num:numbers)
                {
                    if (num<smallest)
                    {
                        smallest=num;
                        
                    }
                    
                    
                }
                cout<<"The smallest number is: "<<smallest<<endl;
                
            }
            
        }
         else if (selection=='L'||selection=='l')
        {
            if (numbers.size()==0)
            {
                cout<<"This is an empty list"<<endl;
            }
            else
            {
                int largest=numbers.at(0);
                for (auto num:numbers)
                {
                    if (num>largest)
                    {
                        largest=num;
                        
                    }
                   
                    
                }
                 cout<<"The largest number is: "<<largest<<endl;
            }
            
            
        }
        else if (selection=='Q'||selection=='q')
        {
            cout<<"Goodbye"<<endl;
        }
        else
        {
            cout<<"Unrecognized character..error";
        }
        
        
        
    }
    while (selection!='q'&& selection!='Q');
    
	cout << endl;
	return 0;
}
