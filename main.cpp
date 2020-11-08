// Richard Ruth
// COP2535.CM1
// Program reads in a string from user, and then let's the user know what string positions are available to see a certain
// character in a certain position. If user enters value outside allowable string boundaries, then an exception error
// is thrown and the program terminates in a controlled fashion.

#include <iostream>
#include <string>
using namespace std;

// create BCheckString class derived from STL string class

class BCheckString : string
{
    
// declare class variables
    
private:
    int stringSize;
    char *stringPhrase;
    int position;
    
public:
    
    // create BoundsException class for exception handling
    
    class BoundsException
    {};
    
    //
    
    BCheckString(string s)  // BCheckString class constructor
    {
        stringSize = static_cast<int>(s.length());
        stringPhrase = new char[stringSize];
        
        for(int i=0; i < stringSize; i++)
            stringPhrase[i] = s[i];
        
        cout << "\nLegitimate string positions are: 0.." << stringSize-1 << endl;
        
    }
    
    // operator function that tests bounds of user input for string character position
    
    char operator[] (int k)
    {
        if(k>=0 && k < stringSize)
        {
            cout << "\nThe character at position " << k << " is " << stringPhrase[k] << endl;
        }
        else
        
        // user input is outside permissible bounds - throw exception
            
        {
            throw BoundsException();
        }
        return stringPhrase[k];
    }
};

int main()
{
    string userString;
    int position;
    bool run = true;
    
    cout << "This program demonstrates bounds checking on string object.\n";
    cout << "Enter a string: ";
    getline(cin, userString);
    BCheckString object(userString);
    while (run)
    {
        cout << "\nEnter an integer describing a position inside or outside the string: ";
        try
        {
            cin >> position;
            object.operator [] (position);
        }
        catch (BCheckString :: BoundsException)                         // catch for BoundsException class error handling
        {
            cout << "\nAccess violation in string." << endl;
            run = false;
        }
    }
    return 0;
}
