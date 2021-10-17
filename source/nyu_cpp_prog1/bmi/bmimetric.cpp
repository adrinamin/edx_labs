#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float weight, height;
    cout << "Please enter weight in kilograms: ";
    cin >> weight;
    cout << "Please enter height in meters: ";
    cin >> height;

    float bmi = weight / (height * height);

    cout << "BMI is: " << setprecision(4) << bmi << endl;

    return 0;
}