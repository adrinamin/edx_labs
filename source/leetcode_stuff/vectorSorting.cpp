#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int len;
    vector<int> v;
    cin >> len;
    for (int i = 0; i<len; i++) {
        int var;
        cin >> var;
        v.push_back(var);
    }
    
    sort(v.begin(),v.end()); 
    
    for (int i = 0; i<len; i++) {
        cout << v[i];
    }
    
    return 0;
}