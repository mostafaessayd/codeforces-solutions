/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/1006/problem/C
rating : 1200
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

void answer() {
	int n;
	cin >> n;
	vector<ll> vec(n);
	vector<ll> prefix(n);
	vector<ll> suffix(n);
	ll ans = 0;
	for(int i = 0 ; i < n ; i++) {
		cin >> vec[i];
		ans += vec[i];
		prefix[i] = ans;
	}
	ans = 0;
	for(int i = n - 1 ; i > -1 ; i--) {
		ans += vec[i];
		suffix[i] = ans;
	}
	
	ll res = 0;
	int i = 0;
	int j = n - 1;
	while(i < j) {
		if(prefix[i] == suffix[j]) {
			res = prefix[i];
			i++;
			j--;
		} else {
			if(prefix[i] < suffix[j]) {
				i++;
			} else {
				j--;
			}
		}
	}
	
	cout << res;
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--) {
    	answer();
    }
    return 0;
}