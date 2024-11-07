/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/637/problem/B
rating : 1200
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll N = 1e5;


void answer() {
    int n;
    cin >> n;
    map<string , int> last_idx;
    deque<pair<int , string>> vec;
    int r = 0;
    for(int i = 0 ; i < n ; i++) {
        string s;
        cin >> s;
        if(last_idx[s] == 0) {
            vec.push_back({r-- , s});
            last_idx[s] = vec.size();
        } else {
            vec[last_idx[s] - 1].first = 1e9;
            vec.push_back({r-- , s});
            last_idx[s] = vec.size();
        }
    }

    sort(vec.begin() , vec.end());

    for(auto ind : vec) {
        if(ind.first == 1e9) {
            continue;
        }
        cout << ind.second << '\n';
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