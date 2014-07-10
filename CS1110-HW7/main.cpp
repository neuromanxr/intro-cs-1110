/*
CS1110 - Assignment 7

Kelvin Lee

*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void readData(string[], int[], int[], int[], int[]);
void analysis(int, string[], int[], int[], int[], int[]);

int main()
{
    int n = 15;  // 15 items
    //string line;
    string name[n];
    int first[n];
    int second[n];
    int third[n];
    int fourth[n];

    readData(name, first, second, third, fourth);

    analysis(n, name, first, second, third, fourth);

    ofstream outfile("outfile.txt");

    for(int i=0; i<n; i++)
    {
        outfile << first[i] << "  " << second[i] << endl;

    }

    //while(getline(items, line))
    //    cout << line << '\n';

    return 0;
}

void readData(string n[], int one[], int two[], int three[], int four[])
{
    //ifstream items;
    //items.open("datafile.txt");
    ifstream items("datafile.txt");

    for(int i=0; items >> n[i] >> one[i] >> two[i] >> three[i] >> four[i]; ++i);
}

void analysis(int n, string m[], int one[], int two[], int three[], int four[])
{
    int sum = 0;
    int grandTotal = 0;
    float average = 0;
    int firstHigh = 0;
    string firstHighName = " ";
    int secondHigh = 0;
    string secondHighName = " ";
    int thirdHigh = 0;
    string thirdHighName = " ";
    int fourthHigh = 0;
    string fourthHighName = " ";
    int filossValue = 0;
    int figainValue = 0;
    int fievenValue = 0;
    int selossValue = 0;
    int segainValue = 0;
    int seevenValue = 0;
    int thlossValue = 0;
    int thgainValue = 0;
    int thevenValue = 0;
    int folossValue = 0;
    int fogainValue = 0;
    int foevenValue = 0;
    string change = " ";
    cout << "ITEM     | " << "Q1 | " << "Q2 | " << "Q3 | " << "Q4 | " << "TOTAL PROFIT | " \
    << "AVERAGE PROFIT" << " | CHANGE" << endl;
    for(int i=0; i<n; i++)
    {
        sum = one[i] + two[i] + three[i] + four[i];
        grandTotal += sum;
        average = float(sum) / 4;

        if(one[i] > firstHigh)
        {
            firstHigh = one[i];
            firstHighName = m[i];
        }
        if(two[i] > secondHigh)
        {
            secondHigh = two[i];
            secondHighName = m[i];
        }
        if(three[i] > thirdHigh)
        {
            thirdHigh = three[i];
            thirdHighName = m[i];
        }
        if(four[i] > fourthHigh)
        {
            fourthHigh = four[i];
            fourthHighName = m[i];
        }

        if(one[i] < 0)
        {
            filossValue++;
        }
        else if(one[i] > 0)
            figainValue++;
        if(one[i] == 0)
            fievenValue++;

        if(two[i] < 0)
        {
            selossValue++;
        }
        else if(two[i] > 0)
            segainValue++;
        if(two[i] == 0)
            seevenValue++;

        if(three[i] < 0)
        {
            thlossValue++;
        }
        else if(three[i] > 0)
            thgainValue++;

        if(three[i] == 0)
            thevenValue++;

        if(four[i] < 0)
        {
            folossValue++;
        }
        else if(four[i] > 0)
            fogainValue++;
        if(one[i] == 0)
            foevenValue++;

        if(one[i] < two[i] && three[i] < four[i] && two[i] < three[i])
            change = "Increasing";
        else if(one[i] > two[i] && three[i] > four[i] && two[i] > three[i])
            change = "Decreasing";
        else if(one[i] > two[i] && three[i] < four[i])
            change = "Down and Up";
        else if(one[i] < two[i] && three[i] > four[i])
            change = "Up and Down";

        cout << setw(11) << left << m[i] << setw(5) << one[i] << setw(5) << two[i] << setw(5) << three[i] << setw(5) \
        << four[i] << setw(10) << right << sum << setw(16) << right << average << setw(15) << change << endl;
        change = "";    // Reset change each iteration
    }
    cout << endl;
    cout << "First quarter greatest: " << setw(10) << firstHighName << "  Profit: " << firstHigh \
    << "  Losses: " << filossValue << "  Gains: " << figainValue << "  Even: " << fievenValue << endl;
    cout << "Second quarter greatest: " << setw(10) << secondHighName << "  Profit: " << secondHigh \
    << "  Losses: " << selossValue << "  Gains: " << segainValue << "  Even: " << seevenValue << endl;
    cout << "Third quarter greatest: " << setw(10) << thirdHighName << "  Profit: " << thirdHigh \
    << "  Losses: " << thlossValue << "  Gains: " << thgainValue << "  Even: " << thevenValue << endl;
    cout << "Fourth quarter greatest: " << setw(10) << fourthHighName << "  Profit: " << fourthHigh \
    << "  Losses: " << folossValue << "  Gains: " << fogainValue << "  Even: " << foevenValue << endl;
    cout << "Profit grand total: " << grandTotal << endl;
}
