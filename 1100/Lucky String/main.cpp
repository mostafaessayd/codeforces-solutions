/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/110/problem/B
 rating : 1100
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
    int n;
    cin >> n;
    for (int i = 0; i < n / 4; i++)
    {
        cout << "abcd";
    }

    char ch = 'a';
    for (int i = 0; i < n % 4; i++)
    {
        cout << ch++;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        answer();
    }
    return 0;
}