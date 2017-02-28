//
//  Project1.cpp
//  CS120
//
//  This is a program that will ask a returning
//  user to login with current username, or create
//  a new one if new user. Then the users will have
//  access to a menu that allows them to choose a
//  menu option to display a variety of dinosaurs
//  and their info from a file.
//
//  Created by Collin on 2/1/17.
//  Copyright © 2017 Collin. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//main function
int main()
{
    
    char returning;
    bool con = false;
    string username;
    
    while(con == false)
    {
        //Ask the user if they are returning or not
        cout << "Are you a returning user? (y/n): ";
        cin >> returning;
        
        if(returning != 'y' || returning != 'Y')
        {
            con = true;
        }
        else if (returning != 'n' || returning != 'N')
        {
            cout << "Enter a new username: " << endl;
            cin >> username;
            con = true;
        }
        else
        {
            cout << "Error: Must enter 'y' or 'n'" << endl;
        }
        
    }
    
    
    

    
    //Open the file users
    
    
    
    
    //End Program
    cout << endl;
    return 0;
}


