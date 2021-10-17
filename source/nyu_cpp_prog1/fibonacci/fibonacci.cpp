#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please enter a positive integer greater than 1: ";
    cin >> n;

    int value1 = 0, value2 = 1;
    int output = 0;
    
    cout << value2 << endl;
    for (int i = 0; i < n-1; i++)
    {
        output = value1 + value2;
        cout << output << endl;
        value1 = value2;
        value2 = output;
    }
    
    return 0;
}