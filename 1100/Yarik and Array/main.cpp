/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1899/problem/C
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

   ll ans = INT_MIN;
   for(int i = 0 ; i < n ; ) {
    vector<ll> temp;
    temp.push_back(vec[i]);
    int j = i + 1;
    while(j < n) {
      if((vec[j] + vec[j - 1]) % 2 == 0) {
        break;
      }
      temp.push_back(vec[j]);
      j++;
    }
    i = j;
    ll cur = INT_MIN;
    ll sum = 0;
    for(int k = 0 ; k < temp.size() ; k++) {
      sum += temp[k];
      cur = max(1ll * cur , 1ll * sum);
      sum = max(0LL , 1ll * sum);
    } 
    ans = max(1ll * ans , 1ll * cur);
    temp.clear();
   }
    
   cout << ans << '\n';
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