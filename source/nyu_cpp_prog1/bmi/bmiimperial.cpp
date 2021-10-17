#include <iostream>
#include <iomanip>
using namespace std;

const float POUND_TO_KILO = 0.453592;
const float INCH_TO_METRIC = 0.0254;

int main()
{
    float weight, height;
    float weightMetric, heightMetric;
    
    cout << "Please enter weight in pounds: ";
    cin >> weight;
    cout << "Please enter height in inches: ";
    cin >> height;

    weightMetric = weight * POUND_TO_KILO;
    heightMetric = height * INCH_TO_METRIC;


    float bmi = weightMetric / (heightMetric * heightMetric);

    cout << "BMI is: " << setprecision(4) << bmi << endl;

    return 0;
}