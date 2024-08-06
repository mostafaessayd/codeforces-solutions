/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1234/problem/D
rating : 1600
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5;

vector<int> src[4 * N];

void build(string &s, int l, int r, int pos)
{
    vector<int> rep(26, 0);
    if (l == r)
    {
        rep[s[l] - 'a']++;
        src[pos] = rep;
        return;
    }

    int mid = (l + r) / 2;
    build(s, l, mid, pos * 2);
    build(s, mid + 1, r, pos * 2 + 1);
    vector<int> rep1 = src[pos * 2];
    vector<int> rep2 = src[pos * 2 + 1];
    for (int i = 0; i < 26; i++)
    {
        rep[i] = rep1[i] + rep2[i];
    }
    src[pos] = rep;
}

vector<int> get(int l, int r, int a, int b, int pos)
{
    vector<int> rep(26, 0);
    if (a > r || l > b)
    {
        return rep;
    }

    if (l >= a && b >= r)
    {
        return src[pos];
    }

    int mid = (l + r) / 2;
    vector<int> rep1 = get(l, mid, a, b, pos * 2);
    vector<int> rep2 = get(mid + 1, r, a, b, pos * 2 + 1);

    for (int i = 0; i < 26; i++)
    {
        rep[i] = rep1[i] + rep2[i];
    }

    return rep;
}

int getAnswer(vector<int> &dest)
{
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += (dest[i] > 0 ? 1 : 0);
    }
    return ans;
}

void update(string &s, int l, int r, int ind, char ch, int pos)
{
    vector<int> rep(26, 0);
    if (l == r)
    {
        rep[ch - 'a']++;
        s[ind] = ch;
        src[pos] = rep;
        return;
    }

    int mid = (l + r) / 2;
    if (ind <= mid)
    {
        update(s, l, mid, ind, ch, pos * 2);
    }
    else
    {
        update(s, mid + 1, r, ind, ch, pos * 2 + 1);
    }

    vector<int> rep1 = src[pos * 2];
    vector<int> rep2 = src[pos * 2 + 1];
    for (int i = 0; i < 26; i++)
    {
        rep[i] = rep1[i] + rep2[i];
    }
    src[pos] = rep;
}

void answer()
{
    string s;
    cin >> s;
    int n = s.size();
    build(s, 0, n - 1, 1);
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (x == 1)
        {
            char z;
            cin >> z;
            y--;
            update(s, 0, n - 1, y, z, 1);
        }
        else
        {
            int z;
            cin >> z;
            y--;
            z--;
            vector<int> rep = get(0, n - 1, y, z, 1);
            cout << getAnswer(rep) << '\n';
        }
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