/*
Summer Project Number One CPP

Main to run the compiled code
*/

//Includes for this project
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iomanip>

//Importing the header file
#include "RPI.h"

using namespace std; //namespace

int main()
{
    //the vector to hold all the teams in the league and the string to hold the ints before we convert them
    vector<teams> league;
    weight percent;

    setPercent(percent);
    getTeams(league);
    calSchStr(league);
    calOppStr(league);
    printRPI(percent, league);

    return 0;
}