/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/78/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int n;
    cin >> n;
    string t = "";
    vector<string> src = {
        "" , 
        "G" , 
        "YG" ,
        "OYG" ,
        "ROGI" ,
        "GYBIV" , 
        "RGYBIV"
    };

    for(int i = 0 ; i < n / 7 ; i++) {
        t += "ROYGBIV";
    }
    t += src[n % 7];
    cout << t << '\n';
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