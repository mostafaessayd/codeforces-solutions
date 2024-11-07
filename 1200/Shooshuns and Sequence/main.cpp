/**
created by : cidi mohamed mostepha
link : https://codeforces.com/contest/222/problem/A
rating : 1200
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <deque>

using namespace std;
using ll = long long;
int N = 2e5 + 1;

void answer()
{
	int n , k;
	cin >> n >> k;
	vector<int> vec(n);
	for(int& val : vec) cin >> val;
	
	for(int i = k ; i < n ; i++) {
		if(vec[i] != vec[i - 1]) {
			cout << "-1";
			return;
		}
	}
	
	int i = k - 1;
	int s = vec[k - 1];
	while(i >= 0 && vec[i] == s) {
		i--;
		k--;
	}
	cout << k;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t = 1;
  //cin >> t;

  while (t--)
  {
    answer();
  }

  return 0;
}