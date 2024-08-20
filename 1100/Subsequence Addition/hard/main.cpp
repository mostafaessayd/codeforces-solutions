/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1807/problem/G2
rating : 1100
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 5e4;

void answer()
{
   int n;
   cin >> n;
   vector<ll> vec(n);
   for(ll& val : vec) {
    cin >> val;
   }

   sort(vec.begin() , vec.end());
   if(vec[0] > 1) {
    cout << "NO\n";
    return;
   }
   ll sum = 0;
   vector<ll> prefix(n);
   for(int i = 0 ; i < n ; i++) {
    sum += vec[i];
    prefix[i] = sum;
    if(i > 0) {
      if(vec[i] > prefix[i - 1]) {
        cout << "NO\n";
        return;
      }
    }
   }

   cout << "YES\n";
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}