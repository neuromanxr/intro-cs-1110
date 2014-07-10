#include <iostream>

/* Kelvin Lee Assignment 5 */

using namespace std;

int die1 = 0;
int die2 = 0;
int sumdie = 0;
int status = 2;


int outcome(int, int, int &);
void continu(int);


int main()
{
    while (status == 2)
    {
        cout << "Type in two integers between 1 and 6: " << endl;
        cin >> die1;
        cin >> die2;

        cout << "The two integers are: " << die1 << " and " << die2 << endl;
        sumdie = die1 + die2;
        outcome(die1, die2, status);
        //cout << status << endl;
        if (die1 == 2222 && die2 == 2222)
            break;
        switch (status)
        {
            case 0: cout << "You win!" << endl;
                    status = 2;
                break;
            case 1: cout << "You lose!" << endl;
                    status = 2;
                break;
            case 2: cout << "You must continue" << endl;
                    cout << "Sum is: " << sumdie << endl;
                    continu(sumdie);
                break;
        }


    }
    return 0;
}

int outcome(int die1, int die2, int & status)
{
    int sum = die1 + die2;
    if (sum == 7 || sum == 11)
    {

        return status = 0;
    }
    else if (sum == 2 || sum == 12)
    {

        return status = 1;
    }
    else

        return status = 2;
}


void continu(int sumdie)
{
    bool status = true;
    while (status)
    {
        int die1 = 0;
        int die2 = 0;
        cout << "Type in two integers between 1 and 6: " << endl;
        cin >> die1;
        cin >> die2;
        cout << "The two integers are: " << die1 << " and " << die2 << endl;
        int sum = die1 + die2;
        if (sum == 7)
        {
            cout << "You lose!" << endl;
            cout << "Sum is: " << sum << endl;
            cout << "Type 2222 for both integers to exit" << endl;
            status = false;
        }
        else if (sum == sumdie)
        {
            cout << "You win!" << endl;
            cout << "Sum is: " << sum << endl;
            cout << "Type 2222 for both integers to exit" << endl;
            status = false;
        }
        else
            cout << "Play again!" << endl;
    }

}
