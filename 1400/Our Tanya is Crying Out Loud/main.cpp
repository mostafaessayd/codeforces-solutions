/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/940/problem/B
rating : 1400
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
	ll n , k , A , B;
	cin >> n >> k >> A >> B;
	if(k == 1) {
		cout << A * (n - 1) << '\n';
		return;
	}
	ll ans = 0;
	while(n > 1) {
		if(n < k) {
			ans += A * (n - 1);
			break;
		}
		if(n % k == 0) {
			ans += min(B , A * (n - n / k));
			n /= k;
		} else {
			ans += A * (n % k);
			n -= n % k;
		}
	}
	cout << ans;
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