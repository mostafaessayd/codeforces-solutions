/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1029/problem/A
rating : 1300
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>
#include <set>

using namespace std;
using ll = long long;
const int Mod = 1e9 + 7;

void answer() {
	int n , k;
	string s;
	cin >> n >> k >> s;
    
    auto get = [&](string& t , int pos) -> bool {
    	int i = 0;
    	for(; i < n ; i++) {
    		if(pos == t.size()) break;
    		if(s[i] != t[pos]) break;
    		pos++;
    	}
    	if(pos == t.size()) {
    		while(i < n) {
    			t += s[i];
    			i++;
    		}
    		return true;
    	}
    	return false;
    };
    
    string t = s;
    int pos = 0;
    int ans = 0;
    while(ans < k) {
    	ans += get(t , pos);
    	pos++;
    	while(pos < t.size() && t[pos] != s[0]) {
    		pos++;
    	}
    	if(pos == t.size() && ans < k) {
    		t += s;
    	}
    }
    cout << t;
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