/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/147/problem/A
rating : 1300
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer()
{
    string s = "";
    char ch;
    bool sp = false;
    while (ch = getchar())
    {
        if (ch == '\n')
        {
            break;
        }
        if (ch == ' ')
        {
            if (sp == false)
            {
                s += ' ';
            }
            sp = true;
        }
        else
        {
            sp = false;
            s += ch;
            if (!isalpha(ch))
            {
                s += ' ';
            }
        }
    }

    if (s.front() == ' ')
    {
        s.erase(s.begin());
    }

    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == ' ' && !isalpha(s[i + 1]))
        {
            continue;
        }
        cout << s[i];
    }

    cout << s.back();
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