#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, helper;
    string line = "";
    cin >> n;
    vector<int> v(n);
    while(cin >> helper, line.length() != 0){
        cin >> helper;
        v.push_back(helper);
        getline(cin, line);
    }
    
    sort(v.begin(), v.end());
    
    for (const int& j : v) {
        cout << j << " ";
    }

    return 0;
}