//
//  main.cpp
//  Project5
//
//  Created by Collin on 2/22/17.
//  Copyright © 2017 Collin. All rights reserved.
//
/*
 
 MY PROGRAM -
 
 The fourth part of my on going FIFA project transforms the 
 FIFA_player class into an abstract class, and four derived
 child classes FIFA_goalie, FIFA_midfielder, FIFA_defenseman 
 and FIFA_striker. These classes override and inherit specific 
 functions and fields defined in the parent class.
 
 The pure virtual method in the parent class FIFA_player is 
 calcOverall. This is a method that based upon the position
 or class the FIFA-player is in, the overall field is calculated
 differently. Example would be a striker's overall stat is affected
 by their shot accuracy percentage, goals and assists. But a goalie
 has overall calculated base upon goals conceded and saves.
 
 NOTE: goals are represented by total of the season. Similarly 
 assists are season long totals. However most if not all of the
 other individual child classes fields are per game (pg) statistics.
 
 */

#include <iostream>
#include "FIFA.hpp"

using namespace std;

/*

 MAIN - for testing for the abstract class and the child classes
 
 */

int main()
{
    ////////////////////////
    // Striker Class Test //
    ////////////////////////
    cout << "Start to testing the FIFA_striker child class:\n\n" << endl;
    
    //Create a striker fifa player
    FIFA_striker sturridge = FIFA_striker();
    cout << sturridge << "\n" << endl;
    
    //test all the setters
    sturridge.setName("Daniel Sturridge");  //set name
    sturridge.setTeam("Liverpool FC");      //set teams name
    sturridge.setGoals(15);                 //set season long goals
    sturridge.setAssists(18);               //set season long assists
    sturridge.setStart(true);               //set starting on the field
    sturridge.setShots(6);                  //set shots - average per game stat
    sturridge.setShotsOnGoal(4);            //set how many of the shots on target
    
    //test all the getters
    cout << sturridge.getName() << endl;
    cout << sturridge.getTeam() << endl;
    cout << sturridge.getGoals() << endl;
    cout << sturridge.getAssists() << endl;
    if(sturridge.getStart())
    {
        cout << "yes" << endl;
    }
    else{
        cout << "nope" << endl;
    }
    cout << sturridge.getShots() << endl;
    cout << sturridge.getShotsOnGoal() << endl;
    cout << sturridge.getShotPercentage() << endl;
    cout << sturridge.getOverall() << endl;
    
    //Test the input validation for the striker class
    sturridge.setShots(-3);
    cout << "\nNegative shots results in striker shots to be = " << sturridge.getShots() << endl;
    sturridge.setShots(3);
    cout << "Less shots taken than shots on net results in twice the shots on net = " << sturridge.getShots() << endl;
    sturridge.setShotsOnGoal(-5);
    cout << "Negative shots on goal results in  = " << sturridge.getShotsOnGoal() << endl;
    sturridge.setShotsOnGoal(16);
    cout << "More shots on net than shots taken results in  = " << sturridge.getShotsOnGoal() << "\n"<< endl;

    cout << "******************************************************************************" << endl;
    
    ///////////////////////////
    // Midfielder Class Test //
    ///////////////////////////
    cout << "Start to testing the FIFA_midfielder child class:\n\n" << endl;
    
    //create a midfielder fifa player
    //FIFA_midfielder coutinho = FIFA_midfielder();
    //cout << coutinho << "\n" << endl;
    
    
    ///////////////////////////
    // Defenseman Class Test //
    ///////////////////////////
    cout << "Start to testing the FIFA_defenseman child class:\n\n" << endl;
    
    //create a defenseman fifa player
    
    
    
    ///////////////////////
    // Goalie Class Test //
    ///////////////////////
    cout << "Start to testing the FIFA_goalie child class:\n\n" << endl;
    
    //create a goalie fifa player
    FIFA_goalie mignolet = FIFA_goalie();
    cout << mignolet << "\n" << endl;
    
    
    
    
    
    
    
    
    //put all the FIFA_players in a vector for pointer reference
    
    
    
    //Test the children by making a few players and
    //a goalie and iterating through the vector with
    //a pointer to the parent class calling a method
    
    

    
    
    
    //Done with testing
    cout << "\n\nEnd of Testing ... " << endl;
    
    cout << endl;
    return 0;
}








