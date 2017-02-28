//
//  main.cpp
//  Project2
//
//  Created by Collin on 2/8/17.
//  Copyright © 2017 Collin. All rights reserved.
//
/*
 
 MY PROGRAM -
 
 This is a program to test the FIFA class. The class is designed 
 to hold information about a FIFA soccer player and then it 
 calculates the overall value of the player on a scale of 100. 
 It calculates this based on the goals, assists, and whether the 
 player starts or is a sub.
 
 Overloaded operaors were implemented to compare players 
 overall ratings.
 
 * These are also all stats in a given year. So typically a
 player doesnt score more than 20 goals or assists in a season 
 but the stats are made to support this.
 No player can actually hit a perfect score because no player 
 is perfect on the pitch. So the min is 65 and the max score 
 is set at 95, even though its on a scale of 0-100.
 
 Setters will only allow the expected input to be submitted as 
 parameter, but as for the setAssists and setGoals you can pass
 a double but it will be truncated. If you submit anything 
 negative then the player doesnt recieve any positive points 
 for goals or assists in their overall rating. (tested below)
 
 */

#include <iostream>
#include "FIFA.hpp"
using namespace std;

int main() {
    
    //Testing all constructors:
    //default
    cout << "Constructor Testing" << endl;
    FIFA_player collin = FIFA_player();
    cout << collin << endl;
    cout << endl;
    //just name
    FIFA_player ct1 = FIFA_player("Collin Turner");
    cout << ct1 << endl;
    cout << endl;
    //name and goals
    FIFA_player ct2 = FIFA_player("Collin Turner", 12);
    cout << ct2 << endl;
    cout << endl;
    //name and goals and assists
    FIFA_player ct3 = FIFA_player("Collin Turner", 12, 8);
    cout << ct3 << endl;
    cout << endl;
    //name and goals and assists and team name
    FIFA_player ct4 = FIFA_player("Collin Turner", 12, 8, "Liverpool FC");
    cout << ct4 << endl;
    cout << endl;
    //name and goals and assists and team name and whether player starts on the field (all fields)
    FIFA_player ct5 = FIFA_player("Collin Turner", 12, 8, "Liverpool FC", false);
    cout << ct5 << endl;
    cout << endl;
    
    cout << "**********************" << endl;
    
    //test all of the getters
    cout << "Getters Testing\n" << endl;
    cout << "getName - " << ct5.getName() << endl;
    cout << "getTeam - " << ct5.getTeam() << endl;
    cout << "getGoals - " << ct5.getGoals() << endl;
    cout << "getAssists - " << ct5.getAssists() << endl;
    string st;
    if(ct5.getStart() == 1)
    {
        string st = "Yes";
    }
    else
    {
        st = "No";
    }
    cout << "getStart - " << st << endl;
    cout << "getOverall - " << ct5.getOverall() << endl;
    cout << endl;
    
    cout << "**********************" << endl;
    
    //test all of the setters
    cout << "Setters Testing\n" << endl;
    cout << "setName - Lionel Messi" << endl;
    ct5.setName("Lionel Messi");
    cout << "setTeam - Barcelona FC" << endl;
    ct5.setTeam("Barcelona FC");
    cout << "setGoals - 24" << endl;
    ct5.setGoals(24);
    cout << "setAssists - 16" << endl;
    ct5.setAssists(16);
    cout << "setStart - true" << endl;
    ct5.setStart(true);
    cout << "\n" << ct5 << endl;
    
    //Test incorrect inputs
    ct5.setGoals(-5422);
    cout << "\n" << ct5 << endl;
    ct5.setAssists(-293);
    cout << "\n" << ct5 << endl;
    ct5.setGoals(5.5);
    cout << "\n" << ct5 << endl;
    cout << endl;
    
    cout << "********************************" << endl;
    
    //test the operator to compare overall rating of two FIFAplayers
    cout << "Compare overall rating of Ronaldo vs Messi\n" << endl;
    FIFA_player ronaldo = FIFA_player("Christiano Ronaldo", 19, 25, "Real Madrid", true);
    FIFA_player messi = FIFA_player("Lionel Messi", 21, 16, "Barcelona FC", true);
    
    cout << "Messi Overall   : " << messi.getOverall() << endl;
    cout << "Ronaldo Overall : " << ronaldo.getOverall() << endl;
    
    if(messi > ronaldo)
    {
        cout << "\nMessi is better than Ronaldo" << endl;
    }
    else
    {
        cout << "\nRonaldo is better than Messi, but that's just not possible..." << endl;
    }
    
    //Done testing
    cout << "\n\nEnd of Testing ... " << endl;
    
    cout << endl;
    return 0;
}
