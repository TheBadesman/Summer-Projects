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

//namespace
using namespace std;

//struct to make storing the infomation about the teams easier
struct teams
{
    string name;
    int wins;
    int loses;

    int total_games(){
        return wins + loses;
    }

    float winloss(){
        return static_cast<double>(wins) / total_games();
    }

};


int main()
{
    //the vector to hold all the teams in the league and the string to hold the ints before we convert them
    vector<teams> league;
    string convertor;
    string finished;

    cout << "Enter in all the information asked. When there are no more teams to add, enter done.\n";

    while (true)
    {
        //a vector to hold the team while we grab all the needed input
        teams holder;
        
        //Getting the name, and checking if it is the last one
        cout << "Enter the teams name: ";

        getline(cin, holder.name); cout << '\n';

        for (char &c : holder.name) {c = toupper(c);}

        if (finished == "done") { break; }

        //Getting the number of wins and losses, then convertering them to ints
        cout << "Enter the number of wins: "; getline(cin, convertor); cout << '\n'; holder.wins = stoi(convertor);
        cout << "Enter the number of losses: "; getline(cin, convertor); cout << '\n'; holder.loses = stoi(convertor);

        league.push_back(holder);

    }
    
    return 0;
}
