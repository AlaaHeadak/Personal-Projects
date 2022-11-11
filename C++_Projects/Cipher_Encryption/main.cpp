#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
int main()
{
	string alphabet {"[ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	string key {" [XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};
    
    string secret_message{};
    cout<<"Enter your message ";
    getline(cin, secret_message);
    
    string encrypted{};
    cout<<"\nEncrypting message..."<<endl;
    
    for (char c:secret_message)
    {
        size_t position=alphabet.find(c);
        if (position!=string::npos)
        {
           char new_char {key.at(position)};
           encrypted+=new_char;
            
        }
        else
        {
            encrypted+=c;
        }
        
        
    }
    cout<<"\nEncrypted message: "<<encrypted<<endl;
    
    
    
    string Decrypted{};
    cout<<"\nDecrypting message..."<<endl;
    
    for (char c:encrypted)
    {
        size_t position=key.find(c);
        if (position!=string::npos)
        {
           char new_char {alphabet.at(position)};
           Decrypted+=new_char;
        }
        else
        {
            Decrypted+=c;
        }
        
        
    }
    cout<<"\nDecrypted message: "<<Decrypted<<endl;
    
    cout<<endl;
	return 0;
}
