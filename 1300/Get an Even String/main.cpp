#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    string s;
    cin >> s;
    vector<int> rep(26 , 0);
    int ans = 0;
    for(int i = 0 ; i < s.size() ; i++) {
        if(rep[s[i] - 'a'] == 0) {
            rep[s[i] - 'a']++;
        } else {
            ans++;
            for(int j = 0 ; j < 26 ; j++) rep[j] = 0;
        }
    }

    cout << s.size() - ans * 2 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
     cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}