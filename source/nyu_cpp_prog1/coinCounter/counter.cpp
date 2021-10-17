#include <iostream>
using namespace std;

const int WORTH_OF_QUARTER = 25;
const int WORTH_OF_DIMES = 10;
const int WORTH_OF_NICKELS = 5;



int main()
{
    int quarters, dimes, nickels, pennies;

    cout << "Please enter the number of coins: " << endl;
    cout << "# of quarters: ";
    cin >> quarters;

    cout << "# of dimes: ";
    cin >> dimes;

    cout << "# of nickels: ";
    cin >> nickels;

    cout << "# of pennies: ";
    cin >> pennies;

    int sumInCents = (quarters * WORTH_OF_QUARTER) + (dimes * WORTH_OF_DIMES) + (nickels * WORTH_OF_NICKELS) + pennies;
    int cents = sumInCents % 100;
    int dollars = (sumInCents - cents) / 100;
    
    
    cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;


    return 0;
}