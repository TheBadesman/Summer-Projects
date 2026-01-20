/*
Unit tests for RPI project
*/

//importing libraries
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

//setting the namespace for the file
using namespace std;

//importing the file to test and the testing library
#include "test.h"
#include "RPI.h"

int main(){
    //creating vectors and weight for testing
    vector<teams> league;
    weight percent;

    //creating a team for testing proper calcuations of total games and win loss
    teams tester; tester.name = "A"; tester.wins = 22; tester.loses = 3; tester.totalGames(); tester.winLoss(); 
    test_(tester.games == 25);
    test_(tester.record == 0.88f);
    league.push_back(tester);

    //testing setPercent
    setPercent(percent);
    

    report_();
}