#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int temp = atoi(argv[1]);

    if (temp % 4 != 0)
    {
        cout << argv[1] << " was not a leap year" << endl;
    }
    else if (temp % 100 != 0)
    {
        cout << argv[1] << " was a leap year" << endl;
    }
    else if (temp % 400 != 0)
    {
        cout << argv[1] << " was not a leap year" << endl;
    }
    else
    {
       cout << argv[1] << " was a leap year" << endl;
    }

    return 0;
}