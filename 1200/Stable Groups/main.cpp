/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1539/problem/C
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
   int n;
   ll k , x;
   cin >> n >> k >> x;
   vector<ll> vec(n);
   for(ll& val : vec) cin >> val;

   sort(vec.begin() , vec.end());
   
   vector<ll> diff;
   
   for(int i = 1 ; i < n ; i++) {
    diff.push_back(vec[i] - vec[i - 1]);
   }
   
   sort(diff.begin() , diff.end());
   
   int ans = 1;
   for(int i = 0 ; i < diff.size() ; i++) {
    if(diff[i] > x) {
        if(diff[i] / x + (diff[i] % x != 0) - 1 <= k) {
           k -= diff[i] / x + (diff[i] % x != 0) - 1;
        } else {
            ans++;
        }
    }
   }
  
   cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
   // cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}