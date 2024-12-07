#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
    string s;
    int n;
    char ch;
    cin >> n >> ch >> s;
    
    int cnt = 0;
    for(char lt : s) {
        cnt += (lt == ch);
    }
    if(cnt == n) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        bool okey = true;
        for (int j = i; j <= n; j += i)
        {
            if (s[j - 1] != ch)
            {
                okey = false;
                break;
            }
        }
        if (okey)
        {
            cout << "1\n"
                 << i << '\n';
            return;
        }
    }
    
    cout << "2\n" << n << ' ' << n - 1 << '\n';
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