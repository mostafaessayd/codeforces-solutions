/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1185/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
   string s , t;
   cin >> s >> t;
   vector<pair<char , int>> press_s;
   vector<pair<char , int>> press_t;
   for(int i = 0 ; i < s.size() ; ) {
    int l = 0;
    int j = i;
    while(i < s.size() && s[i] == s[j]) {
        j++;
        l++;
    }
    press_s.push_back({s[i] , l});
    i = j;
   }
   for(int i = 0 ; i < t.size() ; ) {
    int l = 0;
    int j = i;
    while(i < t.size() && t[i] == t[j]) {
        j++;
        l++;
    }
    press_t.push_back({t[i] , l});
    i = j;
   }

   if(press_s.size() != press_t.size()) {
    cout << "NO\n";
   } else {
    for(int i = 0 ; i < press_s.size() ; i++) {
        if(press_s[i].second > press_t[i].second || press_s[i].first != press_t[i].first) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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
