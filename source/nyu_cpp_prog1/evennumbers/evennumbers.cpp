#include <iostream>
using namespace std;

const int ITERATION = 2;

int main()
{
    int n;
    cout << "Please enter a positive integer: ";
    cin >> n;
    int limit = n * ITERATION;

    for (int i = 0; i <= limit; i+=ITERATION)
    {
        if (i == 0)
        {
            continue;
        }
        
        cout << i << endl;
    }

    return 0;   

}