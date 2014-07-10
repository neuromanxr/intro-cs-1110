/*
CS1110 - Assignment 6

Kelvin Lee

*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void readdata(int, int[], int[]);
void printarray(int, int[]);
float average(int, int[]);
void addonto(int, int[], int[], int[]);

int main()
{
    ifstream Size;
    Size.open("datafile.txt");  // Has 31 lines of data

    int n = 0;
    Size >> n;
    int first[n];
    int second[50];

    readdata(n, first, second);     // Reads in all 31 lines of data but using only 12 lines of data
    cout << "Printing first array: " << endl;
    cout << endl;

    printarray(12, first);     // Prints the first 12 lines of data only
    cout << endl;
    cout << endl;

    cout << "Printing second array: " << endl;
    cout << endl;

    printarray(12, second);
    cout << endl;
    cout << endl;

    cout << "The average of the first array: " << endl;
    cout << endl;
    cout << average(12, first);     // Averages the first 12 lines of data only
    cout << endl;
    cout << endl;
    cout << "The average of the second array: " << endl;
    cout << endl;
    cout << average(12, second);
    cout << endl;
    cout << endl;

    cout << "Second array added to the first array: " << endl;
    addonto(12, first, second, first);
    printarray(24, first);

    cout << endl;
    cout << endl;

    cout << "First array added to the second array: " << endl;
    addonto(12, second, first, second);
    printarray(24, second);

    cout << endl;
    cout << endl;
    cout << "The average of the new first array: " << endl;
    cout << endl;
    cout << average(24, first);
    cout << endl;
    cout << endl;
    cout << "The average of the new second array: " << endl;
    cout << endl;
    cout << average(24, second);
    cout << endl;
    cout << endl;

    return 0;
}

void readdata(int n, int numb1[], int numb2[])
{
    ifstream Size;
    Size.open("datafile.txt");
    for(int i=0; i<n; i++)  // First line in data file "31" determines how many lines of data to read
    {
        Size >> numb1[i] >> numb2[i];
    }
}

void printarray(int q, int numb[])
{
    for(int i=1; i<=q; i++)   // Skips the first line because "31" is lines of data in each column
    {
        cout << numb[i] << "  ";
        if(i%5==0)
            cout << endl;
    }
}

float average(int k, int p[])
{
    float result = 0.0;
    int sum = 0;
    for(int i=1; i<=k; i++)
    {
        sum += p[i];
    }
    result = float(sum) / k;
    return result;
}

void addonto(int m, int r[], int s[], int t[])
{
    int u = m+1;    // Starts the assignment at the end of the array
    for(int i=1; i<=m; i++)
    {
        t[i] = r[i];
        t[u] = s[i];
        u++;
    }
}
