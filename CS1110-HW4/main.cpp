#include <iostream>
#include <iomanip>

/* Kelvin Lee Assignment 4 */

using namespace std;

int athleteID = 0;
int judges = 0;
float scores = 0.0;
float sumScores = 0.0;
char input = 'y';
float hiScore = 0.0;
float loScore = 0.0;
int hiAthlete = 0;
float hiAverage = 0.0;
float averageScore = 0.0;

float average(float, int);

int main()
{
    while (input == 'y')
    {
        cout << "Enter athlete ID: " << endl;
        cin >> athleteID;
        cout << "Enter number of judges: " << endl;
        cin >> judges;
        for (int i = 1; i <= judges; i++)
        {
            cout << "Enter score: " << endl;
            cin >> scores;
            if (i == 1)
            {
                hiScore = scores;
                loScore = scores;
            }
            else
            {
                if (scores > hiScore)
                {
                    hiScore = scores;
                }
                else if (scores < loScore)
                {
                    loScore = scores;
                }
            }
            sumScores += scores;
            //cout << sumScores << endl;
            //cout << "Low " << loScore << " High " << hiScore << endl;
        }

        sumScores = sumScores - hiScore - loScore;
        averageScore = average(sumScores, judges);
        //cout << sumScores << endl;
        cout << "Athlete ID: " << athleteID << endl;
        cout << "The average score is: " << setprecision(4) << averageScore << endl;
        if (averageScore > hiAverage)
        {
            hiAverage = averageScore;
            hiAthlete = athleteID;
        }
        //cout << "The highest average is athlete: " << hiAthlete << " with an average of: " << hiAverage << endl;
        cout << endl;
        cout << endl;
        cout << "Continue input? Enter y or n: " << endl;
        cin >> input;
        sumScores = 0;
        hiScore = 0;
        loScore = 0;
    }
    cout << endl;
    cout << "The highest average is athlete: " << hiAthlete << " with an average of: " << hiAverage << endl;
    return 0;
}

float average(float sumScores, int judges)
{
    float result = 0;
    result = sumScores / (judges - 2);
    return result;
}
