//
//  jan24.cpp
//  CS120
//
//  Created by Collin on 1/24/17.
//  Copyright © 2017 Collin. All rights reserved.
//
/*
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

int main() {
    
    double pi = 3.14159265;
    cout << pi << endl;
    cout << fixed << setprecision(7);
    cout << pi << endl;
    double bob = 42;
    cout << scientific << bob << endl;
    
    vector<string> chapter_titles = {"Characters", "Plot", "Horcruxes"};
    vector<int> page_numbers = {1, 33, 431};
    cout << "   Harry Potter   " << endl; // 18 characters long
    
    cout << setfill('.');
    for (int i = 0; i < chapter_titles.size(); ++i) {
        cout << chapter_titles[i];
        cout << setw(int(18) - chapter_titles[i].length()) << page_numbers[i];
        cout << endl;
    }
    
    
     ifstream in_file("example_file.txt");
     if (in_file) {
     int bob;
     in_file >> bob;
     string junk;
     getline(in_file, junk);
     string message;
     getline(in_file, message);
     char letter;
     in_file >> letter;
     cout << "bob: " << bob << endl;
     cout << "message: " << message << endl;
     cout << "letter: " << letter << endl;
     }
     */
    /*
     ofstream out_file("example_file.txt");
     if (out_file) {
     out_file << 42 << endl;
     out_file << "Hello, World!\n";
     out_file << 'q' << endl;
     }
     out_file.close();
     */
    /*
     vector<int> myInts;
     myInts.push_back(3);
     myInts.push_back(5);
     myInts.push_back(0);
     for (int i = 0; i < myInts.size(); ++i) {
     cout << myInts[i] << endl;
     }
     
     myInts.erase(myInts.begin() + 1);
     
     cout << "After erase: " << endl;
     for (int i = 0; i < myInts.size(); ++i) {
     cout << myInts[i] << endl;
     }
     
     myInts.pop_back();
     cout << "After pop:" << endl;
     for (int i = 0; i < myInts.size(); ++i) {
     cout << myInts[i] << endl;
     }
     
     // 2D vector
     vector<vector<bool> > myBools;
     vector<bool> tempBool = {0, 1, false};
     myBools.push_back(tempBool);
     cout << "The middle element in my 2D vector: ";
     cout << myBools[0][1] << endl;
     cout << "The last element in my 2D vector: ";
     cout << myBools[0][2] << endl;
     */
    /*
    
    return 0;
}*/
