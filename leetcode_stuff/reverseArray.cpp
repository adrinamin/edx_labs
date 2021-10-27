#include <iostream>
#include <vector>

std::vector<int> reverseArray(std::vector<int> a) {
    int size_a = a.size();
    std::vector<int> n;
    int end = size_a - 1;
    for (int i = 0; i < size_a; i++)
    {
        n.insert(a.begin(), a[end - i]);
    }
    return n;
}

int main()
{
    std::vector<int> a{1,4,3,2};
    // std::cout << a[0] << a[1] << a[2] << a[3] << std::endl;
    // int size_a = sizeof(a) / sizeof(a[0]);
    // int n[4];
    // int end = size_a - 1;
    // for (int i = 0; i < size_a; i++)
    // {
    //     n[i] = a[end - i];
    // }

    // std::cout << n[0] << n[1] << n[2] << n[3] << std::endl;

    int n[4];
    std::vector<int> result = reverseArray(a);    
    return 0;
}