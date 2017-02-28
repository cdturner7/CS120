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
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

//functions
void displayMenu();
void menuOption(int m);


//main function
int main()
{
    //initiate
    char returning;
    bool con = false;
    bool con2 = false;
    string username;
    vector <string> users;   //stores the usernames in the "database"
    string line;             //file line
    int i;
    char main;
    
    ///////////////////////////////
    //TITLE OF PROGRAM - GREETING//
    ///////////////////////////////
    //fix the width
    cout << "           Welcome To           " << endl;
    cout << "           DINOTOPIA            " << endl;
    cout << setw(32) << setfill('*');
    cout << "" << endl;
    cout << endl;
 
    
////////////////////////////////////////////////////////////////////////////
//////////////////        USER LOG IN        ///////////////////////////////
 
    
    cout << "Log In - " << endl;
    while(con == false)
    {
        //Ask the user if they are returning or not and some error checking with input
        cout << "Are you a returning user? (y/n): ";
        cin >> returning;
        
        //Error input is too long
        if (cin.get() != '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
            cout << "Error: Input too many characters. (Enter 'y' or 'n')\n" << endl;
        }
        
        //They are returning user
        else if(returning == 'y' || returning == 'Y')
        {
            cout << "Welcome Back!" << endl;
            con = true;
        }
        
        //New user
        else if (returning == 'n' || returning == 'N')
        {
            cout << "Welcome!" << endl;
            con = true;
        }
        
        //error input other
        else
        {
            cin.clear();
            cout << "Error: Must enter 'y' or 'n'\n" << endl;
        }
    }
    cout << endl;
    
    //Open the file of usernames and put them in a vector
    ifstream inFile("users.txt");
    while (inFile)
    {
        inFile >> line;
        string junk;
        getline(inFile, junk);
        users.push_back(line);
    }
    inFile.close();
    
////////////////////////////////////////////////////////////////////////////
/////////////////     Is NOT returning user     ////////////////////////////
    
    //add the new username to the users.txt
    if(returning == 'n' || returning == 'N')
    {
        con = true;
        //Loop until new log in created
        while(con)
        {
            cout << "Enter a new username: ";
            cin >> username;
            //make sure username isn't already taken
            for(i = 0; i < users.size(); i++)
            {
                //username is found in the username vector
                if(!username.compare(users[i]))
                {
                    cout << "\nSorry, the username " << username << " is already taken " << endl;
                    break;
                }
            }
            //username was not found in username vector
            if(i == users.size())
            {
                cout << "\nUser log in success! Welcome " << username << endl;
                con = false;
            }
        }
        
        
        fstream uf;
        uf.open("users.txt", fstream::app);
        {
            uf << username << endl;
            uf.close();
        }
    }

////////////////////////////////////////////////////////////////////////////
//////////////////     Is returning user     ///////////////////////////////
    
    //error check for the username of prior account
    else
    {
        cout << "Enter your username: ";
        cin >> username;
        int count = 0;
        con = true;
        
        //Loop until the log in fails or succeeds
        while(con)
        {
            //loop through the username vector
            for(i = 0; i < users.size(); i++)
            {
                //username is found in the username vector
                if(!username.compare(users[i]))
                {
                    cout << "Log on success! Hi " << username << endl;
                    con = false;
                    break;
                }
            }
            //username is not found in the username vector
            if(con)
            {
                cout << "Sorry username does not exist." << endl;
                cout << "Try again: ";
                cin >> username;
                i = 0;
                count += 1;
                if (count == 5)
                {
                    cout << "Too many attempts\n" << endl;
                    cout << "Program is quitting . . . " << endl;
                    return 0;
                }
            }
        }
    }
    
    /*
    //TEST  - Print the vector of usernames
    cout << endl;
    cout << "*************" << endl;
    for(int i = 0; i < users.size() - 1; i++)
    {
        cout << users[i] << endl;
    }
    cout << username << endl;
    cout << "*************" << endl;
    */
    
    
    //Menu
    int choice;
    con = false;
    while(!con)
    {
        displayMenu();
        cin.clear();
        cin >> choice;
        //Error input is too long
        if (cin.get() != '\n')
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.clear();
            cout << "Error: Input too many characters (Enter a menu choice)\n";
        }
        //not a number from menu
        else if((choice < 1) || (choice > 4))
        {
            cout << "Error: Needs to be a menu choice\n";
            cin.clear();
        }
        //They chose the correct menu option
        else if((choice >= 1) && (choice < 4))
        {
            //display what the menu option should display
            menuOption(choice);
            
            //Ask user if they want to return to menu again or quit
            con2 = false;
            while(!con2)
            {
                //Ask the user if they are returning or not and some error checking with input
                cout << "Would you like to return to main menu? (y/n): ";
                cin >> main;
                
                //Error input is too long
                if (cin.get() != '\n')
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cin.clear();
                    cout << "Error: Input too many characters. (Enter 'y' or 'n')\n" << endl;
                }
                
                //They are returning user
                else if(main == 'y' || main == 'Y')
                {
                    con2 = true;
                }
                
                //New user
                else if (main == 'n' || main == 'N')
                {
                    cout << "\nThank you for using Dinotopia" << endl;
                    cout << "Exiting the program now . . ." << endl;
                    con2 = true;
                    con = true;
                }
                
                //error input other
                else
                {
                    cin.clear();
                    cout << "Error: Must enter 'y' or 'n'\n" << endl;
                }
            }

        }
        
        //Exit code
        else if(choice == 4)
        {
            cout << "\nThank you for using Dinotopia" << endl;
            cout << "Exiting the program now . . ." << endl;
            con = true;
        }
        //Not an integer
        else
        {
            cout << "Error: Must be a menu option\n" << endl;
            cin.clear();
        }
    }
    //End Program
    cout << endl;
    return 0;
}



