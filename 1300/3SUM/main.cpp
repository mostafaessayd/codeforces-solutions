/**
 created by : cidi mohamed mostepha
 link : https://codeforces.com/contest/1692/problem/F
 rating : 1300
 */

#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e5 + 1;

void answer()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	vector<int> dp(10 , 0);
	for(int& val : vec) {
		cin >> val;
		val %= 10;
		dp[val]++;
	}

	vector<int> rep(28 , 0);
	rep[3] = 1;
	rep[13] = 1;
	rep[23] = 1;

    for(int i = 0 ; i < 10 ; i++) {
		for(int j = 0 ; j < 10 ; j++) {
			for(int k = 0 ; k < 10 ; k++) {
				if(rep[i + j + k]) {
					vector<int> temp(10 , 0);
					temp[i]++;
					temp[j]++;
					temp[k]++;
					if(temp[i] <= dp[i] && temp[j] <= dp[j] && temp[k] <= dp[k]) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}

	cout << "NO\n";
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