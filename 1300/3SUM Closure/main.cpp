/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1698/problem/C
 rating : 1300
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	int n;
	cin >> n;
	vector<ll> vec(n);
	map<ll , int> cnt;
	vector<ll> press_array;
	set<ll> dp;
	for(ll& val : vec) {
		cin >> val;
		if(cnt[val] < 3) {
			press_array.push_back(val);
			dp.insert(val);
		}
		cnt[val]++;
	}
    
	if(cnt.size() >= 5) {
		cout << "NO\n";
	} else {
		int n = press_array.size();
		for(int i = 0 ; i < n ; i++) {
			for(int j = 0 ; j < n ; j++) {
				for(int k = 0 ; k < n ; k++) {
					if(i != j && j != k && i != k) {
						if(!dp.count(press_array[i] + press_array[j] + press_array[k])) {
							cout << "NO\n";
							return;
						}
					}
				}
			}
		}

		cout << "YES\n";
	}
}

int main()
{
  ios_base::sync_with_stdio(0);
  int t = 1;
  cin >> t;
  while (t--)
  {
    answer();
  }

  return 0;
}