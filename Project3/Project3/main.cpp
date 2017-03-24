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
    cout << "\n          TESTING PROJECT 5 - C++" << endl;
    cout << "********************************************\n" << endl;
    
    ////////////////////////
    // Striker Class Test //
    ////////////////////////
    cout << "Start to testing the FIFA_striker child class:\n" << endl;
    
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
    cout << "More shots on net than shots taken results in  = " << sturridge.getShotsOnGoal() << endl;
    
    //reset the shots and sog for future use with striker obj
    sturridge.setShots(6);
    sturridge.setShotsOnGoal(4);
    
    //print everything to console:
    cout << "\n" << sturridge << "\n" << endl;

    cout << "******************************************************************************" << endl;
    
    ///////////////////////////
    // Midfielder Class Test //
    ///////////////////////////
    cout << "Start to testing the FIFA_midfielder child class:\n" << endl;
    
    //create a midfielder fifa player
    FIFA_midfielder coutinho = FIFA_midfielder();
    cout << coutinho << "\n" << endl;
    
    //test all the setters
    coutinho.setName("Philippe Coutinho"); //set name
    coutinho.setTeam("Liverpool FC");      //set teams name
    coutinho.setGoals(11);                 //set season long goals
    coutinho.setAssists(22);               //set season long assists
    coutinho.setStart(true);               //set starting on the field
    coutinho.setPlayCreations(9);          //set play creations - average per game stat
    coutinho.setThroughBalls(14);          //set how many of the through balls on ave pg
    
    //test all the getters
    cout << coutinho.getName() << endl;
    cout << coutinho.getTeam() << endl;
    cout << coutinho.getGoals() << endl;
    cout << coutinho.getAssists() << endl;
    if(coutinho.getStart())
    {
        cout << "yes" << endl;
    }
    else{
        cout << "nope" << endl;
    }
    cout << coutinho.getPlayCreations() << endl;
    cout << coutinho.getThroughBalls() << endl;
    cout << coutinho.getOverall() << endl;
    
    //Test the input validation for the new midfielder functions
    coutinho.setPlayCreations(-9);
    cout << "\nNegative plays created results in = " << coutinho.getPlayCreations() << endl;
    coutinho.setThroughBalls(-12);
    cout << "Negative through balls will result in = " << coutinho.getThroughBalls() << endl;
    
    //reset the shots and sog for future use with striker obj
    coutinho.setPlayCreations(9);
    coutinho.setThroughBalls(14);
    
    //print everything to console:
    cout << "\n" << coutinho << "\n" << endl;

    cout << "******************************************************************************" << endl;
    
    ///////////////////////////
    // Defenseman Class Test //
    ///////////////////////////
    cout << "Start to testing the FIFA_defenseman child class:\n" << endl;
    
    //create a defenseman fifa player
    //create a goalie fifa player
    FIFA_defenseman milner = FIFA_defenseman();
    cout << milner << "\n" << endl;
    
    //test all the setters
    milner.setName("James Milner");     //set name
    milner.setTeam("Liverpool FC");     //set teams name
    milner.setGoals(9);                 //set season long goals
    milner.setAssists(4);               //set season long assists
    milner.setStart(true);              //set starting on the field
    milner.setTackles(9);               //set play creations - average per game stat
    milner.setInterceptions(13);        //set how many of the through balls on ave pg
    
    //test all the getters
    cout << milner.getName() << endl;
    cout << milner.getTeam() << endl;
    cout << milner.getGoals() << endl;
    cout << milner.getAssists() << endl;
    if(milner.getStart())
    {
        cout << "yes" << endl;
    }
    else{
        cout << "nope" << endl;
    }
    cout << milner.getTackles() << endl;
    cout << milner.getInterceptions() << endl;
    cout << milner.getOverall() << endl;
    
    //Test the input validation for the new midfielder functions
    milner.setTackles(-27);
    cout << "\nNegative tackles will results in = " << milner.getTackles() << endl;
    milner.setInterceptions(-19);
    cout << "Negative interceptions will result in = " << milner.getInterceptions() << endl;
    
    //reset the shots and sog for future use with striker obj
    milner.setTackles(9);
    milner.setInterceptions(13);
    
    //print everything to console:
    cout << "\n" << milner << "\n" << endl;
    
    cout << "******************************************************************************" << endl;
    
    ///////////////////////
    // Goalie Class Test //
    ///////////////////////
    cout << "Start to testing the FIFA_goalie child class:\n" << endl;
    
    //create a goalie fifa player
    FIFA_goalie mignolet = FIFA_goalie();
    cout << mignolet << "\n" << endl;
    
    //test all the setters
    mignolet.setName("Simon Mignolet");     //set name
    mignolet.setTeam("Liverpool FC");       //set teams name
    mignolet.setGoals(0);                   //set season long goals
    mignolet.setAssists(1);                 //set season long assists
    mignolet.setStart(true);                //set starting on the field
    mignolet.setSaves(9);                   //set play creations - average per game stat
    mignolet.setGoalsAgainst(2);            //set how many of the through balls on ave pg
    
    //test all the getters
    cout << mignolet.getName() << endl;
    cout << mignolet.getTeam() << endl;
    cout << mignolet.getGoals() << endl;
    cout << mignolet.getAssists() << endl;
    if(mignolet.getStart())
    {
        cout << "yes" << endl;
    }
    else{
        cout << "nope" << endl;
    }
    cout << mignolet.getSaves() << endl;
    cout << mignolet.getGoalsAgainst() << endl;
    cout << mignolet.getOverall() << endl;
    
    //Test the input validation for the new midfielder functions
    mignolet.setSaves(-7);
    cout << "\nNegative saves created results in = " << mignolet.getSaves() << endl;
    mignolet.setGoalsAgainst(-11);
    cout << "Negative goals against will result in = " << mignolet.getGoalsAgainst() << endl;
    
    //reset the shots and sog for future use with striker obj
    mignolet.setSaves(9);
    mignolet.setGoalsAgainst(2);
    
    //print everything to console:
    cout << "\n" << mignolet << "\n" << endl;
    
    cout << "******************************************************************************" << endl;

    /////////////////////////////
    // Pointers to Parent Test //
    /////////////////////////////
    cout << "Start to testing vector of pointers to parent class:\n" << endl;
    
    //put all the FIFA_players in a vector - unique ptrs
    cout << "... Creating a unique_ptr vector to hold the child class pointers" << endl;
    vector<unique_ptr<FIFA_player>> team;
    
    //add all the pointers to the vector
    cout << "... Adding child pointers to vector" << endl;
    team.push_back(unique_ptr<FIFA_striker>(&sturridge));
    team.push_back(unique_ptr<FIFA_midfielder>(&coutinho));
    team.push_back(unique_ptr<FIFA_defenseman>(&milner));
    team.push_back(unique_ptr<FIFA_goalie>(&mignolet));
    
    //loop and print result
    cout << "... Looping in vector calling parent function\n" << endl;
    /**
     get the overall rating of each of the players by looping through a child call to the abstract class
     Its calling a get method, the field is calculated for each object in the child class,
     but calling the abstract's getmethod for the field.
    */
    for (int i = 0; i < team.size(); ++i)
    {
        cout << team[i]->getName() << "'s overall rating: " << team[i]->getOverall() << endl;
        team[i].release();
    }

    
    //Done with testing
    cout << "\n\nEnd of Testing ... " << endl;
    
    cout << endl;
    return 0;
}








