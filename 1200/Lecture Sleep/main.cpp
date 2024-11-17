/**
 * created by : cidi mohamed mostepha
 * link : https://codeforces.com/contest/961/problem/B
 * rating : 1200
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n , k;
   cin >> n >> k;
   vector<int> a(n) , t(n);
   for(int& val : a) cin >> val;
   for(int& val : t) cin >> val;
   vector<int> wakePrefix(n , 0) , wakeSuffix(n , 0) , prefix(n , 0);
   int sum1 = 0;
   int sum2 = 0;
   int sum3 = 0;
   for(int i = 0 ; i < n ; i++) {
      sum1 += a[i];
      if(t[i] == 1) {
         sum2 += a[i];
      }
      if(t[n - i - 1] == 1) {
         sum3 += a[n - i - 1];
      }
      prefix[i] = sum1;
      wakePrefix[i] = sum2;
      wakeSuffix[n - i - 1] = sum3;
   }
   if(k == n) {
      cout << prefix.back();
      return;
   }
   int ans = wakePrefix[n - k - 1] + prefix[n - 1] - (n - k == 0 ? 0 : prefix[n - k - 1]);
   for(int i = 1 ; i < n - k ; i++) {
      ans = max(ans , wakePrefix[i - 1] + wakeSuffix[i + k] + prefix[i + k - 1] - prefix[i - 1]);
   }
   ans = max(ans , prefix[k - 1] + wakeSuffix[k]);
   cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    //cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}