/**
created by : cidi mohamed mostepha
link :https://codeforces.com/contest/544/problem/A
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
    int k;
    string s;
    cin >> k >> s;
    vector<int> rep(26, 0);
    vector<string> ans;
    int n = s.size();
    int dist = 0;
    int i;
    for (i = 0; i < n && dist < k;)
    {
        int j = i;
        rep[s[j] - 'a']++;
        ans.push_back("");
        dist++;
        ans.back() += s[j++];
        while (j < n)
        {
            if (rep[s[j] - 'a'] == 0)
            {
                break;
            }
            ans.back() += s[j];
            j++;
        }
        i = j;
    }

    if (dist == k)
    {
        while (i < n)
        {
            ans.back() += s[i];
            i++;
        }
        cout << "YES\n";
        for (string str : ans)
        {
            cout << str << '\n';
        }
    }
    else
    {
        cout << "NO\n";
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