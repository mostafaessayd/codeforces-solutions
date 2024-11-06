/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/27/problem/A
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
   int n;
   cin >> n;
   vector<int> vec(n);
   for(int& val : vec) cin >> val;

   sort(vec.begin() , vec.end());
   
   int l = 1;
   for(int i = 0 ; i < n ; i++ , l++) {
    if(vec[i] != l) {
        cout << l;
        return;
    }
   }

   cout << n + 1;
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