//The display menu
void displayMenu()
{
    cout << endl;
    cout << "         DINOTOPIA MENU         " << endl;
    cout << setw(32) << setfill('*');
    cout << "" << endl;
    cout << "1) Dinos!" << endl;
    cout << "2) Dino Facts" << endl;
    cout << "3) Dino Pics" << endl;
    cout << "4) Exit Dinotopia Program" << endl;
    cout << "\nEnter menu option: ";
    cin.clear();
}


//Menu option codes
void menuOption(int m)
{
    double dinoYear = 65000000.0;
    cout << "\nYou chose menu option #" << m << endl;

    //vector of dinos
    vector<string> dinos = {"Tyrannosaurus Rex","Velociraptor","Triceratops","Apatosaurus","Diplodocus","Stegosaurus"};
    //Print to console depending on menu option chosen!
    switch (m)
    {
        case 1: cout << endl;
                cout << "Dinos ranked on popularity" << endl;
                cout << setw(26) << setfill('-');
                cout << "" << endl;
                cout << setfill('.');
                for (int i = 0; i < dinos.size(); i++)
                {
                    cout << dinos[i];
                    cout << setw(25 - dinos[i].length()) << (i+1);
                    cout << endl;
                }
                cout << endl;
                break;
            
        case 2: cout << endl;
                cout << "        Dino Facts        " << endl;
                cout << setw(26) << setfill('-');
                cout << "" << endl;
                cout << "\n1. Dinosaurs were around " << scientific << dinoYear << " years ago."<< endl;
                cout << fixed << setprecision(2);
                cout << "2. Diplodocus were around 90ft (" << 27.4352 << " m) tall" << endl;
                cout << "3. Stegasaurus was a plant-eating dinosaur" << endl;
                cout << "4. T-rex stands for Tyrannosaurus Rex\n" << endl;
                break;
            
        case 3: cout << endl;
                cout << "        Dino Fics         " << endl;
                cout << setw(26) << setfill('-');
                cout << "" << endl;
                cout << "\nDino Pic 1\nDino Pic 2\nDino Pic 3\nDino Pic 4\nDino Pic 5\nDino Pic 6\n   ... \n\n";
                break;
    }
}

