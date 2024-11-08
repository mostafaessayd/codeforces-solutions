/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/146/problem/B
 rating : 1300
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int a , b;
    cin >> a >> b;
    string t = to_string(b);
    for(int i = a + 1 ; ; i++) {
        int x = i;
        string s = "";
        while(x) {
            if(x % 10 == 7 || x % 10 == 4) {
                char ch = ((x % 10) + '0');
                s = ch + s;
            }
            x /= 10;
        }

        if(s == t) {
            cout << i << '\n';
            return;
        }
    }
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



