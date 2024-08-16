/**
created by : cidi mohamed mostepha
link : https://codeforces.com/problemset/problem/451/B
rating : 1300
*/

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const int MOD = 1e9 + 7;

template <class T>
void ReadVector(vector<T> &vec)
{
    for (T &value : vec)
        cin >> value;
}

template <class T>
void IncSort(vector<T> &vec)
{
    sort(vec.begin(), vec.end());
}

template <class T>
void DecSort(vector<T> &vec)
{
    sort(vec.rbegin(), vec.rend());
}

void answer()
{
    int n;
    cin >> n;
    vector<int> vec(n), a(n);

    ReadVector(vec);
    a = vec;
    IncSort(a);

    int i = 0;
    while(vec[i] == a[i] && i < n)
        i++;
    if(i == n)
    {
        cout << "yes\n1 1\n";
        return;
    }

    int j = n - 1;
    while(vec[j] == a[j] && j > i)
        j--;

    vector<int> arr;

    for(int k = 0 ; k < i ; k++)
        arr.push_back(vec[k]);
    for(int k = j ; k >= i ; k--)
        arr.push_back(vec[k]);
    for(int k = j + 1 ; k < n ; k++)
        arr.push_back(vec[k]);

    if(is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes\n";
        cout << i + 1 << ' ' << j + 1 << '\n';
    }
    else
        cout << "no\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
  //  cin >> T;

    while (T--)
    {
        answer();
    }

    return 0;
}