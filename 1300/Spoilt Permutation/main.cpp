/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/56/problem/B
 rating : 1300
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
	vector<int> vec(n + 1);
	for(int i = 1 ; i <= n ; i++) {
		cin >> vec[i];
	}
	
	int l = -1;
	int r = -1;
	for(int i = 1 ; i <= n ; i++) {
		if(vec[i] != i) {
			l = i;
			r = vec[i];
			break;
		}
	}
	
	if(l == -1 && r == -1) {
		cout << "0 0";
	} else {
		for(int i = l ; i < r ; i++)
		{
			if(vec[i + 1] != vec[i] - 1) {
				cout << "0 0";
				return;
			}
		}
		
		for(int i = r + 1 ; i <= n ; i++)
		{
			if(vec[i] != i) {
				cout << "0 0";
				return;
			}
		}
		
		cout << l << ' ' << r;
	}
}

int main() {
    int t = 1;
    //cin >> t;
    while(t--) {
    	answer();
    }
    return 0;
}