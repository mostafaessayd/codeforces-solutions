/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1355/problem/B
rating : 1200
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
	int n;
	cin >> n;
	deque<int> vec(n);
	for(int& val : vec) cin >> val;
	sort(vec.begin() , vec.end());
	int ans = 0;
	int j = 0;
    for(int i = 0 ; i < n ; i++) {
    	if(i - j + 1 >= vec[i]) {
    		ans++;
    		j = i + 1;
    	}
    }
	cout << ans << '\n';
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