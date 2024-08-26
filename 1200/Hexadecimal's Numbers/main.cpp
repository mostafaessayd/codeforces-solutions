/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/9/problem/C
rating : 1200
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;
ll n;

int get(ll x) {
	if(x > n) {
		return 0;
	}
	
	return 1 + get(x * 10) + get(x * 10 + 1);
}

void answer() {
	cin >> n;
	cout << get(1);
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--) {
    	answer();
    }
    return 0;
}