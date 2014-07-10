#include <iostream>
#include <iomanip>

using namespace std;

int gamesPlayed(int&, int&);
float winPercent(int, int);
void seasonOver(int);
void gamesAB500(int, int);

char input = 'y';
int teamID = 0000;
int wins = 0;
int losses = 0;
int counter = 0;

int main()
{
    while(input == 'y')
    {
        cout << "Enter team ID number: " << endl;
        cin >> teamID;
        cout << "Enter number of wins: " << endl;
        cin >> wins;
        cout << "Enter number of losses: " << endl;
        cin >> losses;

        cout << "Team: " << teamID << endl;
        cout << wins << " wins" << "   " << losses << " losses" << endl;
        int numberOfGames = gamesPlayed(wins, losses);
        cout << "Total number of games played: " << numberOfGames << endl;
        seasonOver(numberOfGames);
        cout << "The winning percentage is: " << std::setprecision(5) << winPercent(wins, numberOfGames) << endl;
        gamesAB500(wins, losses);
        counter += 1;
        cout << "Continue input? Enter y or n: " << endl;
        cin >> input;
        cout << endl;
        cout << endl;
        cout << endl;
    }
    cout << "Total number of teams in the league is: " << counter << endl;
    return 0;
}


int gamesPlayed(int& gameWins, int& gameLosses)
{
    int result = gameWins + gameLosses;
    return result;
}

void seasonOver(int numberOfGames)
{
    int gamesLeft = 0;
    if (numberOfGames == 20)
        cout << "The season is finished." << endl;
    else
    {
        gamesLeft = 20 - numberOfGames;
        cout << "The number of games left is: " << gamesLeft << endl;
    }
}

float winPercent(int gameWins, int numberOfGames)
{
    float result = float(gameWins) / numberOfGames;
    return result;
}

void gamesAB500(int wins, int losses)
{
    int gamesAB = 0;
    if (wins >= losses)
    {
        gamesAB = wins - losses;
        cout << "The team is " << gamesAB << " games" << " above 0.50000" << endl;
    }
    else
    {
        gamesAB = losses - wins;
        cout << "The team is " << gamesAB << " games" << " below 0.50000" << endl;
    }
}
