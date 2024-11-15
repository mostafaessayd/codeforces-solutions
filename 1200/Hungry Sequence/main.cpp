/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/327/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;
const int MOD = 1e9 + 7;

void answer() {
   int n;
   cin >> n;
   int val = 1e7;
   vector<int> vec;
   while(n--) {
      vec.push_back(val--);
   }

   for(int i = vec.size() - 1 ; i > -1 ; i--) cout << vec[i] << ' ';
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