/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/612/problem/A
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int n , p , q;
    string s;
    cin >> n >> p >> q >> s;

    for(int i = 0 ; p * i <= n ; i++) {
        for(int j = 0 ; j * q <= n ; j++) {
            if(p * i + q * j == n) {
                cout << i + j << '\n';
                int idx = 0;
                for(int k = 0 ; k < i ; k++) {
                   int l = 1; 
                   while(l <= p) {
                    l++;
                    cout << s[idx++];
                   }
                   cout << '\n';
                }
                for(int k = 0 ; k < j ; k++) {
                   int l = 1; 
                   while(l <= q) {
                    l++;
                    cout << s[idx++];
                   }
                   cout << '\n';
                }
                return;
            }
        }
    }
    cout << "-1";
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



