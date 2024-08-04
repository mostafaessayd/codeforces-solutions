/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1419/problem/D2
rating : 1500
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void answer()
{
   int n;
   cin >> n;
   vector<int> vec(n);
   for(int& val : vec) {
    cin >> val;
   }

   sort(vec.begin() , vec.end());
   vector<int> res(n);
   int ind = 0;
   for(int i = 1 ; i < n ; i += 2) {
    res[i] = vec[ind++];
   }
   for(int i = 0 ; i < n ; i += 2) {
    res[i] = vec[ind++];
   }

   int k = 0;
   for(int i = 1 ; i < n - 1 ; i++) {
    k += (res[i] < res[i - 1] && res[i] < res[i + 1]);
   }

   cout << k << '\n';
   for(int val : res) {
    cout << val << ' ';
   }
}

int main()
{
    int t = 1;
  //  cin >> t;
    while (t--)
    {
        answer();
    }

    return 0;
}