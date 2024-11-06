/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1369/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
   int n;
   string s;
   cin >> n >> s;

   bool inc_sorted = true;
   bool dec_sorted = true;
   bool diff = false;
   int first_one = -1;
   int last_zero = -1;
   for(int i = 0 ; i < n - 1 ; i++) {
    if(s[i] == '1') {
        if(first_one == -1) {
            first_one = i;
        }
    } else {
        last_zero = i;
    }
    diff |= (s[i] != s[i + 1]);
    inc_sorted &= (s[i] <= s[i + 1]);
    dec_sorted &= (s[i] >= s[i + 1]);
   } 
   if(s[n - 1] == '1') {
        if(first_one == -1) {
            first_one = n - 1;
        }
    } else {
        last_zero = n - 1;
    }

    if(!diff) {
        cout << s << '\n';
    } else {
        if(inc_sorted) {
            cout << s << '\n';
        } else {
            if(dec_sorted) {
                cout << "0\n";
            } else {
                for(int i = 0 ; i < first_one ; i++) cout << s[i];
                cout << "0";
                for(int i = last_zero + 1 ; i < n ; i++) cout << s[i];
                cout << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    cin >> t;
    while(t--) {
        answer();
    }

    return 0;
}