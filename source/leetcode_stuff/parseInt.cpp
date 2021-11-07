#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    for (int i = 0; i < str.length(); i++) {
        if (str[i] ==  ',')
        {
            str[i] = ' ';
        }
    }
    
    stringstream ss(str);
    int number;
    char ch;
    vector<int> parsedInts;
    while (ss >> number) {
        parsedInts.push_back(number);
    }
    
    return parsedInts;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

