#include <iostream>
using namespace std;

const int WORTH_OF_QUARTER = 25;
const int WORTH_OF_DIMES = 10;
const int WORTH_OF_NICKELS = 5;

int main()
{
    int dollars, cents;
    int quarters, dimes, nickels, pennies;
    int rest;

    cout << "Please enter the amount of money to convert:" << endl;
    cout << "# of dollars: ";
    cin >> dollars;
    cout << "# of cents: ";
    cin >> cents;

    int totalCents = (dollars * 100) + cents;

    if (totalCents > WORTH_OF_QUARTER)
    {
        quarters = totalCents / WORTH_OF_QUARTER;
        rest = totalCents % WORTH_OF_QUARTER;
    }
    else
    {
        quarters = 0;
    }

    if (rest > WORTH_OF_DIMES)
    {
        dimes = rest / WORTH_OF_DIMES;
        rest = rest % WORTH_OF_DIMES;
    }
    else
    {
        dimes = 0;
    }

    if (rest > WORTH_OF_NICKELS)
    {
        nickels = rest / WORTH_OF_NICKELS;
        rest = rest % WORTH_OF_NICKELS;
    }
    else
    {
        nickels = 0;
    }

    pennies = rest;
    
    cout << "The coins are " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies" << endl;   
    
    return 0;
}