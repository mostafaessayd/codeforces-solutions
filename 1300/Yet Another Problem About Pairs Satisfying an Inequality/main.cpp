#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<ll> vec(n + 1);
		vector<ll> prefix(n + 1 , 0);
		for(int i = 1 ; i <= n ; i++) {
			cin >> vec[i];
			prefix[i] = prefix[i - 1] + (i > vec[i]);
		}
		ll ans = 0;
		for(int i = 1 ; i <= n ; i++) {
			if(i > vec[i] && vec[i] > 1) {
				ans += prefix[vec[i] - 1];
			}
		}
		cout << ans << '\n';
	}
	
    return 0;
}