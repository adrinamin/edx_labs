#include <iostream>
using namespace std;

int main()
{
    int value1, value2, value3, value4;
    int even = 0, odd = 0;
    cout << "Please enter 4 positive integers, separated by a space: " << endl;
    cin >> value1 >> value2 >> value3 >> value4;

    if (value1 % 2 == 0)
    {
        even++;
    }
    else
    {
        odd++;
    }

    if (value2 % 2 == 0)
    {
        even++;
    }
    else
    {
        odd++;
    }

    if (value2 % 2 == 0)
    {
        even++;
    }
    else
    {
        odd++;
    }

    if (value2 % 2 == 0)
    {
        even++;
    }
    else
    {
        odd++;
    }

    if (even > odd)
    {
        cout << "more evens" << endl;
    }
    else if (even < odd)
    {
        cout << "more odds" << endl;
    }
    else
    {
        cout << "same number of evens and odds" << endl;
    }

    return 0;
}