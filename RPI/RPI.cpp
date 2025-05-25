/*
Summer Project Number One

Creating a player rating index calculator, which takes
input from the user and uses it to rate a rank players
*/

//Includes for this project
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std; //namespace

struct teams //struct to make storing the infomation about the teams easier
{
    string name;
    int wins;
    int loses;
    double games;
    float record;
    float schStr;
    float oppStr;

    void totalGames(){
        games = wins + loses;
    }

    void winLoss(){
        record = wins / games;
    }
};

struct weight //struct to see the weight of each area
{
    float winWeight;
    float strength;
    float opponents;
};



int main()
{
    //the vector to hold all the teams in the league and the string to hold the ints before we convert them
    vector<teams> league;
    weight percent;
    string convertor;
    double str;

    //Gets input form the user to know the weight of each category
    while (true) {
        cout << "Enter the weight of each category as a whole number\n\n";

        cout << "Win/Loss: "; getline(cin, convertor); percent.winWeight = stof(convertor) / 100;
        cout << "Strength of their schedule: "; getline(cin, convertor); percent.strength = stof(convertor) / 100;
        cout << "Strength of their opponents schedule: "; getline(cin, convertor); percent.opponents = stof(convertor) / 100;

        cout << "-------------------------"; //Printing a buffer to help with readability

        if (percent.winWeight + percent.strength + percent.opponents == 1) { break; }
        
        cout << "Sorry, the weight you added does not equal 100. Please try again\n";
    }

    cout << "\nEnter in all the information asked. When there are no more teams to add, enter done.\n";

    while (true) {
        teams holder; //a vector to hold the team while we grab all the needed input
        
        //Getting the name, and checking if it is the last one
        cout << "\nEnter the teams name (Or done if you are finished): "; getline(cin, holder.name);
        for (char &c : holder.name) {c = toupper(c);}
        if (holder.name == "DONE") { cout << "\n-------------------------\n"; break; }

        //Getting the number of wins and losses, then convertering them to ints
        cout << "Enter the number of wins: "; getline(cin, convertor);  holder.wins = stoi(convertor);
        cout << "Enter the number of losses: "; getline(cin, convertor);  holder.loses = stoi(convertor);

        cout << "\n-------------------------\n"; //Printing a buffer to help with readability

        //calculating the win/loss percentage and total games of the team
        holder.totalGames();
        holder.winLoss();

        league.push_back(holder); //Adding the team to the vector
    }

    for (size_t i = 0; i < league.size(); i++)
    {
        str = 0; //Reseting Str

        for (size_t v = 0; v < league.size(); v++)
        {
            if (i != v)
            {
                str += league[v].record; //adding the record of each team to the Str variable
            }
        }
        
        league[i].schStr = str / league.size(); //calculating the Schedule strength and adding it to the Struct stored in the vector
    }

    for (size_t i = 0; i < league.size(); i++)
    {
        str = 0; //Reseting Str

        for (size_t v = 0; v < league.size(); v++)
        {
            if (i != v)
            {
                str += league[v].schStr;
            }
        }
        
        league[i].oppStr = str / league.size(); //calculating the Schedule strength and adding it to the Struct stored in the vector
    }

    //Printing the RPI for every team in the Vector League
    for (size_t i = 0; i < league.size(); i++)
    {
        cout << '\n' << league[i].name << "'s Win/Loss is " << league[i].record << "\nTheir Schedule Strength was " << league[i].schStr;
        cout << "\nTheir Opponents Schedule Strenght was " << league[i].oppStr << "\nfor a total RPI of ";
        cout << league[i].record * percent.winWeight + league[i].schStr * percent.strength + league[i].oppStr * percent.opponents;
        cout << "\n-------------------------\n";
    }

    return 0;
}